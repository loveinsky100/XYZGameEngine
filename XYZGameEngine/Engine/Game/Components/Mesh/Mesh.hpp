//
//  Mesh.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#include "Conponent.hpp"
#include "GLESMesh.hpp"
#include "GLESProgram.hpp"
#include "Array.hpp"

namespace XYZGame
{
    class Mesh : public Conponent
    {
    private:
        strong Array *meshs; // GLESMesh *;
        
    public:
        CreateInit(Mesh);
        
        virtual void dealloc();
        virtual void genGPUBuffer();
        virtual void render();
        
    protected:
        virtual GLESProgram *sharedProgram();
    };
}

#endif /* Mesh_hpp */
