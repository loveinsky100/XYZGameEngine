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
        RetainProtectedProperty(Array *, meshes, Meshes);
        
    private:
        void draw();
        
    public:
        CreateInit(Mesh);
        void start();
        void update();
        
    protected:
        virtual void dealloc();
        virtual Array *genGLESMeshes();
    };
}

#endif /* Mesh_hpp */
