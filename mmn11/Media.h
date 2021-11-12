//
//  Media.h
//  mmn11
//
//  Created by Oren Geva on 10/11/2021.
//

#ifndef Media_h
#define Media_h

class Media
{
public:
    virtual void display() = 0;
};

class Audio : public Media
{
public:
    void display();
};

class Video : public Media
{
public:
    void display();
};

class Photo : public Media
{
public:
    void display();
};
#endif /* Media_h */
