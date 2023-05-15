#include "expense.h"

using namespace std;

Expense::Expense(const string& date, const string& name, int price, const string& amount)
	: date(date), name(name), price(price), amount(amount) {}

Expense::~Expense() {}

string Expense::getDate() const {
	return date;
}

void Expense::setDate(const string& date) {
	this->date = date;
}

string Expense::getName() const {
	return name;
}

void Expense::setName(const string& name) {
	this->name = name;
}

int Expense::getPrice() const {
	return price;
}

void Expense::setPrice(int price) {
	this->price = price;
}

string Expense::getAmount() const {
	return amount;
}

void Expense::setAmount(const string& amount) {
	this->amount = amount;
}

void Expense::display() const
{
}

string Expense::getCategory() const
{
	return string();
}
