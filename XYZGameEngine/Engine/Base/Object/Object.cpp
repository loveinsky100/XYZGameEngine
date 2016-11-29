//
//  Object.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "Object.hpp"
#include <list>
#include "ReleasePool.hpp"

using namespace XYZGame;
using namespace std;

Object::Object()
{
    this->retainCount = 1;
    this->isDestory = false;
}

Object::~Object()
{
    
}

bool Object::init()
{
    return true;
}

void Object::dealloc()
{
    
}

void Object::release()
{
    Locker l(lock);
    this -> retainCount --;
    if(this->retainCount <= 0 && !this->isDestory)
    {
        this->isDestory = true;
        delete this;
    }
}

Object *Object::autorelease()
{
    Locker l(lock);
    ReleasePool::sharedReleasePool()->addAutoRelease(this);
    return this;
}

Object *Object::retain()
{
    Locker l(lock);
    this->retainCount ++;
    return this;
}

int Object::getRetainCount()
{
    Locker l(lock);
    return this->retainCount;
}
