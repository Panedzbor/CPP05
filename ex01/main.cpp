#include "Bureaucrat.hpp"
#include "testkit.hpp"
#include <iomanip>

void startProgram()
{
    std::cout << "Welcome to Bureaucrats siginig Forms simulator!\n";
    std::cout << "\n";
}

void showMenu()
{
    std::cout << "Choose an option:\n";
    std::cout << "1. Create a Bureaucrat\n";
    std::cout << "2. Create a Form\n";
    std::cout << "3. Sign a Form\n";
    std::cout << "4. Exit\n";
    std::cout << "\n";
}

char acceptOption()
{
    return getOption("1234");
}

int setGrade(std::string name)
{
    std::cout << "Set " << name << "'s grade: ";
    int grade = collectNumber();
    return grade; 
}

void createBureaucrat(Bureaucrat ** burs)
{
    std::string name = giveName("Bureaucrat");
    int grade = setGrade(name);
    Bureaucrat * newB = new Bureaucrat(name, grade);
    int i;
    for (i = 0; i < 10; i++)
    {
        if (!burs[i])
        {
            burs[i] = newB;
            std::cout << "Bureaucrat " << name << "created\n";
            break;
        }
    }
    if (i == 10)
        std::cout << "All slots full\n";
    std::cout << "\n";
}

void createForm(Form ** forms)
{
    std::string name = giveName("Form");
    int grade = setGrade(name);
    Form * newF = new Form(name, grade, grade);
    int i;
    for (i = 0; i < 10; i++)
    {
        if (!forms[i])
        {
            forms[i] = newF;
            std::cout << "Form " << name << "created\n";
            break;
        }
    }
    if (i == 10)
        std::cout << "All slots full\n";
    std::cout << "\n";
}

void signForm(Bureaucrat ** burs, Form ** forms)
{
    std::cout << "Choose which from to sign: ";
    
    int formIndx;
    while ((formIndx = collectNumber()) < 1 || formIndx > 10)
        std::cout << "\nWrong option. Try again: ";
    std::cout << "\n";
    
    std::cout << "Choose a Bureaucrat to sign the form: ";
    int burIndx;
    while ((burIndx = collectNumber()) < 1 || burIndx > 10)
        std::cout << "\nWrong option. Try again: ";
    std::cout << "\n";

    burs[burIndx]->signForm(*forms[formIndx]);
}

bool executeCommand(char chOption, Bureaucrat ** burs, Form ** forms)
{
    int option = chOption - '0';
    switch (option)
    {
        case 1:
            createBureaucrat(burs);
            break;
        case 2:
            createForm(forms);
            break;
        case 3:
            signForm(burs, forms);
            break;
        case 4:
            return false;
    }
    return true;
}

void showResult(Bureaucrat ** burs, Form ** forms)
{
    for (int i = 0; i < 10; i++)
    {
        if (burs[i])
            std::cout << std::setw(15) << burs[i];
        else
            std::cout << std::setw(15) << "";
        std::cout << " | ";
        if (forms[i])
            std::cout << std::setw(30) << forms[i];
        else 
            std::cout << std::setw(30) << "";
        std::cout << "\n";
    }
    std::cout << "\n";
}

void finishProgram(Bureaucrat ** burs, Form ** forms)
{
    std::cout << "Exiting\n";
    for (int i = 0; i < 10; i++)
    {
        delete burs[i];
        delete forms[i];
    }
}

int main()
{
    Bureaucrat * burs[10] = {0};
    Form * forms[10] = {0};
    char option = 0;
    
    startProgram();
    while (option != 'e')
    {
        showMenu();
        option = acceptOption();
        executeCommand(option, burs, forms);
        showResult(burs, forms);
    }
    finishProgram(burs, forms);

    return 0;
}