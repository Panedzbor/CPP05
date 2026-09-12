#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade < minGrade)
        throw GradeTooHighException();
    if (grade > maxGrade)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat & orig) : name(orig.name), grade(orig.grade) {}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & orig)
{
    if (this != &orig)
        grade = orig.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade - 1 < minGrade)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade + 1 > maxGrade)
        throw GradeTooLowException();
    grade++;
}

void Bureaucrat::signForm(Form & F) const
{
    try
    {
        F.beSigned(*this);
        std::cout << name << " signed " << F.get("name") << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << name << " couldn't sign " << F.get("name") << " because " << e.what() << '\n';
    }
}

const char * Bureaucrat::GradeTooHighException::what() const throw ()
{
    return "Grade too high\n";
}

const char * Bureaucrat::GradeTooLowException::what() const throw ()
{
    return "Grade too low\n";
}

std::ostream & operator<<(std::ostream & out, const Bureaucrat & b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}

