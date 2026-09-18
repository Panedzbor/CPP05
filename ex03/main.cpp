#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "testkit.hpp"
#include <iomanip>

void startProgram()
{
    std::cout << "Welcome to Bureaucrats signing Forms simulator!\n";
    std::cout << "\n";
}

void showMenu()
{
    std::cout << "Choose an option:\n";
    std::cout << "1. Create a Bureaucrat\n";
    std::cout << "2. Edit a Bureaucrat\n";
    std::cout << "3. Create a ShrubberyCreationForm\n";
    std::cout << "4. Create a RobotomyRequestForm\n";
    std::cout << "5. Create a PresidentialPardonForm\n";
    std::cout << "6. Make a Form by an Intern\n";
    std::cout << "7. Sign a Form\n";
    std::cout << "8. Execute a Form\n";
    std::cout << "9. Exit\n";
    std::cout << "\n";
}

char acceptOption()
{
    return getOption("123456789");
}

int setGrade(std::string name)
{
    std::cout << "Set " << name << "'s grade: ";
    int grade = collectNumber();
    std::cout << "\n";
    return grade;
}

bool createBureaucrat(Bureaucrat ** burs)
{
    std::string name = giveName("Bureaucrat");
    int grade = setGrade(name);
    try
    {
        Bureaucrat * newB = new Bureaucrat(name, grade);
        int i;
        for (i = 0; i < 10; i++)
        {
            if (!burs[i])
            {
                burs[i] = newB;
                std::cout << "Bureaucrat " << name << " created\n";
                break;
            }
        }
        if (i == 10)
        {
            delete newB;
            std::cout << "All slots full\n";
        }
        std::cout << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
        return false;
    }

    return true;
}

bool editBureaucrat(Bureaucrat ** burs)
{
    std::cout << "Choose which Bureaucrat to edit: ";

    int burIndx;
    while ((burIndx = collectNumber()) < 1 || burIndx > 10)
        std::cout << "\nWrong option. Try again: ";
    std::cout << "\n";

    std::cout << *burs[burIndx-1] << "\n";
    std::cout << "Choose 1 to increment bureaucarat's grade; choose 2 to decrement bureaucrat's grade\n";
    char option = getOption("12");
    try
    {
        if (option == '1')
            burs[burIndx-1]->incrementGrade();
        else
            burs[burIndx-1]->decrementGrade();
    }
    catch(...)
    {
        return false;
    }

    return true;
}

bool createSCForm(AForm ** forms)
{
    try
    {
        std::cout << "Enter the target: ";
        std::string target = collectString();
        std::cout << "\n";

        ShrubberyCreationForm * newF = new ShrubberyCreationForm(target);
        int i;
        for (i = 0; i < 10; i++)
        {
            if (!forms[i])
            {
                forms[i] = newF;
                std::cout << "ShrubberyCreationForm created\n";
                break;
            }
        }
        if (i == 10)
        {
            delete newF;
            std::cout << "All slots full\n";
        }
        std::cout << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
        return false;
    }

    return true;
}

bool createRRForm(AForm ** forms)
{
    try
    {
        std::cout << "Enter the target: ";
        std::string target = collectString();
        std::cout << "\n";

        RobotomyRequestForm * newF = new RobotomyRequestForm(target);
        int i;
        for (i = 0; i < 10; i++)
        {
            if (!forms[i])
            {
                forms[i] = newF;
                std::cout << "RobotomyRequestForm created\n";
                break;
            }
        }
        if (i == 10)
        {
            delete newF;
            std::cout << "All slots full\n";
        }
        std::cout << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
        return false;
    }

    return true;
}

bool createPPForm(AForm ** forms)
{
    try
    {
        std::cout << "Enter the target: ";
        std::string target = collectString();
        std::cout << "\n";

        PresidentialPardonForm * newF = new PresidentialPardonForm(target);
        int i;
        for (i = 0; i < 10; i++)
        {
            if (!forms[i])
            {
                forms[i] = newF;
                std::cout << "PresidentialPardonForm created\n";
                break;
            }
        }
        if (i == 10)
        {
            delete newF;
            std::cout << "All slots full\n";
        }
        std::cout << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
        return false;
    }

    return true;
}

bool makeForm(AForm ** forms)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (!forms[i])
            break;
    }
    if (i == 10)
        std::cout << "All slots full\n";

    Intern I;

    std::cout << "Choose a From to create:\n";
    std::cout << "1. Shrubbery Creation\n";
    std::cout << "2. Robotomy Request\n";
    std::cout << "3. Presidential Pardon\n";
    std::cout << "4. Other\n";
    std::cout << "\n";
    char option = getOption("1234");


    std::string target;
    std::string name;
    try
    {

        switch (option - '0')
        {
            case 1:
                std::cout << "Enter the target: ";
                target = collectString();
                std::cout << "\n";
                forms[i] = I.makeForm("shrubbery creation", target);
                break;
            case 2:
                std::cout << "Enter the target: ";
                target = collectString();
                std::cout << "\n";
                forms[i] = I.makeForm("robotomy request", target);
                break;
            case 3:
                std::cout << "Enter the target: ";
                target = collectString();
                std::cout << "\n";
                forms[i] = I.makeForm("presidential pardon", target);
                break;
            case 4:
                std::cout << "Enter the form name: ";
                name = collectString();
                std::cout << "Enter the target: ";
                target = collectString();
                std::cout << "\n";
                forms[i] = I.makeForm(name, target);
                break;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Intern couldn't create " << name << " because " << e.what() << '\n';
    }

    return true;
}

bool signForm(Bureaucrat ** burs, AForm ** forms)
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

    try
    {
        burs[burIndx-1]->signForm(*forms[formIndx-1]);
    }
    catch(...)
    {
        return false;
    }

    return true;
}

bool executeForm(Bureaucrat ** burs, AForm ** forms)
{
    std::cout << "Choose which from to execute: ";

    int formIndx;
    while ((formIndx = collectNumber()) < 1 || formIndx > 10)
        std::cout << "\nWrong option. Try again: ";
    std::cout << "\n";

    std::cout << "Choose a Bureaucrat to execute the form: ";
    int burIndx;
    while ((burIndx = collectNumber()) < 1 || burIndx > 10)
        std::cout << "\nWrong option. Try again: ";
    std::cout << "\n";

    try
    {
        burs[burIndx-1]->executeForm(*forms[formIndx-1]);
    }
    catch(...)
    {
        return false;
    }

    return true;
}

bool executeCommand(char chOption, Bureaucrat ** burs, AForm ** forms)
{
    int option = chOption - '0';
    switch (option)
    {
        case 1:
            return createBureaucrat(burs);
        case 2:
            return editBureaucrat(burs);
        case 3:
            return createSCForm(forms);
        case 4:
            return createRRForm(forms);
        case 5:
            return createPPForm(forms);
        case 6:
            return makeForm(forms);
        case 7:
            return signForm(burs, forms);
        case 8:
            return executeForm(burs, forms);
        case 9:
            return false;
    }
    return true;
}

void showResult(Bureaucrat ** burs, AForm ** forms)
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << std::setw(2) << i + 1;
        if (burs[i])
            std::cout << std::setw(40) << toString(*burs[i]);
        else
            std::cout << std::setw(40) << "";
        std::cout << "   ";
        if (forms[i])
            std::cout << std::setw(40) << toString(*forms[i]);
        else
            std::cout << std::setw(40) << "";
        std::cout << "\n";
    }
    std::cout << "\n";
}

void finishProgram(Bureaucrat ** burs, AForm ** forms)
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
    AForm * forms[10] = {0};
    char option = 0;

    startProgram();
    while (option != '9')
    {
        showMenu();
        option = acceptOption();
        if (executeCommand(option, burs, forms))
            showResult(burs, forms);
    }
    finishProgram(burs, forms);

    return 0;
}
