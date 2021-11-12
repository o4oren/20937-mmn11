//
//  Message.h
//  mmn11
//
//  Created by Oren Geva on 10/11/2021.
//

#ifndef Message_h
#define Message_h

#include <string>

class Message
{
private:
    std::string text;
    
public:
    Message(std::string);
    std::string getText();
};

#endif /* Message_h */
