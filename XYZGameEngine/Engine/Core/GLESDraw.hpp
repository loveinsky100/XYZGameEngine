//
//  GLESDraw.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/29.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef GLESDraw_hpp
#define GLESDraw_hpp

#include <stdio.h>
#include "Object.hpp"
#include "GLESProgram.hpp"
#include "Mesh.hpp"
#include "GLESTexture.hpp"
#include "GLESMath.hpp"
#include "GLESMatrix.hpp"
#include "GLESBuffer.hpp"

namespace XYZGame
{
    class GLESDraw : public Object
    {
    private:
        weak Matrix4 model;
        weak Matrix4 projection;
        
        weak GLESBuffer *buffer;
        weak GLESProgram *program;
        weak Mesh *mesh;
        weak GLESTexture *texture;
        
    private:
        strong GLESMatrix *matrix;
        
    public:
        CreateInit(GLESDraw);
        
        virtual void dealloc();
        
        void setCurrentModel(Matrix4 &model);
        void setCurrentProjection(Matrix4 &projection);
        
        void setCurrentBuffer(GLESBuffer *buffer);
        void setCurrentProgram(GLESProgram *program);
        void setCurrentMesh(Mesh *mesh);
        void setCurrentTexture(GLESTexture *texture);
        
        void draw();
    };
}

#endif /* GLESDraw_hpp */
