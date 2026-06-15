#include "ExpenseManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

void ExpenseManager::addExpense(const Expense& expense)
{
    expenses.push_back(expense);
}

void ExpenseManager::displayExpenses() const
{
    for (size_t i = 0; i < expenses.size(); i++)
    {
        const auto& e = expenses[i];

        std::cout << i << ". "
                  << e.description << " - $"
                  << e.amount << " - "
                  << e.category << std::endl;
    }
}

double ExpenseManager::getTotal() const
{
    double total = 0;

    for (const auto& e : expenses)
    {
        total += e.amount;
    }

    return total;
}

void ExpenseManager::deleteExpense(int index)
{
    if (index < 0 || index >= expenses.size())
    {
        std::cout << "Invalid index.\n";
        return;
    }

    expenses.erase(expenses.begin() + index);
    std::cout << "Expense deleted.\n";
}

void ExpenseManager::editExpense(int index)
{
    if (index < 0 || index >= expenses.size())
    {
        std::cout << "Invalid index.\n";
        return;
    }

    std::string desc, category;
    double amount;

    std::cout << "New Description: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, desc);

    std::cout << "New Amount: ";
    std::cin >> amount;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "New Category: ";
    std::getline(std::cin, category);

    expenses[index] = Expense(desc, amount, category);

    std::cout << "Expense updated.\n";
}

void ExpenseManager::saveToFile(const std::string& filename) const
{
    std::ofstream outFile(filename);

    if (!outFile.is_open())
    {
        std::cout << "Error: Could not open file for saving.\n";
        return;
    }

    for (const auto& e : expenses)
    {
        outFile << e.description << "|"
                << e.amount << "|"
                << e.category << "\n";
    }
}

void ExpenseManager::loadFromFile(const std::string& filename)
{
    std::ifstream inFile(filename);

    if (!inFile.is_open())
    {
        return;
    }

    expenses.clear();

    std::string line;

    while (std::getline(inFile, line))
    {
        std::stringstream ss(line);

        std::string description;
        std::string amountStr;
        std::string category;

        std::getline(ss, description, '|');
        std::getline(ss, amountStr, '|');
        std::getline(ss, category, '|');

        Expense e(description, std::stod(amountStr), category);
        expenses.push_back(e);
    }
}