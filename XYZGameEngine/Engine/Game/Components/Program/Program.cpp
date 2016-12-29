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
    this->setProgram(GLESProgram::create());
    return true;
}

void Program::dealloc()
{
    Conponent::dealloc();
}

void Program::start()
{
    this->getProgram()->loadVertexShader(vertex);
    this->getProgram()->loadFragmentShader(vertex);
    this->getProgram()->link();
}

void Program::update()
{
    this->getProgram()->use();
}

