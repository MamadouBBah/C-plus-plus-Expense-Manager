#include <iostream>
#include "ExpenseManager.h"
#include "Expense.h"
#include <limits>

int main()
{
    ExpenseManager manager;
    manager.loadFromFile("../data/expenses.txt");

    int choice;
    bool running = true;

    while (running)
    {
        std::cout << "\n=== Expense Tracker ===\n";
        std::cout << "1. Add Expense\n";
        std::cout << "2. View Expenses\n";
        std::cout << "3. Total Spending\n";
        std::cout << "4. Delete Expense\n";
        std::cout << "5. Edit Expense\n";
        std::cout << "6. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::string desc, category;
            double amount;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Description: ";
            std::getline(std::cin, desc);

            std::cout << "Amount: ";
            std::cin >> amount;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Category: ";
            std::getline(std::cin, category);

            Expense e(desc, amount, category);
            manager.addExpense(e);
        }
        else if (choice == 2)
        {
            manager.displayExpenses();
        }
        else if (choice == 3)
        {
            std::cout << "Total: $" << manager.getTotal() << std::endl;
        }

        else if (choice == 4)
        {
            int index;
            std::cout << "Enter index to delete: ";
            std::cin >> index;

            manager.deleteExpense(index);
        }
         else if (choice == 5)
        {
            int index;
            std::cout << "Enter index to edit: ";
            std::cin >> index;

            manager.editExpense(index);
        }
        else if (choice == 6)
        {
            char saveChoice;

            std::cout << "Do you want to save before exiting? (Y/N): ";
            std::cin >> saveChoice;

            if (saveChoice == 'Y' || saveChoice == 'y')
            {
                manager.saveToFile("../data/expenses.txt");
                std::cout << "Expenses saved.\n";
            }

            running = false;
        }
    }

    return 0;
}