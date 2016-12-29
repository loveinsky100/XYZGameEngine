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
    public:
        CreateInit(Scene);
        void addSubScene(Scene *scene);
        void draw();
        
    protected:
        virtual void dealloc();
        virtual void update(long deltaTime);
    };
}

#endif /* Scene_hpp */
