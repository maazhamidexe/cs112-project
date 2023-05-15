#include "education.h"

using namespace std;

Education::Education(const string& date, const string& name, int price, const string& amount)
    : Expense(date, name, price, amount) {}

void Education::display() const {
    cout << "Education: " << name << "\n";
    cout << "Date (DD/MM/YYYY) : " << date << "\n";
    cout << "Price: " << price << "\n";
    cout << "Amount: " << amount << "\n";
}
