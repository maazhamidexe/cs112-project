#include "entertainment.h"

using namespace std;

Entertainment::Entertainment(const string& date, const string& name, int price, const string& amount)
    : Expense(date, name, price, amount) {}

void Entertainment::display() const {
    cout << "Entertainment: " << name << "\n";
    cout << "Date (DD/MM/YYYY): " << date << "\n";
    cout << "Price: " << price << "\n";
    cout << "Amount: " << amount << "\n";
}
