#ifndef EDUCATION_H
#define EDUCATION_H

#include "expense.h"

class Education : public Expense {
public:
	Education(const string& date, const string& name, int price, const string& amount);
	void display() const;
	// Example implementation in Bill class
	string getCategory() const {
		return "bill";
	}

	// Implement the same function in other derived expense classes
	// with their respective categories

};

#endif  // EDUCATION_H
