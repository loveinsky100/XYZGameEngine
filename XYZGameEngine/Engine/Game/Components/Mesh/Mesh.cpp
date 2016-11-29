//
//  Mesh.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "Mesh.hpp"

using namespace XYZGame;

void Mesh::dealloc()
{
    Release(this->meshs);
}

bool Mesh::init()
{
    this->meshs = Array::create();
    this->meshs->retain();
    
    return Conponent::init();
}

void Mesh::start()
{
    
}

void Mesh::update()
{
    
}

void Mesh::draw()
{
    this->meshs->enumerate([&](Object *object, int index){
        GLESMesh *mesh = (GLESMesh *)object;
        mesh->bind();
        mesh->load();
    });
}

void Mesh::render()
{
    this->meshs->enumerate([&](Object *object, int index){
        GLESMesh *mesh = (GLESMesh *)object;
        mesh->load();
    });
}

void Mesh::addMesh(GLESMesh *mesh)
{
    this->meshs->add(mesh);
}

GLESProgram *Mesh::sharedProgram()
{
    static GLESProgram *defaultProgram = nullptr;
    if(defaultProgram == nullptr)
    {
        defaultProgram = GLESProgram::create();
        defaultProgram->retain();
        defaultProgram->loadVertexShader(string(TextureShader_vert));
        defaultProgram->loadFragmentShader(string(TextureShader_frag));
    }
    
    return defaultProgram;
}
