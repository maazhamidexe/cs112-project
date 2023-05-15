#include "groceries.h"

using namespace std;

Groceries::Groceries(const string& date, const string& name, int price, const string& amount)
    : Expense(date, name, price, amount) {}

void Groceries::display() const {
    cout << "Groceries: " << name << "\n";
    cout << "Date: (DD/MM/YYYY) " << date << "\n";
    cout << "Price: " << price << "\n";
    cout << "Amount: " << amount << "\n";
}
