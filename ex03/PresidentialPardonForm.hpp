#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm(std::string);
        PresidentialPardonForm(const PresidentialPardonForm &);
        PresidentialPardonForm & operator=(const PresidentialPardonForm &);
        ~PresidentialPardonForm();

        void pardon() const;
        void executeAction() const;

    private:
        std::string target;
};