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
    
    this->setCube1(Shape::create());
    this->getShape()->addShape(this->getCube1());
    this->setCube2(Shape::create());
    this->getShape()->addShape(this->getCube2());
    this->setCube3(Shape::create());
    this->getShape()->addShape(this->getCube3());
    this->setCube4(Shape::create());
    this->getShape()->addShape(this->getCube4());
    this->setCube5(Shape::create());
    this->getShape()->addShape(this->getCube5());
    this->setCube6(Shape::create());
    this->getShape()->addShape(this->getCube6());
    
    this->getCube()->getTransform()->scale = Vec3(0.2, 0.2, 0.2);
    this->getCube()->getTransform()->position = Vec3(-0.8, -0.8, 0);
    
    this->getCube1()->getTransform()->scale = Vec3(0.05, 0.2, 0.2);
    this->getCube1()->getTransform()->position = Vec3(-0.2, -0.2, 0);
    this->getCube2()->getTransform()->scale = Vec3(0.05, 0.2, 0.2);
    this->getCube2()->getTransform()->position = Vec3(-0.4, -0.4, 0);
    this->getCube3()->getTransform()->scale = Vec3(0.2, 0.5, 0.2);
    this->getCube3()->getTransform()->position = Vec3(-0.5, -0.1, 0);
    this->getCube4()->getTransform()->scale = Vec3(0.1, 0.1, 0.2);
    this->getCube4()->getTransform()->position = Vec3(-0.8, -0.4, 0);
    this->getCube5()->getTransform()->scale = Vec3(0.05, 0.1, 0.2);
    this->getCube5()->getTransform()->position = Vec3(-0.8, -0.8, 0);
    this->getCube6()->getTransform()->scale = Vec3(0.2, 0.05, 0.2);
    this->getCube6()->getTransform()->position = Vec3(-0.3, -0.3, 0);
    
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
    this->getCube1()->getTransform()->rotation = rotation;
    this->getCube2()->getTransform()->rotation = rotation;
    this->getCube3()->getTransform()->rotation = rotation;
    this->getCube4()->getTransform()->rotation = rotation;
    this->getCube5()->getTransform()->rotation = rotation;
    this->getCube6()->getTransform()->rotation = rotation;
    
    printf("delta : %ld \n", deltaTime);
}
