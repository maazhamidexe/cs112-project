# cs112-project
#hierarchy
              super class
         +-----------------+
         |     Expense     | 
         +-----------------+
                |
        +-------------------+
        |       Bill        |
        +-------------------+
                |
        +-------------------+
        |    Entertainment  |
        +-------------------+
                |
        +-------------------+
        |      Medical      |
        +-------------------+
                |
        +-------------------+
        |     Education     |
        +-------------------+
                |
        +-------------------+
        |     Groceries     |
        +-------------------+
                |
        +-------------------+
        |     Emergency     |
        +-------------------+
In this hierarchy, the Expense class serves as the base class, 
and all the derived classes (Bill, Entertainment, Medical, Education,
Groceries, Emergency) inherit from it. Each derived class represents 
a specific type of expense, with its own unique attributes and behaviors.

This inheritance structure allowed us to define common methods and 
attributes in the Expense base class, which can be inherited and 
overridden by the derived classes as needed. It provides a way to 
organize and categorize different types of expenses while promoting code reuse and flexibility.


           +-------------+
           |    User     |
           +-------------+
                 |
           +-------------+
           | NormalUser  |
           +-------------+
                 |
           +--------------+
           | PremiumUser  |
           +--------------+
           
 In this hierarchy, the PremiumUser class inherits from the 
 NormalUser class, which in turn inherits from the User class. This allows the 
 PremiumUser class to have access to all the functionalities of both the NormalUser and User classes.
 
 #functionalities
 
 Normal User Features
 
1. Add Expense
OOP Type Used: N/A
Functions Created:
void addExpense(Expense* expense) in User class
Expense* createExpense() in User class
void displayAddExpenseMenu() const in User class
Variables/Objects Created:
Expense* expense in createExpense() function
string date, string name, int price, string amount in createExpense() function
Line of Code Written: Approximately 100 lines


2. Delete Expense
OOP Type Used: N/A
Functions Created:
void deleteExpense(int index) in User class
int getExpenseIndex(const string& expenseName) const in User class
void displayDeleteExpenseMenu() const in User class
Variables/Objects Created: N/A
Line of Code Written: Approximately 70 lines


3. Display Highest Expense
OOP Type Used: N/A
Functions Created:
void displayHighestExpense() const in User class
int findMaxExpenseIndex() const in User class
Variables/Objects Created: N/A
Line of Code Written: Approximately 35 lines


4. Display Lowest Expense
OOP Type Used: N/A
Functions Created:
void displayLowestExpense() const in User class
int findMinExpenseIndex() const in User class
Variables/Objects Created: N/A
Line of Code Written: Approximately 35 lines


5. Display Expenses on a Given Date
OOP Type Used: N/A
Functions Created:
void displayExpensesOnDate() const in User class
Variables/Objects Created:
string date in displayExpensesOnDate() function
Line of Code Written: Approximately 35 lines


6. Display Expenses by Category
OOP Type Used: N/A
Functions Created:
void displayExpensesByCategory() const in User class
int getTotalExpenseByCategory(const string& category) const in User class
Variables/Objects Created: N/A
Line of Code Written: Approximately 40 lines


7. Display Total Expense
OOP Type Used: N/A
Functions Created:
void displayTotalExpense() const in User class
int calculateTotalExpense() const in User class
Variables/Objects Created: N/A
Line of Code Written: Approximately 35 lines

Premium User features:

All the above mentioned feature with the following additional functionalities:

8. Display Expenses Within a Date Interval
OOP Type Used: N/A
Functions Created:
void displayExpensesWithinDateInterval() const in User class
Variables/Objects Created:
string startDate, string endDate in displayExpensesWithinDateInterval() function
Line of Code Written: Approximately 40 lines
  
 9. Set Budget for Categories
OOP Type Used: N/A
Functions Created:
void setBudgetForCategories() in PremiumUser class
void displaySetBudgetMenu() const in PremiumUser class
Variables/Objects Created: N/A
Line of Code Written: Approximately 30 lines
10. Display Budget Progress
OOP Type Used: N/A
Functions Created:
void displayBudgetProgress() const in PremiumUser class
int getCategoryBudget(const string& category) const in PremiumUser class
int getCategoryExpense(const string& category) const in PremiumUser class
Variables/Objects Created: N/A
Line of Code Written: Approximately 40 lines

 
