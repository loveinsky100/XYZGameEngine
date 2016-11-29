//
//  GameObject.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "GameObject.hpp"
#include <OpenGLES/ES2/gl.h>

using namespace XYZGame;

void GameObject::dealloc()
{
    Release(this->conponents);
}

bool GameObject::init()
{
    this->conponents = Array::create();
    return true;
}

void GameObject::start()
{
    this->conponents->enumerate([&](Object *object, int index){
        Conponent *conponent = (Conponent *)object;
        conponent->start();
    });
}

void GameObject::update()
{
    glClearColor(0, 0, 0, 1);
    glClearStencil(0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    
    this->conponents->enumerate([&](Object *object, int index){
        Conponent *conponent = (Conponent *)object;
        conponent->update();
    });
}
