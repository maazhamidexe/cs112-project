#include "bill.h"

using namespace std;

Bill::Bill(const string& date, const string& name, int price, const string& amount)
    : Expense(date, name, price, amount) {}

void Bill::display() const {
    cout << "Bill: " << name << "\n";
    cout << "Date: " << date << "\n";
    cout << "Price: " << price << "\n";
    cout << "Amount: " << amount << "\n";
}
