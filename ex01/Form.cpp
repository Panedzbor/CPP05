#include "Form.hpp"

Form::Form(std::string name, int gS, int gE) 
: name(name), gradeToSign(gS), gradeToExec(gE), isSigned(false)
{}
    
Form::Form(const Form & orig)
: name(orig.name), gradeToSign(orig.gradeToSign), gradeToExec(orig.gradeToExec), isSigned(orig.isSigned)
{}

Form & Form::operator=(const Form & orig)
{
    name = orig.name;
    isSigned = orig.isSigned;
}

Form::~Form() 
{}

std::string Form::get(std::string name) const
{
    return this->name;
}
    
bool Form::get(bool isSigned) const
{
    return this->isSigned;
}

int Form::get(int gradeTo) const
{
    int result = (gradeTo == gToSign) ? this->gradeToSign : this->gradeToExec;
    return result;
}

void Form::beSigned(const Bureaucrat & mrB)
{
    int bGrade = mrB.getGrade();
    if (bGrade > gradeToSign)
        throw Bureaucrat::GradeTooLowException();
    
    isSigned = true;
}

std::ostream & operator<<(std::ostream & out, const Form & f)
{
    out << f.get("name") << ", Form grade " << f.get(1) << " status " << f.get(true);
    return out;
}