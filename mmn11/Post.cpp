//
//  Post.cpp
//  mmn11
//
//  Created by Oren Geva on 12/11/2021.
//

#include "Post.h"
#include <iostream>

Post::Post(std::string text) {
    init(text, NULL);
}

Post::Post(std::string text, Media* media) {
    init(text, media);
}

void Post::init(std::string text, Media* media) {
    this->text = text;
    this->media = media;
}

std::string Post::getText() {
    return text;
};

Media* Post::getMedia() {
    return media;
};
