#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    string username;
    string password;
    string email;

public:
    User(const std::string& username, const std::string& password, const std::string& email);
    virtual ~User();

    string getUsername() const;
    string getPassword() const;
    string getEmail() const;
};

#endif  // USER_H
