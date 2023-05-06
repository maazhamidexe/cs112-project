#include <iostream>
#include <fstream>
#include "WaterElectricity.h"
#include "Telephone.h"
#include "Entertainment.h"
#include "filemanip.h"

using namespace std;

filemanip f;
ifstream fin;

int main() {
short int choice;
fin.open("Customer.txt");
if (!fin) {
f.CreateCustomerFile();
}
fin.close();
fin.open("Water.txt");
if (!fin) {
f.CreateWaterFile();
}
fin.close();
fin.open("Electricity.txt");
if (!fin) {
f.CreateElectricityFile();
}
fin.close();
fin.open("Telephone.txt");
if (!fin) {
f.CreateTelephoneFile();
}
fin.close();
fin.open("Entertainment.txt");
if (!fin) {
f.CreateEntertainmentFile();
}
fin.close();
fin.open("LoginFile.txt");
if (!fin) {
f.CreateLoginFile();
}
fin.close();
do {
cout << "Choose one: " << endl;
cout << "1. Sign up" << endl;
cout << "2. Login" << endl;
cout << "3. Exit" << endl;
cin >> choice;
switch (choice) {
case 1: f.SignUp();
break;
case 2: f.Login();
break;
case 3: f.CalculateTotal(10);
break;

}
cin.get();
system("cls");
} while (choice != 3);
return 0;
}
