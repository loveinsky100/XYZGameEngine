//
//  Object.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include <functional>
#include "Locker.h"

#define CreateInit(ObjectClass) \
virtual bool init(); \
static ObjectClass *create() \
{ \
    ObjectClass *object = new ObjectClass(); \
    if(!object -> init()) \
    { \
        delete object; \
        object = nullptr; \
    } \
    else \
    { \
        object -> autoRelease(); \
    } \
     \
    return object; \
}

namespace XYZGame
{
    class Object
    {
    private:
        int retainCount;
        bool isDestory;
        Mutex lock;
        
    public:
        Object();
        ~Object();
        
        CreateInit(Object)
        
        void release();
        Object *autoRelease();
        Object *retain();
        int getRetainCount();
    };
}

#endif /* Object_hpp */
