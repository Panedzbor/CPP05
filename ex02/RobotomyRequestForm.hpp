#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm(std::string);
        RobotomyRequestForm(const RobotomyRequestForm &);
        RobotomyRequestForm & operator=(const RobotomyRequestForm &);
        ~RobotomyRequestForm();

        void robotomize() const;
        void executeAction() const;

    private:
        std::string target;
};