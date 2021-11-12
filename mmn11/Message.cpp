#include "Message.h"
#include <string>

Message::Message(std::string text){
    this->text = text;
}

std::string Message::getText() { 
    return this->text;
}
