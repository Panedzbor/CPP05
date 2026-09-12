#pragma once
#ifndef testkit_HPP
#define testkit_HPP

# include <iostream>
# include <string>

void        showOptions();
char        getOption(const std::string& allOptions);
std::string collectString();
int         collectNumber();
std::string giveName(std::string who);



#endif