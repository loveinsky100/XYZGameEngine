//
//  Texture.cpp
//  XYZGameEngine
//
//  Created by Leo on 2017/2/6.
//  Copyright © 2017年 Leo. All rights reserved.
//

#include "Texture.hpp"

using namespace XYZGame;

void Texture::dealloc()
{
    Object::dealloc();
    Release(this->texture);
}

bool Texture::init()
{
    if(Object::init())
    {
        this->setTexture(GLESTexture::create());
        return false;
    }
    
    return true;
}

void Texture::load(Image *image)
{
    
}
