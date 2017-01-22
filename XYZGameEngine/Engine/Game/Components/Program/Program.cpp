//
//  Program.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/12/5.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "Program.hpp"

using namespace XYZGame;

bool Program::init()
{
    Conponent::init();
    this->setESProgram(GLESProgram::create());
    return true;
}

void Program::dealloc()
{
    Conponent::dealloc();
}

void Program::start()
{
    this->getESProgram()->loadVertexShader(vertex);
    this->getESProgram()->loadFragmentShader(fragment);
    this->getESProgram()->link();
}

void Program::update()
{
    this->getESProgram()->use();
}

