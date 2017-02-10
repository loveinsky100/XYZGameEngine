//
//  Scene.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>
#include "Shape.hpp"
#include "Array.hpp"

namespace XYZGame
{
    class Scene : public Object
    {
        RetainReadOnlyProperty(Shape *, shape, Shape)
        RetainReadOnlyProperty(Array *, subScenes, SubScenes);
        AssignReadOnlyProperty(long, drawTime, DrawTime)
        AssignProtectedProperty(long, frameTime, FrameTime) // 当前花费的时间
        AssignProtectedProperty(int, frameCount, FrameCount) // 记录总共有多少桢
        
    public:
        CreateInit(Scene);
        void addSubScene(Scene *scene);
        void draw();
        
    protected:
        virtual void clear();
        virtual void dealloc();
        virtual void update(long deltaTime);
        
    private:
        bool isLoseFrame(long frameTime);
    };
}

#endif /* Scene_hpp */
