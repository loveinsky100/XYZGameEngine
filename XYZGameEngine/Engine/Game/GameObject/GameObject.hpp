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
    private:
        list<Conponent *> conponent;
        
    public:
        CreateInit(GameObject);
        void draw();
    };
}

#endif /* GameObject_hpp */
