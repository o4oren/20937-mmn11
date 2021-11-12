#ifndef User_h
#define User_h

#include "Post.h"
#include "Message.h"
#include <string>
#include <list>
#include "USocial.h"

class User
{
    friend class USocial;
protected:
    unsigned long id;
    std::string name;
    std::list<unsigned long> friends;
    std::list<Post*> posts;
    std::list<Message*> recievedMessages;
    USocial* us;
    
    User();
    ~User();

public:
    unsigned long getId();
    std::string getName();
    void addFriend(User*);
    void removeFriend(User*);
    void post(std::string);
    void post(std::string, Media*);
    std::list<Post*> getPosts();
    void viewFriendsPosts();
    void recieveMessage(Message*);
    virtual void sendMessage(User*, Message*);
    void viewReceivedMessages();
    void setUsocial(USocial*);
};

class BusinessUser: public User {
    friend class USocial;
    void sendMessage(User*, Message*);
};

#endif /* User_h */
