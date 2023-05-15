#ifndef MEDICAL_H
#define MEDICAL_H

#include "expense.h"

class Medical : public Expense {
public:
	Medical(const string& date, const string& name, int price, const string& amount);
	void display() const;
	// Example implementation in Bill class
	string getCategory() const {
		return "bill";
	}

	// Implement the same function in other derived expense classes
	// with their respective categories

};

#endif  // MEDICAL_H
