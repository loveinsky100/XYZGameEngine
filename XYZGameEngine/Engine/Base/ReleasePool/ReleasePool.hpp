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

namespace XYZGame
{
    class Object;
    class ReleasePool
    {
    private:
        Mutex lock;
        ReleasePool();
    public:
        static ReleasePool *sharedReleasePool();
        void autoRelease();
        void destory();
        
        void addAutoRelease(Object *object);
        void addDestory(Object *object);
    };

}

#endif /* ReleasePool_hpp */
