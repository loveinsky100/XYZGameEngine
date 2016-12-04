//
//  GameDelegate.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/12/4.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "GameDelegate.hpp"
#include "Scene.hpp"

using namespace XYZGame;

void XYZGameDelegate::gameViewDidLoad(Frame *frame)
{
    frame->setRootScene(Scene::create());
}
