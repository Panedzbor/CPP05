#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm(std::string);
        ShrubberyCreationForm(const ShrubberyCreationForm &);
        ShrubberyCreationForm & operator=(const ShrubberyCreationForm &);
        ~ShrubberyCreationForm();

        void createFile() const;
        void executeAction() const;

    private:
        std::string target;
};