#include "User.h"
#include <algorithm>
#include <iostream>
#include <exception>

User::User() {
    // no implementation
}

User::~User() {
    // destroy posts
    for(auto&& post : posts) {
      delete post;
    }
}

unsigned long User::getId() { 
    return id;
}

std::string User::getName() { 
    return name;
}

void User::addFriend(User * user) {
    friends.push_back(user->id);
}

void User::removeFriend(User * user) {
    auto it = find(friends.begin(), friends.end(), user->id);
    if(it != friends.end()) {
        friends.remove(user->id);
    }
}

void User::post(std::string text) {
    Post* post = new Post(text);
    posts.push_back(post);
}

void User::post(std::string text, Media* media) {
    Post* post = new Post(text, media);
    posts.push_back(post);
}

std::list<Post *> User::getPosts() { 
    return posts;
}

void User::viewFriendsPosts() {
    std::cout << name << " viewing posts by friends:" << std::endl;
    for (auto const& friendId : friends) {
        auto myFriend = us->getUserById(friendId);
        std::cout << myFriend->name << " posted:" << std::endl;
        for (auto const& post : myFriend->posts) {
            std::cout << post->getText() << std::endl;
            if(post->getMedia() != NULL) {
                post->getMedia()->display();
            }
        }
    }
    std::cout << "=============" << std::endl;
}

void User::recieveMessage(Message* message) {
    recievedMessages.push_back(message);
}

void User::sendMessage(User* other, Message* message) {
    auto it = find(friends.begin(), friends.end(), other->id);
    if(it != friends.end()) {
        other->recieveMessage(message);
    } else {
        throw std::runtime_error("You tried sending a message to a user who is not your friend!");
    }
}

void BusinessUser::sendMessage(User* other, Message* message) {
    other->recieveMessage(message);
}

void User::viewReceivedMessages() {
    std::cout << name << " viewing recieved messagess:" << std::endl;
    for (auto const& message : recievedMessages) {
        std::cout << message->getText() << std::endl;
    }
    std::cout << "=============" << std::endl;
}

void User::setUsocial(USocial* us) {
    this->us = us;
}

