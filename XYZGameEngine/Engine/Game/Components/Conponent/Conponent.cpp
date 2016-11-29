//
//  Conponent.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "Conponent.hpp"

using namespace XYZGame;

bool Conponent::init()
{
    this->setEnable(true);
    return true;
}

void Conponent::setEnable(bool enable)
{
    this->isEnable = enable;
}

bool Conponent::enable()
{
    return this->isEnable;
}

void Conponent::start()
{
    
}

void Conponent::update()
{
    
}
