//
//  GLESDraw.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/29.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "GLESDraw.hpp"

using namespace XYZGame;

void GLESDraw::dealloc()
{
    Object::dealloc();
    this->matrix->release();
}

bool GLESDraw::init()
{
    this->matrix = GLESMatrix::create();
    this->matrix->retain();
    return true;
}

void GLESDraw::setCurrentModel(Matrix4 &model)
{
    this->model = model;
}

void GLESDraw::setCurrentProjection(Matrix4 &projection)
{
    this->projection = projection;
}

void GLESDraw::setCurrentBuffer(GLESBuffer *buffer)
{
    this->buffer = buffer;
}

void GLESDraw::setCurrentProgram(GLESProgram *program)
{
    this->program = program;
    this->matrix->setCurrentProgram(this->program);
}

void GLESDraw::setCurrentMesh(Mesh *mesh)
{
    this->mesh = mesh;
}

void GLESDraw::setCurrentTexture(GLESTexture *texture)
{
    this->texture = texture;
}

void GLESDraw::draw()
{
    if(this->program != nullptr)
    {
        this->program->use();
    }
    
    this->buffer->bindFrameBuffer();
    
    this->matrix->loadModel(this->model);
    this->matrix->loadProjection(this->projection);
    
    this->mesh->render();
    
}
