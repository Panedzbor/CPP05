#pragma once

#include <string>
#include "AForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern &);
        Intern & operator=(const Intern &);
        ~Intern();

        AForm * makeForm(std::string, std::string);

        class FormDoesNotExist : public std::exception {
            public:
                const char * what() const throw();
        };
};
