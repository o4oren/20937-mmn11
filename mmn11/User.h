#ifndef User_h
#define User_h

#include "Post.h"
#include "Message.h"
#include <string>
#include <list>

class USocial; // forward declaration of USocial so we can break cross declaration of User/USocial

class User
{
protected:
    unsigned long id;
    std::string name;
    std::list<unsigned long> friends;
    std::list<Post> posts;
    std::list<Message> recievedMessages;
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
    void sendMessage(User*, Message*);
    void viewReceivedMessages();
};

#endif /* User_h */
