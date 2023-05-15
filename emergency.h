#ifndef EMERGENCY_H
#define EMERGENCY_H

#include "expense.h"

class Emergency : public Expense {
public:
	Emergency(const string& date, const string& name, int price, const string& amount);
	void display() const;
	// Example implementation in Bill class
	string getCategory() const {
		return "bill";
	}

	// Implement the same function in other derived expense classes
	// with their respective categories

};

#endif  // EMERGENCY_H
