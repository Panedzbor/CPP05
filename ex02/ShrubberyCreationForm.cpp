#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & orig)
: AForm(orig), target(orig.target)
{}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & orig)
{
    if (this != &orig)
    {
        target = orig.target;
        AForm::operator=(orig);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::createFile() const
{
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file)
        throw std::runtime_error("Could not create shrubbery file");

    file << "       *\n";
    file << "      ***\n";
    file << "     *****\n";
    file << "      |||\n";
    file << "      |||\n";
}

void ShrubberyCreationForm::executeAction() const
{
    createFile();
}
