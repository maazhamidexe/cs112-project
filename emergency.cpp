#include "emergency.h"

using namespace std;

Emergency::Emergency(const string& date, const string& name, int price, const string& amount)
    : Expense(date, name, price, amount) {}

void Emergency::display() const {
    cout << "Emergency: " << name << "\n";
    cout << "Date (DD/MM/YYYY) : " << date << "\n";
    cout << "Price: " << price << "\n";
    cout << "Amount: " << amount << "\n";
}
