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
#include <string>
#include <list>
#include "Locker.h"
#include "ObjectDefinition.h"

namespace XYZGame
{
    class Object
    {
    private:
        int retainCount;
        bool isDestroy;
        Mutex lock;
    
    protected:
        void _autorelease();
        void _retain();
        virtual void dealloc();
        
        friend class ReleasePool;
    public:
        Object();
        ~Object();
        
        CreateInit(Object)
        
        void release();
        int getRetainCount();
    };
}

#endif /* Object_hpp */
