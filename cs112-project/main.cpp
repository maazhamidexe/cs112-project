#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <thread>
#include <chrono>


#include <ios>    //used to get stream size
#include <limits> //used to get numeric limits
#include <stdlib.h>
using namespace std;
using namespace std;


class Commodity
{
private:
    string name;
    string type;
    double rate;
public:
    Commodity();
    Commodity(string, string, double);
    //setter methods
    void setName(string);
    void setType(string);
    void setRate(double);
    //getter methods
    string getName();
    string getType();
    double getRate();
    //other methods
    void inputDetails();
    void printDetails();
};

class Date
{
private:
    long long day;
    long long month;
    long long year;
    bool validateDate();
public:
    Date();
    Date(long long, long long, long long);
    //setter methods
    void setDay(long long);
    void setMonth(long long);
    void setYear(long long);
    //getter methods
    long long getDay();
    long long getMonth();
    long long getYear();
    //other methods
    void inputDetails();
    void printDetails();
    void stringToDate(string);
    string dateToString();
    long long value();
};

class Expense
{
private:
    long long id;
    Date date;
    Commodity commodity;
    double quantity;
    double amount;
public:
    Expense();
    Expense(long long, Date, Commodity, double, double);
    //setter methods
    void setId(long long);
    void setDate(Date);
    void setCommodity(Commodity);
    void setQuantity(double);
    void setAmount(double);
    //getter methods
    long long getId();
    Date getDate();
    Commodity getCommodity();
    double getQuantity();
    double getAmount();
    //other methods
    void inputDetails(bool);
    void printDetails();
    static void printDetails(vector<Expense>);
};

class ExpenseManager
{
private:
    static map<long long, Expense> expenses;
    static map<long long, string> commodityTypes;
public:
    ExpenseManager();
    
    static void addExpense(Expense);
    static void removeExpense(Expense);
    static Expense getExpenseDetails();
    static void calculateExpenditure();
    static void printExpenses();

    static void addCommodityType(string);
    static void removeCommodityType(string);
    static void printCommodityTypes();
    static string getCommodityType();

    static void readFromCSV();
    static void writeToCSV();
};


//funcs

Commodity::Commodity()
{
    name = "";
    type = "";
    rate = -1.00;
}
Commodity::Commodity(string name, string type, double rate)
{
    this->name = name;
    this->type = type;
    this->rate = rate;
}
// setter methods
void Commodity::setName(string name)
{
    this->name = name;
    return;
}
void Commodity::setType(string type)
{
    this->type = type;
    return;
}
void Commodity::setRate(double rate)
{
    this->rate = rate;
    return;
}
// getter methods
string Commodity::getName()
{
    return name;
}
string Commodity::getType()
{
    return type;
}
double Commodity::getRate()
{
    return rate;
}
// other methods
void Commodity::inputDetails()
{
    cout << "Commodity Name: ";
    getline(cin >> ws, name);
    cout << "\n";
    cout << "Commodity Type:\n";
    ExpenseManager::printCommodityTypes();
    cout << "\nOptions:\n";
    cout << "[01] - Select commodity type from the list above\n";
    cout << "[02] - Add a new commodity type\n\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    while (choice != 1 && choice != 2)
    {
        cout << "\nInvalid choice.\nPlease enter a valid choice: ";
        cin >> choice;
    }
    if (choice == 1)
        type = ExpenseManager::getCommodityType();
    else if (choice == 2)
    {
        cout << "Enter new commodity type: ";
        getline(cin >> ws, type);
        ExpenseManager::addCommodityType(type);
    }
    return;
}
void Commodity::printDetails()
{
    cout << "Commodity Name: " << name << endl;
    cout << "Commodity Type: " << type << endl;
    cout << "Commodity Rate: " << rate << endl;
    return;
}


#define wait(x) this_thread::sleep_for(chrono::milliseconds(x))

Date::Date()
{
    day = -1;
    month = -1;
    year = -1;
}
Date::Date(long long day, long long month, long long year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
// setter methods
void Date::setDay(long long day)
{
    this->day = day;
    return;
}
void Date::setMonth(long long month)
{
    this->month = month;
    return;
}
void Date::setYear(long long year)
{
    this->year = year;
    return;
}
// getter methods
long long Date::getDay()
{
    return day;
}
long long Date::getMonth()
{
    return month;
}
long long Date::getYear()
{
    return year;
}
// other methods
bool Date::validateDate()
{
    //check if the date is a valid calendar date
    if(day < 1 || day > 31)
        return false;
    if(month < 1 || month > 12)
        return false;
    if(year < 0)
        return false;
    if(month == 2)
    {
        if(day > 29)
            return false;
        if(day == 29)
            if(year % 4 != 0)
                return false; // loophole: non-leap years like 2100, 2200, etc.
    }
    if(month == 4 || month == 6 || month == 9 || month == 11)
        if(day > 30)
            return false;
    return true;
}
void Date::inputDetails()
{
    cout << "\n";
    cout << "Enter Date (DD,MM,YYYY):\n";
    cout << "\tDay   - (DD)  : ", cin >> day;
    cout << "\tMonth - (MM)  : ", cin >> month;
    cout << "\tYear  - (YYYY): ", cin >> year;
    cout << "\n";
    while(!validateDate())
    {
        cout << "\nInvalid Date!\nPlease enter a valid date:\n";
        this->inputDetails();
    }
    return;
}
void Date::printDetails()
{
    cout << "Date: " << day << "/" << month << "/" << year << endl;
    return;
}
void Date::stringToDate(string date)
{
    stringstream ss(date);
    string token;
    getline(ss, token, '/');
    day = stoll(token);
    getline(ss, token, '/');
    month = stoll(token);
    getline(ss, token, '/');
    year = stoll(token);
    return;
}
string Date::dateToString()
{
    stringstream ss;
    if (day < 10)
        ss << "0";
    ss << day << "/";
    if (month < 10)
        ss << "0";
    ss << month << "/";
    if (year < 10)
        ss << "000";
    else if (year < 100)
        ss << "00";
    else if (year < 1000)
        ss << "0";
    ss << year;
    return ss.str();
}
long long Date::value()
{
    return year * 10000 + month * 100 + day;
}


Expense::Expense()
{
    id = -1;
    date = Date();
    commodity = Commodity();
    quantity = -1.00;
    amount = -1.00;
}
Expense::Expense(long long id, Date date, Commodity commodity, double quantity, double amount)
{
    this->id = id;
    this->date = date;
    this->commodity = commodity;
    this->quantity = quantity;
    this->amount = amount;
}
// setter methods
void Expense::setId(long long id)
{
    this->id = id;
    return;
}
void Expense::setDate(Date date)
{
    this->date = date;
    return;
}
void Expense::setCommodity(Commodity commodity)
{
    this->commodity = commodity;
    return;
}
void Expense::setQuantity(double quantity)
{
    this->quantity = quantity;
    return;
}
void Expense::setAmount(double amount)
{
    this->amount = amount;
    return;
}
// getter methods
long long Expense::getId()
{
    return id;
}
Date Expense::getDate()
{
    return date;
}
Commodity Expense::getCommodity()
{
    return commodity;
}
double Expense::getQuantity()
{
    return quantity;
}
double Expense::getAmount()
{
    return amount;
}
// other methods
void Expense::inputDetails(bool _date)
{
    cout << "Enter Expense Details:\n";
    cout << "\n\n";
    if (_date)
        date.inputDetails(), cout << "\n";
    commodity.inputDetails();
    cout << "\n";
    cout << "Quantity (kg/ltr/piece): ";
    cin >> quantity;
    while (quantity <= 0)
    {
        cout << "Enter valid quantity: ";
        cin >> quantity;
    }
    cout << "Amount: ";
    cin >> amount;
    commodity.setRate(amount / quantity);
    cout << "\n\n";
    return;
}
void Expense::printDetails()
{
    cout << "\n";

    cout << "Expense Details: \n"
         << endl;
    cout << "ID: ";
    if (date.getDay() < 10)
        cout << "0";
    cout << id << endl;
    date.printDetails();
    commodity.printDetails();
    cout << "Quantity: " << quantity << endl;
    cout << "Amount: " << amount << endl;
    return;
}
void Expense::printDetails(vector<Expense> expenses)
{
    if (expenses.size() == 0)
        return void(cout << "\n\n");
    cout << "\n\n";
    cout << "-------------------------------------------\n\n";
    long long sNoSpace = max(5LL, (long long)log10(expenses.size())), idSpace = 2, dateSpace = 4, commodityNameSpace = 14, commodityTypeSpace = 4, commodityRateSpace = 4, quantitySpace = 8, amountSpace = 6;
    for (auto expense : expenses)
    {
        if (idSpace < to_string(expense.getId()).length())
            idSpace = to_string(expense.getId()).length();
        if (dateSpace < expense.getDate().dateToString().length())
            dateSpace = expense.getDate().dateToString().length();
        if (commodityNameSpace < expense.getCommodity().getName().length())
            commodityNameSpace = expense.getCommodity().getName().length();
        if (commodityTypeSpace < expense.getCommodity().getType().length())
            commodityTypeSpace = expense.getCommodity().getType().length();
        if (commodityRateSpace < to_string(expense.getCommodity().getRate()).length())
            commodityRateSpace = to_string(expense.getCommodity().getRate()).length();
        if (quantitySpace < to_string(expense.getQuantity()).length())
            quantitySpace = to_string(expense.getQuantity()).length();
        if (amountSpace < to_string(expense.getAmount()).length())
            amountSpace = to_string(expense.getAmount()).length();
    }

    long long totalDash = 6 * 3 + 4 + idSpace + dateSpace + commodityNameSpace + commodityTypeSpace + commodityRateSpace + quantitySpace + amountSpace;
    cout << " ";
    for (long long i = 0; i < totalDash; i++)
        cout << "-";
    cout << "\n"
         << " | "
         << left << setw(idSpace) << "ID";
    cout << " | ";
    cout << left << setw(dateSpace) << "Date";
    cout << " | ";
    cout << left << setw(commodityNameSpace) << "Commodity Name";
    cout << " | ";
    cout << left << setw(commodityTypeSpace) << "Type";
    cout << " | ";
    cout << left << setw(commodityRateSpace) << "Rate";
    cout << " | ";
    cout << left << setw(quantitySpace) << "Quantity";
    cout << " | ";
    cout << left << setw(amountSpace) << "Amount";
    cout << " |\n";
    cout << " ";
    for (long long i = 0; i < totalDash; i++)
        cout << "-";
    cout << "\n";
    for (auto expense : expenses)
    {
        cout << " | ";
        if (expense.getDate().getDay() < 10)
            cout << left << setw(idSpace) << (to_string(expense.getId()) + "0");
        else
            cout << left << setw(idSpace) << expense.getId();
        cout << " | ";
        cout << left << setw(dateSpace) << expense.getDate().dateToString();
        cout << " | ";
        cout << left << setw(commodityNameSpace) << expense.getCommodity().getName();
        cout << " | ";
        cout << left << setw(commodityTypeSpace) << expense.getCommodity().getType();
        cout << " | ";
        cout << left << setw(commodityRateSpace) << expense.getCommodity().getRate();
        cout << " | ";
        cout << left << setw(quantitySpace) << expense.getQuantity();
        cout << " | ";
        cout << left << setw(amountSpace) << expense.getAmount();
        cout << " |\n";
    }
    cout << " ";
    for (long long i = 0; i < totalDash; i++)
        cout << "-";
    cout << "\n\n";
    return;
}

map<long long, Expense> ExpenseManager::expenses = map<long long, Expense>();
map<long long, string> ExpenseManager::commodityTypes = map<long long, string>();

ExpenseManager::ExpenseManager()
{
}
void ExpenseManager::addExpense(Expense expense)
{
    long long cnt = 0;
    for (auto E : expenses)
    {
        if (E.second.getDate().value() == expense.getDate().value())
            cnt++;
        else if (E.second.getDate().value() > expense.getDate().value())
            break;
    }
    expense.setId(expense.getDate().value() * 1000 + cnt);
    expenses[expense.getId()] = expense;
    cout << "\nExpense added successfully!" << endl;
    cout << "Expense ID is " << expense.getId() << "\n"
         << endl;
    return;
}
void ExpenseManager::removeExpense(Expense expense)
{
    Date date = expense.getDate();
    long long id = expense.getId();
    expenses.erase(expense.getId());
    cout << "\nExpense with ID " << expense.getId() << " removed successfully!\n\n"
         << endl;
    long long cnt = 0;
    for (auto E : expenses)
    {
        if (E.second.getDate().value() == date.value() && E.second.getId() > id)
            cnt++;
        else if (E.second.getDate().value() > date.value())
            break;
    }
    for (long long i = 0; i < cnt; i++)
        expenses[i + id] = expenses[i + id + 1], expenses[i + id].setId(i + id);
    expenses.erase(cnt + id);
    return;
}
Expense ExpenseManager::getExpenseDetails()
{
    long long choice;
    cout << "\n\n-------------------------------------------\n\n";
    cout << "Search expense by: " << endl;
    cout << "[01] - ID" << endl;
    cout << "[02] - Date" << endl;
    cout << "[03] - Commodity Type" << endl;
    cout << "[04] - Commodity Name" << endl;
    cout << "[05] - Amount Range\n"
         << endl;
    cout << "[-1] - Back\n"
         << endl;
    cout << "-------------------------------------------\n\n";
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice > 5 || (choice < 1 && choice != -1))
    {
        cout << "\nInvalid choice.\nEnter a valid choice: ";
        cin >> choice;
    }

    cout << "\n-------------------------------------------\n\n";
    if (choice == -1)
        return Expense();
    else if (choice == 1)
    {

        long long idReq;
        cout << "Enter ID: ";
        cin >> idReq;
        if (expenses.find(idReq) != expenses.end())
        {
            return expenses[idReq];
        }
        else
        {
            cout << "\n\nNo expense found with ID: " << idReq << endl;
            cout << "\nDo you want to try again? (Y for Yes || N for No): ";
            char choice;
            cin >> choice;
            while (choice != 'Y' && choice != 'N')
            {
                cout << "Enter valid choice (Y or N): ";
                cin >> choice;
            }
            return (choice == 'Y' || choice == 'y') ? getExpenseDetails() : Expense();
        }
    }
    else if (choice == 2)
    {

        Date dateReq;
        cout << "\nEnter Date: ";
        dateReq.inputDetails();
        vector<Expense> matchingExpenses;
        for (auto expense : expenses)
            if (expense.second.getDate().value() == dateReq.value())
                matchingExpenses.push_back(expense.second);
        if (matchingExpenses.size() == 0)
        {
            cout << "\nNo matching records found with date " << dateReq.dateToString() << ".\n"
                 << endl;
            cout << "\nDo you want to try again? (Y for Yes || N for No): ";
            char choice;
            cin >> choice;
            while (choice != 'Y' && choice != 'N')
            {
                cout << "Enter valid choice (Y or N): ";
                cin >> choice;
            }
            return (choice == 'Y' || choice == 'y') ? getExpenseDetails() : Expense();
        }
        else
        {
            cout << "\n"
                 << matchingExpenses.size() << " matching records found with date " << dateReq.dateToString() << ".\n"
                 << endl;
            Expense::printDetails(matchingExpenses);
            char choice = 'Y';
            while (choice == 'Y')
            {
                cout << "\nEnter ID of the required expense: ";
                long long idReq;
                cin >> idReq;
                for (auto expense : matchingExpenses)
                    if (expense.getId() == idReq)
                        return expense;
                cout << "\nNo expense from the list above has ID " << idReq << ".\n"
                     << endl;
                cout << "\nDo you want to try again? (Y for Yes || N for No): ";
                cin >> choice;
                while (choice != 'Y' && choice != 'N')
                {
                    cout << "\nEnter valid choice (Y or N): ";
                    cin >> choice;
                }
            }
        }
    }
    else if (choice == 3)
    {
        string commodityTypeReq;
        cout << "\n";
        printCommodityTypes();
        cout << "\n";
        cout << "\nEnter Commodity Type: ";
        cin >> commodityTypeReq;
        vector<Expense> matchingExpenses;
        for (auto expense : expenses)
            if (expense.second.getCommodity().getType() == commodityTypeReq)
                matchingExpenses.push_back(expense.second);
        if (matchingExpenses.size() == 0)
        {
            cout << "\nNo matching records found with commodity type " << commodityTypeReq << ".\n"
                 << endl;
            cout << "\nDo you want to try again? (Y for Yes || N for No): ";
            char choice;
            cin >> choice;
            while (choice != 'Y' && choice != 'N')
            {
                cout << "Enter valid choice (Y or N): ";
                cin >> choice;
            }
            return (choice == 'Y' || choice == 'y') ? getExpenseDetails() : Expense();
        }
        else
        {
            cout << "\n"
                 << matchingExpenses.size() << " matching records found with commodity type " << commodityTypeReq << ".\n"
                 << endl;
            Expense E = Expense();
            Expense::printDetails(matchingExpenses);
            char choice = 'Y';
            while (choice == 'Y')
            {
                cout << "\nEnter ID of the required expense: ";
                long long idReq;
                cin >> idReq;
                for (auto expense : matchingExpenses)
                    if (expense.getId() == idReq)
                        return expense;
                cout << "\nNo expense from the list above has ID " << idReq << ".\n"
                     << endl;
                cout << "Do you want to try again? (Y for Yes || N for No): ";
                cin >> choice;
                while (choice != 'Y' && choice != 'N')
                {
                    cout << "Enter valid choice (Y or N): ";
                    cin >> choice;
                }
            }
        }
    }
    else if (choice == 4)
    {
        string commodityNameReq;
        cout << "Enter Commodity Name: ";
        cin >> commodityNameReq;
        vector<Expense> matchingExpenses;
        for (auto expense : expenses)
            if (expense.second.getCommodity().getName() == commodityNameReq)
                matchingExpenses.push_back(expense.second);
        if (matchingExpenses.size() == 0)
        {
            cout << "\nNo matching records found with commodity name " << commodityNameReq << ".\n"
                 << endl;
            cout << "Do you want to try again? (Y for Yes || N for No): ";
            char choice;
            cin >> choice;
            while (choice != 'Y' && choice != 'N')
            {
                cout << "Enter valid choice (Y or N): ";
                cin >> choice;
            }
            return (choice == 'Y' || choice == 'y') ? getExpenseDetails() : Expense();
        }
        else
        {
            cout << matchingExpenses.size() << " matching records found with commodity name " << commodityNameReq << ".\n"
                 << endl;
            Expense E = Expense();
            Expense::printDetails(matchingExpenses);
            char choice = 'Y';
            while (choice == 'Y')
            {
                cout << "\nEnter ID of the required expense: ";
                long long idReq;
                cin >> idReq;
                for (auto expense : matchingExpenses)
                    if (expense.getId() == idReq)
                        return expense;
                cout << "No expense from the list above has ID " << idReq << ".\n"
                     << endl;
                cout << "Do you want to try again? (Y for Yes || N for No): ";
                cin >> choice;
                while (choice != 'Y' && choice != 'N')
                {
                    cout << "Enter valid choice (Y or N): ";
                    cin >> choice;
                }
            }
        }
    }
    else if (choice == 5)
    {
        long long lowerLimitReq, upperLimitReq;
        cout << "\n\nEnter Amount Range:\n";
        cout << "Lower Limit: ";
        cin >> lowerLimitReq;
        cout << "Upper Limit: ";
        cin >> upperLimitReq;
        if (lowerLimitReq > upperLimitReq)
            swap(lowerLimitReq, upperLimitReq);
        vector<Expense> matchingExpenses;
        for (auto expense : expenses)
            if (expense.second.getAmount() >= lowerLimitReq && expense.second.getAmount() <= upperLimitReq)
                matchingExpenses.push_back(expense.second);
        if (matchingExpenses.size() == 0)
        {
            cout << "\nNo matching records found with amount range " << lowerLimitReq << " to " << upperLimitReq << ".\n"
                 << endl;
            cout << "Do you want to try again? (Y for Yes || N for No): ";
            char choice;
            cin >> choice;
            while (choice != 'Y' && choice != 'N')
            {
                cout << "Enter valid choice (Y or N): ";
                cin >> choice;
            }
            return (choice == 'Y' || choice == 'y') ? getExpenseDetails() : Expense();
        }
        else
        {
            cout << matchingExpenses.size() << " matching records found with amount range " << lowerLimitReq << " to "
                 << upperLimitReq << ".\n"
                 << endl;
            Expense E = Expense();
            Expense::printDetails(matchingExpenses);
            char choice = 'Y';
            while (choice == 'Y')
            {
                cout << "\nEnter ID of the required expense: ";
                long long idReq;
                cin >> idReq;
                for (auto expense : matchingExpenses)
                    if (expense.getId() == idReq)
                        return expense;
                cout << "No expense from the list above has ID " << idReq << ".\n"
                     << endl;
                cout << "Do you want to try again? (Y for Yes || N for No): ";
                cin >> choice;
                while (choice != 'Y' && choice != 'N')
                {
                    cout << "Enter valid choice (Y or N): ";
                    cin >> choice;
                }
            }
        }
    }
    return Expense();
}
void ExpenseManager::calculateExpenditure()
{
    long long choice;
    cout << "Options: " << endl;
    cout << "\n[01] - Between two dates" << endl;
    cout << "[02] - Total Expenditure from the begining of the records\n" << endl;
    cout << "[-1] - Back\n" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    while ((choice > 4) || (choice < 1 && choice != -1))
    {
        cout << "Enter valid choice: ";
        cin >> choice;
    }
    if (choice == -1)
        return;
    else if (choice == 1)
    {
        Date startDate, endDate;
        cout << "\nEnter start date:\n";
        startDate.inputDetails();
        cout << "\nEnter end date:\n";
        endDate.inputDetails();
        cout << "Calculate expenditure from " << startDate.dateToString() << " to " << endDate.dateToString() << ": " << endl;
        cout << "\n[01] - By Commodity name" << endl;
        cout << "[02] - By Commodity type" << endl;
        cout << "[03] - For all commodities\n" << endl;
        cout << "[-1] - Back\n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        while ((choice > 3) || (choice < 1 && choice != -1))
        {
            cout << "Enter valid choice: ";
            cin >> choice;
        }
        if (choice == -1)
            return calculateExpenditure();
        else if (choice == 1)
        {
            string commodityNameReq;
            cout << "Enter Commodity Name: ";
            getline(cin >> ws, commodityNameReq);
            long long totalExpenditure = 0;
            for (auto expense : expenses)
                if (expense.second.getDate().value() >= startDate.value() && expense.second.getDate().value() <= endDate.value() &&
                    expense.second.getCommodity().getName() == commodityNameReq)
                    totalExpenditure += expense.second.getAmount();
            cout << "Total expenditure from " << startDate.dateToString() << " to " << endDate.dateToString() << " for commodity " << commodityNameReq
                 << " is " << totalExpenditure << endl;
        }
        else if (choice == 2)
        {
            string commodityTypeReq;
            cout << "\n";
            printCommodityTypes();
            cout << "\n";
            cout << "Enter Commodity Type: ";
            getline(cin >> ws, commodityTypeReq);
            long long totalExpenditure = 0;
            for (auto expense : expenses)
                if (expense.second.getDate().value() >= startDate.value() && expense.second.getDate().value() <= endDate.value() &&
                    expense.second.getCommodity().getType() == commodityTypeReq)
                    totalExpenditure += expense.second.getAmount();
            cout << "Total expenditure from " << startDate.dateToString() << " to " << endDate.dateToString() << " for commodity type " << commodityTypeReq
                 << " is " << totalExpenditure << endl;
        }
        else if (choice == 3)
        {
            long long totalExpenditure = 0;
            for (auto expense : expenses)
                if (expense.second.getDate().value() >= startDate.value() && expense.second.getDate().value() <= endDate.value())
                    totalExpenditure += expense.second.getAmount();
            cout << "Total expenditure from " << startDate.dateToString() << " to " << endDate.dateToString() << " is " << totalExpenditure << endl;
        }
    }
    else if (choice == 2)
    {
        cout << "Calculate expenditure from the begining of the records: " << endl;
        cout << "\n[01] - By Commodity name" << endl;
        cout << "[02] - By Commodity type" << endl;
        cout << "[03] - For all commodities\n" << endl;
        cout << "[-1] - Back\n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        while ((choice > 3) || (choice < 1 && choice != -1))
        {
            cout << "Enter valid choice: ";
            cin >> choice;
        }
        if (choice == -1)
            return calculateExpenditure();
        else if (choice == 1)
        {
            string commodityNameReq;
            cout << "Enter Commodity Name: ";
            getline(cin >> ws, commodityNameReq);
            long long totalExpenditure = 0;
            for (auto expense : expenses)
                if (expense.second.getCommodity().getName() == commodityNameReq)
                    totalExpenditure += expense.second.getAmount();
            cout << "Total expenditure for commodity " << commodityNameReq << " is " << totalExpenditure << endl;
        }
        else if (choice == 2)
        {
            string commodityTypeReq;
            cout << "\n";
            printCommodityTypes();
            cout << "\n";
            cout << "Enter Commodity Type: ";
            getline(cin >> ws, commodityTypeReq);
            long long totalExpenditure = 0;
            for (auto expense : expenses)
                if (expense.second.getCommodity().getType() == commodityTypeReq)
                    totalExpenditure += expense.second.getAmount();
            cout << "Total expenditure for commodity type " << commodityTypeReq << " is " << totalExpenditure << endl;
        }
        else if (choice == 3)
        {
            long long totalExpenditure = 0;
            for (auto expense : expenses)
                totalExpenditure += expense.second.getAmount();
            cout << "Total expenditure is " << totalExpenditure << endl;
        }
    }
}
void ExpenseManager::printExpenses()
{
    vector<Expense> allExpenses;
    for (auto expense : expenses)
        allExpenses.push_back(expense.second);
    Expense::printDetails(allExpenses);
    return;
}
void ExpenseManager::addCommodityType(string type)
{
    for (auto commodityType : commodityTypes)
        if (commodityType.second == type)
            return;
    commodityTypes[commodityTypes.size()] = type;
    return;
}
void ExpenseManager::removeCommodityType(string type)
{
    for (long long i = 0; i < commodityTypes.size(); i++)
        if (commodityTypes[i] == type)
        {
            for (long long j = i; j < commodityTypes.size() - 1; j++)
                commodityTypes[j] = commodityTypes[j + 1];
            commodityTypes.erase(commodityTypes.size() - 1);
            return;
        }
    return;
}
void ExpenseManager::printCommodityTypes()
{
    cout << "\nExisting Commodity Types:\n\n";
    for (auto commodityType : commodityTypes)
        cout << left << setw(log10((int)(commodityTypes.size() > 1) ? commodityTypes.size() - 1 : 1)) << commodityType.first,
            cout << ": " << commodityType.second << endl;
    cout << endl;
    return;
}
string ExpenseManager::getCommodityType()
{
    long long id;
    cout << "\nEnter ID of required Commodity Type: ";
    cin >> id;
    while (id < 0 || id >= commodityTypes.size())
    {
        cout << "Invalid ID.\nPlease enter again: ";
        cin >> id;
    }
    return commodityTypes[id];
}
void ExpenseManager::readFromCSV()
{
    ifstream file;
    file.open("./data/expenseSheet.csv");
    string line;
    getline(file, line); // skip first line
    while (getline(file, line))
    {
        stringstream ss(line);
        string token;
        long long id;
        Date date;
        Commodity commodity;
        double quantity;
        double amount;
        getline(ss, token, ',');
        id = stoll(token);
        getline(ss, token, ',');
        date.stringToDate(token);
        getline(ss, token, ',');
        commodity.setName(token);
        getline(ss, token, ',');
        commodity.setType(token);
        getline(ss, token, ',');
        commodity.setRate(stod(token));
        getline(ss, token, ',');
        quantity = stod(token);
        getline(ss, token, ',');
        amount = stod(token);
        expenses[id] = Expense(id, date, commodity, quantity, amount);
    }
    file.close();
    file.open("./data/commodityTypes.csv");
    getline(file, line); // skip first line
    while (getline(file, line))
    {
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        getline(ss, token, ',');
        commodityTypes[commodityTypes.size()] = token;
    }
    return;
}
void ExpenseManager::writeToCSV()
{
    ofstream file;
    file.open("./data/temp.csv");
    file << "ID,Date,Commodity Name,Commodity Type,Rate,Quantity,Amount\n";
    for (auto expense : expenses)
    {
        file << expense.first << ",";
        file << expense.second.getDate().dateToString() << ",";
        file << expense.second.getCommodity().getName() << ",";
        file << expense.second.getCommodity().getType() << ",";
        file << expense.second.getCommodity().getRate() << ",";
        file << expense.second.getQuantity() << ",";
        file << expense.second.getAmount() << "\n";
    }
    file.close();
    remove("./data/expenseSheet.csv");
    rename("./data/temp.csv", "./data/expenseSheet.csv");

    file.open("./data/temp.csv");
    file << "S.No.,Commodity Type\n";
    for (auto commodityType : commodityTypes)
    {
        file << commodityType.first << ",";
        file << commodityType.second << "\n";
    }
    file.close();
    remove("./data/commodityTypes.csv");
    rename("./data/temp.csv", "./data/commodityTypes.csv");

    return;
}


int main()
{
    ExpenseManager::readFromCSV();
    long long choice = 0;
    while (choice != -1)
    {
        
        cout << "\n\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "--- || E X P E N S E   M A N A G E R || ---\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\n";
        cout << "|~~~~~~~~~~~~~~~~~ HOME ~~~~~~~~~~~~~~~~~~|";
        cout << "\n\n";
        cout << "Options:\n"
             << endl;
        cout << "[01] - Manage Expenses" << endl;
        cout << "[02] - Manage Commodity Types\n"
             << endl;
        cout << "[-1] - Exit\n"
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        while ((choice > 2 || choice < 1) && choice != -1)
        {
            cout << "\nInvalid choice.\nPlease enter again: ";
            cin >> choice;
        }
        cout << "\n-------------------------------------------\n\n";
        if (choice == 1)
        {
            long long subChoice = 0;
            while (subChoice != -1)
            {
                
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "--- || E X P E N S E   M A N A G E R || ---\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                cout << "\n\n";
                cout << "|~~~~~~~~~~~~ MANAGE EXPENSES ~~~~~~~~~~~~|";
                cout << "\n\n";
                cout << "Options:\n"
                     << endl;
                cout << "[01] - Add new Expense" << endl;
                cout << "[02] - View an existing Expense" << endl;
                cout << "[03] - Delete an existing Expense" << endl;
                cout << "[04] - Calculate Expenditure" << endl;
                cout << "[05] - View all Expenses\n"
                     << endl;
                cout << "[-1] - Back\n"
                     << endl;
                cout << "Enter your choice: ";
                cin >> subChoice;
                while ((subChoice < 1 || subChoice > 5) && subChoice != -1)
                {
                    cout << "Invalid choice. Please enter again: ";
                    cin >> subChoice;
                }
                cout << "\n-------------------------------------------\n\n";
                if (subChoice == 1)
                {
                    Expense expense;
                    expense.inputDetails(1);
                    ExpenseManager::addExpense(expense);
                    cout << "\n\nAdd another expense with the same date? (Y for Yes || N for No): ";
                    char choice;
                    cin >> choice;
                    while (choice != 'Y' && choice != 'N')
                    {
                        cout << "Invalid choice. Please enter again: ";
                        cin >> choice;
                    }
                    cout << "\n\n";
                    while (choice == 'Y')
                    {
                        Date _date = expense.getDate();
                        expense.inputDetails(0);
                        expense.setDate(_date);
                        ExpenseManager::addExpense(expense);
                        cout << "\n\nAdd another expense with the same date? (Y for Yes || N for No): ";
                        cin >> choice;
                        while (choice != 'Y' && choice != 'N')
                        {
                            cout << "Invalid choice. Please enter again: ";
                            cin >> choice;
                        }
                        cout << "\n\n";
                    }
                }
                else if (subChoice == 2)
                {
                    Expense expense = ExpenseManager::getExpenseDetails();
                    if (expense.getId() != -1)
                        expense.printDetails();
                }
                else if (subChoice == 3)
                {
                    Expense expense = ExpenseManager::getExpenseDetails();
                    if (expense.getId() != -1)
                        ExpenseManager::removeExpense(expense);
                }
                else if (subChoice == 4)
                {
                    ExpenseManager::calculateExpenditure();
                }
                else if (subChoice == 5)
                {
                    ExpenseManager::printExpenses();
                }
                cout << "\n\n-------------------------------------------\n\n";
                if (subChoice != -1)
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                }
            }
        }
        else if (choice == 2)
        {
            long long subChoice = 0;
            while (subChoice != -1)
            {
                
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "--- || E X P E N S E   M A N A G E R || ---\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                cout << "\n\n";
                cout << "|~~~~~~~~ MANAGE COMMODITY TYPES ~~~~~~~~~|";
                cout << "\n\n";
                cout << "Options:\n"
                     << endl;
                cout << "[01] - Add new Commodity Type" << endl;
                cout << "[02] - View existing Commodity Types" << endl;
                cout << "[03] - Delete an existing Commodity Type\n"
                     << endl;
                cout << "[-1] - Back\n"
                     << endl;
                cout << "Enter your choice: ";
                cin >> subChoice;
                while ((subChoice < 1 || subChoice > 3) && subChoice != -1)
                {
                    cout << "Invalid choice. Please enter again: ";
                    cin >> subChoice;
                }
                cout << "\n-------------------------------------------\n\n";
                if (subChoice == 1)
                {
                    string commodityType;
                    cout << "Enter Commodity Type: ";
                    getline(cin >> ws, commodityType);
                    ExpenseManager::addCommodityType(commodityType);
                }
                else if (subChoice == 2)
                {
                    ExpenseManager::printCommodityTypes();
                }
                else if (subChoice == 3)
                {
                    ExpenseManager::printCommodityTypes();
                    ExpenseManager::removeCommodityType(ExpenseManager::getCommodityType());
                }
                cout << "\n\n-------------------------------------------\n\n";

                if (subChoice != -1)
                {
                    if (subChoice - 1)
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                }
            }
        }
        else if (choice == -1)
        {
            cout << "Exiting...\n"
                 << endl;
            cout << "-------------------------------------------\n\n";
        }
    }
    ExpenseManager::writeToCSV();
    
    return 0;
}
