#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

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
        const int gradeToSign;
        const int gradeToExec;
        bool isSigned;

};

std::ostream & operator<<(std::ostream &, const Form &);
std::string toString(const Form &);

enum GradeToGet
{
    gToSign = 1,
    gToExec = 2
};