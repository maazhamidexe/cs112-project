#ifndef BILL_H
#define BILL_H

#include "expense.h"

class Bill : public Expense {
public:
	Bill(const string& date, const string& name, int price, const string& amount);
	void display() const;
	// Example implementation in Bill class
	string getCategory() const {
		return "bill";
	}

	// Implement the same function in other derived expense classes
	// with their respective categories

};

#endif  // BILL_H
