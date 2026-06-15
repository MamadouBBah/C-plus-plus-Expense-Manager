#pragma once

#include <string>

class Expense
{
public:
    std::string description;
    double amount;
    std::string category;

    Expense();
    Expense(std::string desc, double amt, std::string cat);
};