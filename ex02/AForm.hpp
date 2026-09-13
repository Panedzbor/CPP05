#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
    
    public:
        AForm(std::string name, int gradeToSign, int gradeToExec);
        AForm(const AForm &);
        AForm & operator=(const AForm &);
        ~AForm();

        std::string get(std::string name) const;
        bool get(bool isSigned) const;
        int get(int gradeTo) const;

        void beSigned(const Bureaucrat &);
        void execute(Bureaucrat const & executor) const;

        class FormNotSignedException : public std::exception {
            public:
                const char * what() const throw();
        };

    protected:
        virtual void executeAction() const = 0;

    private:
        std::string name;
        const int gradeToSign;
        const int gradeToExec;
        bool isSigned;

};

std::ostream & operator<<(std::ostream &, const AForm &);
std::string toString(const AForm &);

enum GradeToGet
{
    gToSign = 1,
    gToExec = 2
};