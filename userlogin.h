#ifndef userlogin_H
#define userlogin_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct User
{
    string username;
    string password;
};

int normallogin(string uname, string upass)
{
    ifstream file("normal_login.txt");
    int num = 0;
    if (file.is_open())
    {
        string line;
        vector<User> users;
        while (getline(file, line))
        {
            istringstream iss(line);
            string username, password;
            if (iss >> username >> password)
            {
                User user;
                user.username = username;
                user.password = password;
                users.push_back(user);
                if ((uname == username) && (upass == password))
                {

                    num = 1;
                }
            }
        }

        // for (const auto& user : users) {
        //     cout << "Username: " << user.username << "\n Password: " << user.password << "\n\n";
        // }
        file.close();
        return num;
    }
}

int premium_login(string uname, string upass)
{
    int num1 = 0;
    ifstream file("premuim_login.txt");

    if (file.is_open())
    {
        string linee;
        vector<User> userss;
        while (getline(file, linee))
        {
            istringstream iss(linee);
            string username, password;
            if (iss >> username >> password)
            {
                User user1;
                user1.username = username;
                user1.password = password;
                userss.push_back(user1);
                if ((uname == username) && (upass == password))
                {
                    num1 = 1;
                }
            }
        }

        // display
        //  for (const auto& user1 : userss) {
        //      cout << "Username: " << user1.username << "\n Password: " << user1.password << "\n\n";
        //  }

        file.close();
    }
    else
    {
        cout << "wrong file";
    }
    return num1;
}

void checklogintype(string uname, string upass)
{
    if (normallogin(uname, upass) == 1 || premium_login(uname, upass) == 1)
    {
     
    cout << "\033[32m"<< "\nLOGIN SUCCESSFUL\n"
    << "-----------------------------\n"<< "\033[0m"; //color green
        
    }
    if (normallogin(uname, upass) == 1)
    {
        cout << "Signed in as normal user\n";
    }
    else if (premium_login(uname, upass) == 1)
    {
         cout << "\033[35m"
    << "Signed in as premium user\n"<< "\033[0m"; //yellow color
    
    }
    else{
        // Set color to red
    cout << "\033[31m"<< "\nINVALID USER/PASSWORD SELECTED\n\nPLEASE TRY AGAIN\n"<< "\033[0m"; 
    // color

       
}}

#endif
