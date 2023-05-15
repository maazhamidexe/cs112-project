#ifndef ENTERTAINMENT_H
#define ENTERTAINMENT_H

#include "expense.h"

class Entertainment : public Expense {
public:
	Entertainment(const string& date, const string& name, int price, const string& amount);
	void display() const;
	// Example implementation in Bill class
	string getCategory() const {
		return "bill";
	}

	// Implement the same function in other derived expense classes
	// with their respective categories

};

#endif  // ENTERTAINMENT_H
