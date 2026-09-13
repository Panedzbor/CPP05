#include "testkit.hpp"

std::string collectString()
{
    std::string str;
    
    if (!std::getline(std::cin, str) || str.empty())
    {
        std::cin.ignore(1000, '\n');
        return "";
    }
    return str;
}

int collectNumber()
{
    std::string str = collectString();
    int num = atoi(str.c_str());
    return num;
}

std::string giveName(std::string who)
{
    std::string name;
    
    std::cout << "Enter " << who << "'s name: ";
    while ((name = collectString()) == "")
        std::cout << "Give a valid name: ";
    std::cout << '\n';
    return name;
}

char getOption(const std::string& allOptions)
{
    char input = 0;

    while (true)
    {
        std::cout << "Enter your choice: ";
        std::cin >> input;
        std::cin.ignore(1000, '\n');

        if (allOptions.find(input) != std::string::npos)
            break;
    }
    std::cout << '\n';
    return input;
}