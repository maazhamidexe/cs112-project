#include <iostream>
#include "normal_user.h"
#include "premium_user.h"
#include "C:\Users\alido\Desktop\cs project (1)\userlogin.h"


using namespace std;

int main() {
	NormalUser normalUser("John", "password", "john@example.com");
	PremiumUser premiumUser("Jane", "password", "jane@example.com");

	int choice;
	do {
		system("CLS");
		string muname , mupass ;


		cout<<"\033[33m";
		cout << "--------------------------------------------\n";

		cout << "  ____ " << "  _   " << " _  __" << " _  \n" ;
		cout << " / ___|" << " | |  " << "| |/ /" << "| |  \n" ;
		cout << "| |  _ " << " | |  " << "| ' / " << "| |  \n" ;
		cout << "| |_| |" << " | |  " << "|  < \ " << "| |  \n";
		cout << " \\___ |" << " |_|  " << "|_|\\__" << "|_|  \n";
		cout << "\n--------------------------------------------\n";

		cout << "\033[34m";
		cout << endl;
		cout << "Welcome to the Login Page!" << endl;
		cout << "                      \n";
		cout << "Please enter username: ";
		cin >> muname;
		cout << "\nEnter password: ";
		cin >> mupass;
		cout<<"\n\033[0m";


		



	/*cout << "Select user type:\n";
	cout << "1. Normal User\n";
	cout << "2. Premium User\n";
	cout << "3. Exit.\n";
	cout << "Enter your choice: ";
	cin >> choice;*/
		checklogintype(muname, mupass);
	if (normallogin(muname,mupass)) {
		cout << "\n \n";
		do {
			
			
			normalUser.displayMenu();
			cin >> choice;
			
			normalUser.processUserChoice(choice);
			
		} while (choice != 9);
	}
	else if (premium_login(muname, mupass)) {

		cout << "\n  \n";
		do {
			
			premiumUser.displayMenu();
			cin >> choice;
			system("CLS");
			premiumUser.processUserChoice(choice);
			system("CLS");
		} while (choice != 11);
	}
	else {
		cout << "Invalid username or password. Exiting...\n";
		return 0;
	}
}while (choice!=3);

	return 0;
}
