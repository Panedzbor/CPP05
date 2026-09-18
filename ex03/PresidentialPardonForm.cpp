#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5), target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & orig)
: AForm(orig), target(orig.target)
{}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & orig)
{
    if (this != &orig)
    {
        target = orig.target;
        AForm::operator=(orig);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::pardon() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}

void PresidentialPardonForm::executeAction() const
{
    pardon(); 
}