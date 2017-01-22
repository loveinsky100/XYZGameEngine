//
//  ReleasePool.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef ReleasePool_hpp
#define ReleasePool_hpp

#include <stdio.h>
#include "Locker.h"
#include <list>

using namespace std;

namespace XYZGame
{
    class Object;
    class ReleasePool
    {
    private:
        list<Object *> autoReleaseObjects;
        list<Object *> destoryObjects;
        Mutex lock;
        ReleasePool();
    public:
        static ReleasePool *sharedReleasePool();
        void autoRelease();
        void destroy();
        
        void addAutoRelease(Object *object);
        void addDestroy(Object *object);
    };

}

#endif /* ReleasePool_hpp */
