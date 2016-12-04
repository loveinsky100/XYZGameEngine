//
//  Cube.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/29.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef Cube_hpp
#define Cube_hpp

#include <stdio.h>
#include "Mesh.hpp"

namespace XYZGame
{
    class Cube : public Mesh
    {
    public:
        CreateInit(Cube);
        
    protected:
        virtual void dealloc();
        virtual Array *genGLESMeshes();
    };
}

#endif /* Cube_hpp */
