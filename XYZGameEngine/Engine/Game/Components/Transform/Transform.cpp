//
//  Transform.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/12/5.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "Transform.hpp"
#include "Program.hpp"
#include "Frame.hpp"

using namespace XYZGame;

bool Transform::init()
{
    Conponent::init();
    
    this->scale = Vec3(1, 1, 1);
    this->position = Vec3(0, 0, 0);
    this->rotation = Vec3(0, 0, 0);
    
    return true;
}

void Transform::dealloc()
{
    Conponent::dealloc();
    Release(matrix);
}

void Transform::start()
{
    this->setMatrix(GLESMatrix::create());
}

void Transform::update()
{
    Conponent::update();
    Matrix4 modelView;
    GLESMath::MatrixLoadIdentity(&modelView);
    GLESMath::Rotate(&modelView, this->rotation.x, 1, 0, 0);
    GLESMath::Rotate(&modelView, this->rotation.y, 0, 1, 0);
    GLESMath::Rotate(&modelView, this->rotation.z, 0, 0, 1);
    GLESMath::Translate(&modelView, this->position.x, this->position.y, this->position.z);
    GLESMath::Scale(&modelView, this->scale.x, this->scale.y, this->scale.z);
    this->matrix->setCurrentProgram(this->getProgram()->getESProgram());
    this->matrix->loadModel(modelView);
    
    Matrix4 projectionMatrix;
    GLESMath::MatrixLoadIdentity(&projectionMatrix);
    
    GLfloat width = Frame::sharedFrame()->currentSize().width;
    GLfloat height = Frame::sharedFrame()->currentSize().height;
    
    GLESMath::Ortho(&projectionMatrix,
                    -width / 2,
                    width / 2,
                    -height / 2,
                    height / 2,
                    -height / 2,
                    height / 2);
    
    this->matrix->loadProjection(projectionMatrix);
}
