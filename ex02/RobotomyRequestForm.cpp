#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & orig)
: AForm(orig), target(orig.target)
{}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & orig)
{
    if (this != &orig)
    {
        target = orig.target;
        AForm::operator=(orig);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::robotomize() const
{
    static int attempts = 0;

    std::cout << "~^_^-!@#$% ";
    if (attempts++ % 2 == 0)
        std::cout << target << "has been robotomized successfully!\n";
    else
        std::cout << "robotomy failed -_-\n";
}

void RobotomyRequestForm::executeAction() const
{
    robotomize(); 
}