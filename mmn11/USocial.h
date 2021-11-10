//
//  USocial.h
//  mmn11
//
//  Created by Oren Geva on 10/11/2021.
//

#ifndef USocial_h
#define USocial_h

#include "User.h"
#include <map>
#include <string>

class USocial
{
private:
    std::map<unsigned long, User> users;
public:
    User* registerUser(std::string, bool);
    User* registerUser(std::string);
    void removeUser(User*);
    User* getUserById(unsigned long);
};

#endif /* USocial_h */
