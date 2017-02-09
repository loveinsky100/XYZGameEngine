//
//  GLESMesh.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/29.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "GLESMesh.hpp"

using namespace XYZGame;

bool GLESMesh::init()
{
    this->buffer = 0;
    return true;
}

void GLESMesh::dealloc()
{
    Object::dealloc();
    this->destoryBuffer();
}

GLuint GLESMesh::genBuffer(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage)
{
    GLuint buffer;
    glGenBuffers(1, &buffer);
    
    glBindBuffer(target, buffer);
    glBufferData(target, size, data, usage);
    this->buffer = buffer;
    return buffer;
}

void GLESMesh::destoryBuffer()
{
    glDeleteBuffers(1, &buffer);
    this->buffer = 0;
}

void GLESMesh::draw()
{
    if(this->program == nullptr)
    {
        return;
    }
    
    this->program->use();
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer);
    if(this->isElement)
    {
        if(!this->getShouldDraw())
        {
            return;
        }
        
        glDrawElements(this->getDrawType(), this->getDrawCount(), this->getDrawValueType(), this->getDrawPtr());
    }
    else
    {
        GLuint positionId = this->program->attributeIndex(this->name);
        glVertexAttribPointer(positionId, size, type, normalized, stride, ptr);
        glEnableVertexAttribArray(positionId);
        if(!this->getShouldDraw())
        {
            return;
        }
        
        glDrawArrays(this->getDrawType(), this->getDrawFirst(), this->getDrawEnd());
    }
}

void GLESMesh::clear()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_CULL_FACE);
}

void GLESMesh:: viewPort(GLfloat width, GLfloat height)
{
    glViewport(0, 0, width, height);
}
