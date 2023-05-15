#ifndef NORMAL_USER_H
#define NORMAL_USER_H

#include "user.h"
#include "expense.h"
#include <vector>

class NormalUser : public User {
public:
    std::vector<Expense*> expenses;

public:
    NormalUser(const std::string& username, const std::string& password, const std::string& email);
    ~NormalUser();

    void addExpense(Expense* expense);
    void deleteExpense(int index);
    void displayHighestExpense() const;
    void displayLowestExpense() const;
    void displayExpensesOnDate(const std::string& date) const;
    void displayExpensesByCategory(const std::string& category) const;
    void displayTotalExpense() const;
    void displayExpensesWithinDateInterval(const std::string& startDate, const std::string& endDate) const;
    void displayMenu() const;
    void processUserChoice(int choice);
};

#endif  // NORMAL_USER_H
