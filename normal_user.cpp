#include "normal_user.h"
#include "bill.h"
#include "entertainment.h"
#include "medical.h"
#include "education.h"
#include "groceries.h"
#include "emergency.h"
#include <iostream>
#include <algorithm>

using namespace std;

NormalUser::NormalUser(const string& username, const string& password, const string& email)
    : User(username, password, email) {}

NormalUser::~NormalUser() {
    for (Expense* expense : expenses) {
        delete expense;
    }
}

void NormalUser::addExpense(Expense* expense) {
    expenses.push_back(expense);
}

void NormalUser::deleteExpense(int index) {
    if (index >= 0 && index < expenses.size()) {
        delete expenses[index];
        expenses.erase(expenses.begin() + index);
        cout << "Expense deleted successfully.\n";
    } else {
        cout << "Invalid expense index.\n";
    }
}

void NormalUser::displayHighestExpense() const {
    if (expenses.empty()) {
        cout << "No expenses found.\n";
        return;
    }

    auto maxExpense = max_element(expenses.begin(), expenses.end(), [](const Expense* a, const Expense* b) {
        return a->getPrice() < b->getPrice();
    });

    cout << "Highest Expense:\n";
    (*maxExpense)->display();
}

void NormalUser::displayLowestExpense() const {
    if (expenses.empty()) {
        cout << "No expenses found.\n";
        return;
    }

    auto minExpense = min_element(expenses.begin(), expenses.end(), [](const Expense* a, const Expense* b) {
        return a->getPrice() < b->getPrice();
    });

    cout << "Lowest Expense:\n";
    (*minExpense)->display();
}

void NormalUser::displayExpensesOnDate(const string& date) const {
    cout << "Expenses on " << date << ":\n";
    bool found = false;
    for (Expense* expense : expenses) {
        if (expense->getDate() == date) {
            expense->display();
            found = true;
        }
    }
    if (!found) {
        cout << "No expenses found on " << date << ".\n";
    }
}

void NormalUser::displayExpensesByCategory(const string& category) const {
    cout << "Expenses in the category " << category << ":\n";
    bool found = false;
    for (Expense* expense : expenses) {
        // Call getCategory() function on each expense
        if (expense->getCategory() == category) {
            expense->display();
            found = true;
        }
    }
    if (!found) {
        cout << "No expenses found in the category " << category << ".\n";
    }
}


void NormalUser::displayTotalExpense() const {
    int totalExpense = 0;
    for (Expense* expense : expenses) {
        totalExpense += expense->getPrice();
    }
    cout << "Total Expense: " << totalExpense << "\n";
}

void NormalUser::displayExpensesWithinDateInterval(const string& startDate, const string& endDate) const {
    cout << "Expenses between " << startDate << " and " << endDate << ":\n";
    bool found = false;
    for (Expense* expense : expenses) {
        if (expense->getDate() >= startDate && expense->getDate() <= endDate) {
            expense->display();
            found = true;
        }
    }
    if (!found) {
        cout << "No expenses found between " << startDate << " and " << endDate << ".\n";
    }
}

void NormalUser::displayMenu() const {
    cout << "----- Normal User Menu -----\n";
    cout << "1. Add Expense\n";
    cout << "2. Delete Expense\n";
    cout << "3. Display Highest Expense\n";
    cout << "4. Display Lowest Expense\n";
    cout << "5. Display Expenses on a Given Date\n";
    cout << "6. Display Expenses by Category\n";
    cout << "7. Display Total Expense\n";
    cout << "8. Display Expenses Within a Date Interval\n";
    cout << "9. Exit\n";
    cout << "-----------------------------\n";
    cout << "Enter your choice: ";
}

void NormalUser::processUserChoice(int choice) {
    switch (choice) {
    case 1: {
    string category, date, name, amount;
    int price;
    cout << "Enter expense category: (bill, medical, education, emergency, entertainment, groceries) ";
    cin >> category;
    cout << "Enter expense date:(DD-MM-YYYY) ";
    cin >> date;
    cout << "Enter expense name: ";
    cin >> name;
    cout << "Enter expense amount: ";
    cin >> amount;
    cout << "Enter expense price: ";
    cin >> price;

    Expense* expense = nullptr;

    if (category == "bill")
        expense = new Bill(date, name, price, amount);
    else if (category == "entertainment")
        expense = new Entertainment(date, name, price, amount);
    else if (category == "medical")
        expense = new Medical(date, name, price, amount);
    else if (category == "education")
        expense = new Education(date, name, price, amount);
    else if (category == "groceries")
        expense = new Groceries(date, name, price, amount);
    else if (category == "emergency")
        expense = new Emergency(date, name, price, amount);
    else {
        cout << "Invalid expense category.\n";
        break;
    }

    addExpense(expense);
    cout << "Expense added successfully.\n";
    break;
}

        case 2: {
            int index;
            cout << "Enter the index of the expense to delete: ";
            cin >> index;
            deleteExpense(index);
            break;
        }
        case 3:
            displayHighestExpense();
            break;
        case 4:
            displayLowestExpense();
            break;
        case 5: {
            string date;
            cout << "Enter the date (DD/MM/YYYY): ";
            cin >> date;
            displayExpensesOnDate(date);
            break;
        }
        case 6: {
            string category;
            cout << "Enter the category:(bill, medical, education, emergency, entertainment, groceries) ";
            cin >> category;
            displayExpensesByCategory(category);
            break;
        }
        case 7:
            displayTotalExpense();
            break;
        case 8: {
            string startDate, endDate;
            cout << "Enter the start date: ";
            cin >> startDate;
            cout << "Enter the end date: ";
            cin >> endDate;
            displayExpensesWithinDateInterval(startDate, endDate);
            break;
        }
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
    }
}

