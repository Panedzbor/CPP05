#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <exception>
#include <sstream>


#define minGrade 1
#define maxGrade 150

class AForm;

class Bureaucrat {
    public:
        Bureaucrat(std::string, int);
        Bureaucrat(const Bureaucrat &);
        Bureaucrat & operator=(const Bureaucrat &);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        void signForm(AForm &) const;

        class GradeTooHighException : public std::exception {
            public:
                const char * what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char * what() const throw();
        };
    
    private:
        const std::string name;
        int grade;
};

std::ostream & operator<<(std::ostream & out, const Bureaucrat & b);
std::string toString(const Bureaucrat &);
