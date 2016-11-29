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
        
        void draw();
    public:
        CreateInit(Mesh);
        
        virtual void dealloc();
        void render();
        
        virtual void start();
        virtual void update();
    protected:
        virtual GLESProgram *sharedProgram();
        void addMesh(GLESMesh *mesh);
        
    };
}

#endif /* Mesh_hpp */
