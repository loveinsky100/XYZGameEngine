//
//  Cube.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/29.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "Cube.hpp"
#include "Frame.hpp"

using namespace XYZGame;

bool Cube::init()
{
    return Mesh::init();
}

void Cube::dealloc()
{
    Release(this->drawMesh);
}

void Cube::start()
{
    Size screenSize = Frame::sharedFrame()->currentSize();
    GLfloat cubeWidth = screenSize.width / 4;
    static GLfloat vertices[] = {
        cubeWidth/ 2.f, cubeWidth / 2.f, -cubeWidth / 2.f,
        cubeWidth / 2.f, cubeWidth / 2.f, -3.f / 2.f * cubeWidth,
        
        -1.f / 2.f * cubeWidth, 1.f / 2.f * cubeWidth, -1.f / 2.f * cubeWidth,
        -1.f / 2.f * cubeWidth, 1.f / 2.f * cubeWidth, -2.f / 2.f * cubeWidth,
        
        -1.f / 2.f * cubeWidth, -1.f / 2.f * cubeWidth, -1.f / 2.f * cubeWidth,
        -1.f / 2.f, -1.f / 2.f, -3.f / 2.f,
        
        1.f / 2.f * cubeWidth, -1.f / 2.f * cubeWidth, -1.f / 2.f * cubeWidth,
        1.f / 2.f * cubeWidth, -1.f / 2.f * cubeWidth, -3.f / 2.f * cubeWidth
    };
    
    GLESMesh *vertexMesh = GLESMesh::create();
    vertexMesh->size = 3;
    vertexMesh->type = GL_FLOAT;
    vertexMesh->normalized = GL_FALSE;
    vertexMesh->stride = 0;
    vertexMesh->ptr = 0;
    
    vertexMesh->genBuffer(GL_ARRAY_BUFFER, 24 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
    this->addMesh(vertexMesh);
    
    static GLubyte indices[] = {
        0, 1, 2,
        1, 3, 2,
        
        0, 2, 4,
        0, 4, 6,
        
        7, 6, 4,
        7, 4, 5,
        
        1, 7, 5,
        1, 5, 3,
        
        1, 0, 6,
        1, 6, 7,
        
        3, 4, 2,
        3, 5, 4
    };
    
    this->drawMesh = GLESMesh::create();
    this->drawMesh->retain();
    this->drawMesh->genBuffer(GL_ELEMENT_ARRAY_BUFFER, 36 * sizeof(GLubyte), indices, GL_STATIC_DRAW);
}

void Cube::update()
{
    Mesh::update();
    this->drawMesh->bind();
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, 0);
}
