#include "premium_user.h"
#include "bill.h"
#include "entertainment.h"
#include "medical.h"

#include <iostream>
#include <iomanip>

using namespace std;

PremiumUser::PremiumUser(const string& username, const string& password, const string& email)
	: NormalUser(username, password, email), budget(0.0), categoryBudgets(6, 0.0) {}

double PremiumUser::getBudget() const {
	return budget;
}

void PremiumUser::setBudget(double amount) {
	budget = amount;
}

double PremiumUser::getCategoryBudget(const string& category) const {
	if (category == "bill")
		return categoryBudgets[0];
	else if (category == "entertainment")
		return categoryBudgets[1];
	else if (category == "medical")
		return categoryBudgets[2];
	else if (category == "education")
		return categoryBudgets[3];
	else if (category == "groceries")
		return categoryBudgets[4];
	else if (category == "emergency")
		return categoryBudgets[5];
	else
		return 0.0; // Invalid category, return 0 budget
}

void PremiumUser::setCategoryBudget(const string& category, double amount) {
	if (category == "bill")
		categoryBudgets[0] = amount;
	else if (category == "entertainment")
		categoryBudgets[1] = amount;
	else if (category == "medical")
		categoryBudgets[2] = amount;
	else if (category == "education")
		categoryBudgets[3] = amount;
	else if (category == "groceries")
		categoryBudgets[4] = amount;
	else if (category == "emergency")
		categoryBudgets[5] = amount;
	else
		cout << "Invalid category.\n";
}

double PremiumUser::calculateTotalExpenses() const {
	double totalExpenses = 0.0;
	for (const Expense* expense : expenses) {
		totalExpenses += expense->getPrice();
	}
	return totalExpenses;
}

double PremiumUser::calculateBudgetProgress() const {
	double totalExpenses = calculateTotalExpenses();
	return (totalExpenses / budget) * 100.0;
}

void PremiumUser::displayBudgetProgress() const {
	cout << "----- Budget Progress -----\n";
	cout << "Total Expenses: $" << fixed << setprecision(2) << calculateTotalExpenses() << endl;
	cout << "Budget: $" << fixed << setprecision(2) << budget << endl;
	cout << "Progress: " << fixed << setprecision(2) << calculateBudgetProgress() << "%" << endl;
}
void PremiumUser::displayMenu() const {
	cout << "----- Premium User Menu -----\n";
	cout << "1. Add Expense\n";
	cout << "2. Delete Expense\n";
	cout << "3. Display Highest Expense\n";
	cout << "4. Display Lowest Expense\n";
	cout << "5. Display Expenses on a Given Date\n";
	cout << "6. Display Expenses by Category\n";
	cout << "7. Display Total Expense\n";
	cout << "8. Display Expenses within a Given Interval of Dates\n";
	cout << "9. Set Budget for Categories\n";
	cout << "10. Display Budget Progress\n";
	cout << "11. Quit\n";
	cout << "Enter your choice: ";
}

void PremiumUser::processUserChoice(int choice) {
	switch (choice) {
	case 1: {
		string category, name, date, amount;
		double price;
		cout << "Enter category: (bill, medical, education, emergency, entertainment, groceries) ";
		cin.ignore();
		getline(cin, category);
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter price: ";
		cin >> price;
		cin.ignore();
		cout << "Enter date: (DD-MM-YYYY) ";
		getline(cin, date);
		cout << "Enter amount: ";
		getline(cin, amount);


		// Create an instance of the appropriate derived class
		Expense* expense = nullptr;
		if (category == "bill") {
			expense = new Bill(date, name, price, amount);
		}
		else if (category == "entertainment") {
			expense = new Entertainment(date, name, price, amount);
		}
		else if (category == "medical") {
			expense = new Medical(date, name, price, amount);
		}
		else {
			cout << "Invalid category. Expense not added.\n";
			break;
		}

		addExpense(expense);
		break;
	}
	case 2: {
		// Delete Expense
		int index;
		cout << "Enter the index of the expense to delete: ";
		cin >> index;
		deleteExpense(index);
		break;
	}
	case 3: {
		// Display Highest Expense
		displayHighestExpense();
		break;
	}
	case 4: {
		// Display Lowest Expense
		displayLowestExpense();
		break;
	}
	case 5: {
		// Display Expenses on a Given Date
		string date;
		cout << "Enter the date (YYYY-MM-DD): ";
		cin.ignore();
		getline(cin, date);
		displayExpensesByDate(date);
		break;
	}
	case 6: {
		// Display Expenses by Category
		string category;
		cout << "Enter the category: ";
		cin.ignore();
		getline(cin, category);
		displayExpensesByCategory(category);
		break;
	}
	case 7: {
		// Display Total Expense
		displayTotalExpense();
		break;
	}
	case 8: {
		// Display Expenses within a Given Interval of Dates
		string startDate, endDate;
		cout << "Enter the start date (YYYY-MM-DD): ";
		cin.ignore();
		getline(cin, startDate);
		cout << "Enter the end date (YYYY-MM-DD): ";
		getline(cin, endDate);
		displayExpensesByDateInterval(startDate, endDate);
		break;
	}
	case 9: {
		// Set Budget for Categories
		setBudgetForCategories();
		break;
	}
	case 10: {
		// Display Budget Progress
		displayBudgetProgress();
		break;
	}
	case 11: {
		// Quit
		cout << "Goodbye! Exiting the program.\n";
		exit(0);
	}
	default:
		cout << "Invalid choice. Please try again.\n";
		break;
	}
}


void PremiumUser::displayExpensesByDate(const string& date) const
{
}

void PremiumUser::displayExpensesByCategory(const string& category) const
{
}

void PremiumUser::displayExpensesByDateInterval(const string& startDate, const string& endDate) const
{
}

void PremiumUser::setBudgetForCategories()
{
}
