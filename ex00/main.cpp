#include "Bureaucrat.hpp"

int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        std::cout << "Run the program in format: ./exec_file name grade\n";
        return 1;
    }

    char * name = argv[1];
    int grade = atoi(argv[2]);
    
    try
    {
        Bureaucrat b(name, grade);
        std::cout << b;
    }
    catch (const std::exception & e)
    {
        std::cout << e.what();
    }

    return 0;
}