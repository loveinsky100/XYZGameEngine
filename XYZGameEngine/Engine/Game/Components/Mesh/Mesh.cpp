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
    Release(this->meshes);
}

bool Mesh::init()
{
    return Conponent::init();
}

void Mesh::start()
{
    this->setMeshes(this->genGLESMeshes());
}

void Mesh::update()
{
    this->draw();
}

Array * Mesh::genGLESMeshes()
{
    return Array::create()->autorelease();
}

void Mesh::draw()
{
    this->meshes->enumerate([&](Object *object, int index){
        GLESMesh *mesh = (GLESMesh *)object;
        mesh->setProgram(this->sharedProgram());
        mesh->draw();
    });
}

GLESProgram *Mesh::sharedProgram()
{
    static GLESProgram *defaultProgram = nullptr;
    if(defaultProgram == nullptr)
    {
        defaultProgram = GLESProgram::create()->retain();
        defaultProgram->loadVertexShader(string(TextureShader_vert));
        defaultProgram->loadFragmentShader(string(TextureShader_frag));
        defaultProgram->link();
    }
    
    return defaultProgram;
}
