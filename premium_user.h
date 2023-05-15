#ifndef PREMIUM_USER_H
#define PREMIUM_USER_H

#include "normal_user.h"
#include <vector>
#include <string>

using namespace std;

class PremiumUser : public NormalUser {
private:
	double budget;
	vector<double> categoryBudgets;

public:
	PremiumUser(const string& username, const string& password, const string& email);

	double getBudget() const;
	void setBudget(double amount);
	double getCategoryBudget(const string& category) const;
	void setCategoryBudget(const string& category, double amount);
	double calculateTotalExpenses() const;
	double calculateBudgetProgress() const;
	void displayBudgetProgress() const;

	void displayMenu() const;
	void processUserChoice(int choice);

	void displayExpensesByDate(const string& date) const;
	void displayExpensesByCategory(const string& category) const;
	void displayExpensesByDateInterval(const string& startDate, const string& endDate) const;
	void setBudgetForCategories();
};

#endif
