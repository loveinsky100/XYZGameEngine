//
//  String.cpp
//  XYZGameEngine
//
//  Created by Leo on 2017/2/9.
//  Copyright © 2017年 Leo. All rights reserved.
//

#include "String.hpp"

using namespace XYZGame;

void String::dealloc()
{
    Object::dealloc();
}

bool String::init()
{
    return Object::init();
}

String *String::create(string value)
{
    String *object = new String();
    if(!object -> init())
    {
        delete object;
        object = nullptr;
    }
    else
    {
        object -> value  = value;
        object -> autorelease();
    }
    
    return object;
}

void String::append(String *aString)
{
    this->append(aString->getValue());
}

void String::append(string aString)
{
    this->value += aString;
}

long String::hashCode()
{
    long hash = 0;
    if (hash == 0 && this->value.length() > 0)
    {
        char *val = (char *)this->getValue().c_str();
        for (int i = 0; i < this->value.length(); i++)
        {
            hash = 31 * hash + val[i];
        }
    }
    
    return hash;
}
