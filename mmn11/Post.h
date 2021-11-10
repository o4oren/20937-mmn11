//
//  Post.h
//  mmn11
//
//  Created by Oren Geva on 10/11/2021.
//

#ifndef Post_h
#define Post_h

#include <string>
#include "Media.h"

class Post
{
private:
    std::string text;
    Media* media;
public:
    void post(std::string);
    void post(std::string, Media* media);
    std::string getString();
    Media* getMedia();
};

#endif /* Post_h */
