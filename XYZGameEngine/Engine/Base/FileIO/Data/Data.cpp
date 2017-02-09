//
//  Data.cpp
//  XYZGameEngine
//
//  Created by Leo on 2017/2/9.
//  Copyright © 2017年 Leo. All rights reserved.
//

#include "Data.hpp"
#include <mm_malloc.h>

using namespace XYZGame;

void Data::dealloc()
{
    Object::dealloc();
    if(this->bytes != NULL)
    {
        free(this->bytes);
    }
}
bool Data::init()
{
    return Object::init();
}

Data *Data::createWithSize(long size)
{
    Data *object = new Data();
    if(!object -> init())
    {
        delete object;
        object = nullptr;
    }
    else
    {
        object -> bytes = (char *)malloc(sizeof(char) * size);
        object -> length = size;
        object -> autorelease();
    }
    
    return object;
}
