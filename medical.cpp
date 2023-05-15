#include "medical.h"

using namespace std;

Medical::Medical(const string& date, const string& name, int price, const string& amount)
    : Expense(date, name, price, amount) {}

void Medical::display() const {
    cout << "Medical: " << name << "\n";
    cout << "Date : (DD/MM/YYYY) " << date << "\n";
    cout << "Price: " << price << "\n";
    cout << "Amount: " << amount << "\n";
}
