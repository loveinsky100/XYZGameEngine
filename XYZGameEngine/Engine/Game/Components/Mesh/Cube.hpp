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
    private:
        strong GLESMesh *drawMesh;
        
    public:
        CreateInit(Cube);
        virtual void dealloc();
        virtual void start();
        virtual void update();
    };
}

#endif /* Cube_hpp */
