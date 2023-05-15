#ifndef GROCERIES_H
#define GROCERIES_H

#include "expense.h"

class Groceries : public Expense {
public:
	Groceries(const string& date, const string& name, int price, const string& amount);
	void display() const;
	// Example implementation in Bill class
	string getCategory() const {
		return "bill";
	}

	// Implement the same function in other derived expense classes
	// with their respective categories

};

#endif  // GROCERIES_H
