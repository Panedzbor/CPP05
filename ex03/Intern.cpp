#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern ()
{}

Intern::Intern(const Intern & orig)
{
    (void)orig;
}

Intern & Intern::operator=(const Intern & orig)
{
    if (this == &orig)
        return *this;
    return *this;
}

Intern::~Intern()
{}

char checkFormName(std::string formName)
{
    std::string array[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (int i = 0; i < 3; i++)
    {
        if (array[i] == formName)
            return array[i].c_str()[0];
    }
    return 0;
}

AForm * Intern::makeForm(std::string formName, std::string target)
{
    switch (checkFormName(formName))
    {
        case 's':
            std::cout << "Intern creates " << formName << "\n\n";
            return new ShrubberyCreationForm(target);
        case 'r':
            std::cout << "Intern creates " << formName << "\n\n";
            return new RobotomyRequestForm(target);
        case 'p':
            std::cout << "Intern creates " << formName << "\n\n";
            return new PresidentialPardonForm(target);
    }

    throw FormDoesNotExist();
}

const char * Intern::FormDoesNotExist::what() const throw ()
{
    return "Form does not exist";
}
