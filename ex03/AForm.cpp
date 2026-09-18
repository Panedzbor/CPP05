#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(std::string name, int gS, int gE)
: name(name), gradeToSign(gS), gradeToExec(gE), isSigned(false)
{
    if (gradeToSign < minGrade)
        throw Bureaucrat::GradeTooHighException();
    if (gradeToSign > maxGrade)
        throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm & orig)
: name(orig.name), gradeToSign(orig.gradeToSign), gradeToExec(orig.gradeToExec), isSigned(orig.isSigned)
{}

AForm & AForm::operator=(const AForm & orig)
{
    name = orig.name;
    isSigned = orig.isSigned;
    return *this;
}

AForm::~AForm()
{}

std::string AForm::get(std::string name) const
{
    (void)name;
    return this->name;
}

bool AForm::get(bool isSigned) const
{
    (void)isSigned;
    return this->isSigned;
}

int AForm::get(int gradeTo) const
{
    int result = (gradeTo == gToSign) ? this->gradeToSign : this->gradeToExec;
    return result;
}

void AForm::beSigned(const Bureaucrat & mrB)
{
    int bGrade = mrB.getGrade();
    if (bGrade > gradeToSign)
        throw Bureaucrat::GradeTooLowException();

    isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!get(true))
        throw FormNotSignedException();
    if (executor.getGrade() > get(gToExec))
        throw Bureaucrat::GradeTooLowException();
    executeAction();
}

const char * AForm::FormNotSignedException::what() const throw ()
{
    return "Form not signed\n";
}

std::ostream & operator<<(std::ostream & out, const AForm & f)
{
    out << f.get(std::string("name")) << ", sign grade " << f.get(1) << ", exec grade " << f.get(2) << " status: " << f.get(true);
    return out;
}

std::string toString(const AForm & F)
{
    std::ostringstream out;
    out << F;
    return out.str();
}
