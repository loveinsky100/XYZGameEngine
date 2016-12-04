//
//  GameObject.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "Object.hpp"
#include "Mesh.hpp"
#include <list>
#include "Conponent.hpp"

using namespace std;

namespace XYZGame
{
    class GameObject : public Object
    {
        RetainProperty(Array *, conponents, Conponents)
        RetainReadOnlyProperty(Array *, subGameObjects, SubGameObjects);
        
        AssignProtectedProperty(bool, isStart, IsStart);
        
    public:
        ~GameObject();
        CreateInit(GameObject);
       
        void draw();
        
        void addConponent(Conponent *conponent);
        void addGameObject(GameObject *gameObject);

    protected:
        virtual void dealloc();
        void drawGameObject();
    };
}

#endif /* GameObject_hpp */
