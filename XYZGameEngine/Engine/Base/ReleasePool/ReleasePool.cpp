//
//  ReleasePool.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "ReleasePool.hpp"
#include <list>
#include "Object.hpp"

using namespace XYZGame;
using namespace std;

static list<Object *> autoReleaseObjects;
static list<Object *> destoryObjects;

ReleasePool::ReleasePool()
{
    
}

ReleasePool *ReleasePool::sharedReleasePool()
{
    static ReleasePool *releasePool = nullptr;
    if(releasePool == nullptr)
    {
        releasePool = new ReleasePool();
    }
    
    return releasePool;
}

void ReleasePool::autoRelease()
{
    Locker l(lock);
    while (autoReleaseObjects.size() != 0)
    {
        Object *object = autoReleaseObjects.back();
        autoReleaseObjects.pop_back();
        object->release();
    }
}

void ReleasePool::destroy()
{
    Locker l(lock);
    while (destoryObjects.size() != 0)
    {
        Object *object = destoryObjects.back();
        destoryObjects.pop_back();
        delete object;
    }
}

void ReleasePool::addAutoRelease(Object *object)
{
    Locker l(lock);
    autoReleaseObjects.push_back(object);
}

void ReleasePool::addDestroy(Object *object)
{
    Locker l(lock);
    destoryObjects.push_back(object);
}
