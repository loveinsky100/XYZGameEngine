//
//  SimpleScene.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/12/5.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "SimpleScene.hpp"

bool SimpleScene::init()
{
    Scene::init();
    this->setCube(Shape::create());
    this->getShape()->addShape(this->getCube());
    
    this->getCube()->getTransform()->scale = Vec3(0.2, 0.2, 0.2);
    this->getCube()->getTransform()->position = Vec3(-0.8, -0.8, 0);
    
    return true;
}

void SimpleScene::update(long deltaTime)
{
    Vec3 rotation = this->getShape()->getTransform()->rotation;
    rotation.y += deltaTime / 25.f * 2;
    this->getShape()->getTransform()->rotation = rotation;
    this->getShape()->getTransform()->scale = Vec3(0.2, 0.2, 0.2);
    
    rotation.y -= deltaTime / 25.f * 4;
    this->getCube()->getTransform()->rotation = rotation;

    printf("delta : %ld \n", deltaTime);
}
