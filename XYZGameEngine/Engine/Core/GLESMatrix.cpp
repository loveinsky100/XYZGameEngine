//
//  GLESMatrix.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/29.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "GLESMatrix.hpp"

using namespace XYZGame;

bool GLESMatrix::init()
{
    return true;
}

void GLESMatrix::loadModel(Matrix4 model)
{
    if(this->program == nullptr)
    {
        return;
    }
    
    GLuint modelViewHandle = this->program->uniformIndex("modelView");
    glUniformMatrix4fv(modelViewHandle, 1, GL_FALSE, (GLfloat*)&model.m[0][0]);
}

void GLESMatrix::loadProjection(Matrix4 projection)
{
    if(this->program == nullptr)
    {
        return;
    }
    
    GLuint projectionHandle = this->program->uniformIndex("projection");
    glUniformMatrix4fv(projectionHandle, 1, GL_FALSE, (GLfloat*)&projection.m[0][0]);
}
