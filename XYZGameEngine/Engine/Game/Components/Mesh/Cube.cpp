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
    Mesh::dealloc();
}

Array *Cube::genGLESMeshes()
{
    Array *meshes = Array::create();
    Size screenSize = Frame::sharedFrame()->currentSize();
    GLfloat cubeWidth = 1;
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
    vertexMesh->setSize(3);
    vertexMesh->setType(GL_FLOAT);
    vertexMesh->setNormalized(GL_FALSE);
    vertexMesh->setStride(0);
    vertexMesh->setPtr(0);
    vertexMesh->setName("vPosition");

    vertexMesh->genBuffer(GL_ARRAY_BUFFER, 24 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
    meshes->add(vertexMesh);
    
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
    
    GLESMesh *drawMesh = GLESMesh::create();
    drawMesh->genBuffer(GL_ELEMENT_ARRAY_BUFFER, 36 * sizeof(GLubyte), indices, GL_STATIC_DRAW);
    drawMesh->setIsElement(GL_TRUE);
    drawMesh->setShouldDraw(GL_TRUE);
    drawMesh->setDrawType(GL_TRIANGLES);
    drawMesh->setDrawCount(36);
    drawMesh->setDrawValueType(GL_UNSIGNED_BYTE);
    drawMesh->setDrawPtr(0);
    
    meshes->add(drawMesh);
    return meshes;
}
