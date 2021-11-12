#include "USocial.h"
#include "User.h"
#include <iostream>
User* USocial::getUserById(unsigned long id) {
    auto it = users.find(id);
    if(it != users.end()) {
        return (it->second);
    }
    throw std::runtime_error("User not found!!!");
}

User* USocial::registerUser(std::string name) {
    return registerUser(name, false);
}

User* USocial::registerUser(std::string name, bool isBusinessUser) {
    if(name.length() > 0) {
        ++lastUsedId;
        User* user;
        if(isBusinessUser) {
            user = new BusinessUser();
        } else {
            user = new User();
        }
        
        user->setUsocial(this);
        user->id = lastUsedId;
        user->name = name;
        users.insert(std::pair<const unsigned long, User*>(user->id, user));
        return user;
    }
    return NULL;
}


void USocial::removeUser(User* user) {
    auto it = users.find(user->id);
    
    // if we have found the user id we validate that the name is also identical before erasing
    if(it != users.end() && user->name == it->second->name) {
        users.erase(it->first);
        delete it->second;
    }
}

