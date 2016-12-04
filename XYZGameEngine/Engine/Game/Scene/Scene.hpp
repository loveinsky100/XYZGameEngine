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
#include "GameObject.hpp"
#include "Array.hpp"

namespace XYZGame
{
    class Scene : public Object
    {
        RetainReadOnlyProperty(GameObject *, gameObject, GameObject)
        RetainReadOnlyProperty(Array *, subScenes, SubScenes);
        
    public:
        
        CreateInit(Scene);
        void addSubScene(Scene *scene);
        
        void draw();
        
    protected:
        virtual void dealloc();
    };
}

#endif /* Scene_hpp */
