#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include <iostream>

using namespace std;

// Base expense class
class Expense {
protected:
	string date;
	string name;
	int price;
	string amount;

public:
	Expense(const string& date, const string& name, int price, const string& amount);
	virtual ~Expense();

	// Getters and setters
	string getDate() const;
	void setDate(const string& date);

	string getName() const;
	void setName(const string& name);

	int getPrice() const;
	void setPrice(int price);

	string getAmount() const;
	void setAmount(const string& amount);

	// Display expense information
	virtual void display() const;
	virtual string getCategory() const;
};

#endif  // EXPENSE_H
