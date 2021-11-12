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
    void init(std::string, Media* media);
public:
    Post(std::string);
    Post(std::string, Media* media);
    std::string getText();
    Media* getMedia();
};

#endif /* Post_h */
