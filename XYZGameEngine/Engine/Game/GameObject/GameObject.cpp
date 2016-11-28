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

bool GameObject::init()
{
    return true;
}

void GameObject::draw()
{
    glClearColor(0, 0, 0, 1);
    glClearStencil(0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}
