//
//  USocial.h
//  mmn11
//
//  Created by Oren Geva on 10/11/2021.
//

#ifndef USocial_h
#define USocial_h

#include <map>
#include <string>
#include <algorithm>

class User;

class USocial
{
private:
    std::map<const unsigned long, User*> users;
    unsigned long lastUsedId;

public:
    User* registerUser(std::string, bool);
    User* registerUser(std::string);
    void removeUser(User*);
    User* getUserById(unsigned long);
};

#endif /* USocial_h */
