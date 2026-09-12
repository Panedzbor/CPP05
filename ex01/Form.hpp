#pragma once

#include <string>
#include <cstdbool>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
    
    public:
        Form(std::string name, int gradeToSign, int gradeToExec);
        Form(const Form &);
        Form & operator=(const Form &);
        ~Form();

        std::string get(std::string name) const;
        bool get(bool isSigned) const;
        int get(int gradeTo) const;

        void beSigned(const Bureaucrat &);

    private:
        std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExec;

};

std::ostream & operator<<(std::ostream &, const Form &);

enum GradeToGet
{
    gToSign = 1,
    gToExec = 2
};