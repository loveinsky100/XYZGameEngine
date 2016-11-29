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
    this->meshs->release();
}

bool Mesh::init()
{
    this->meshs = Array::create();
    this->meshs->retain();
    
    return Conponent::init();
}

void Mesh::genGPUBuffer()
{
    
}

void Mesh::render()
{
    this->meshs->enumerate([&](Object *object, int index){
        GLESMesh *mesh = (GLESMesh *)object;
        mesh->load();
    });
}

GLESProgram *Mesh::sharedProgram()
{
    static GLESProgram *defaultProgram = nullptr;
    if(defaultProgram == nullptr)
    {
        defaultProgram = GLESProgram::create();
        defaultProgram->retain();
//        defaultProgram->loadVertexShader(string(TextureShader_vert));
//        defaultProgram->loadFragmentShader(TextureShader_frag);
    }
    
    return defaultProgram;
}
