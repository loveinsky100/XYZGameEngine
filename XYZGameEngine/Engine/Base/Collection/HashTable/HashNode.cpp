//
//  HashNode.cpp
//  XYZGameEngine
//
//  Created by Leo on 2017/2/9.
//  Copyright © 2017年 Leo. All rights reserved.
//

#include "HashNode.hpp"

using namespace XYZGame;

void HashNode::dealloc()
{
    Object::dealloc();
    Release(this->value);
    Release(this->next);
}

bool HashNode::init()
{
    return Object::init();
}
