#pragma once
#include <vector>
#include "Expense.h"
#include <string>

class ExpenseManager
{
private:
    std::vector<Expense> expenses;

public:
    void addExpense(const Expense& expense);
    void displayExpenses() const;
    double getTotal() const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    void deleteExpense(int index);
    void editExpense(int index);
};