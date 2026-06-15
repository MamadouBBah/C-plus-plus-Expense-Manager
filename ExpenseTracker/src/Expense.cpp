#include "Expense.h"

Expense::Expense()
{
    description = "";
    amount = 0.0;
    category = "";
}

Expense::Expense(std::string desc, double amt, std::string cat)
{
    description = desc;
    amount = amt;
    category = cat;
}