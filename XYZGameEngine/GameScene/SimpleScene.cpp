//
//  SimpleScene.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/12/5.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "SimpleScene.hpp"
#include "File.hpp"

bool SimpleScene::init()
{
    Scene::init();
    this->setCube(Shape::create());
    this->getShape()->addShape(this->getCube());
    
    this->getCube()->getTransform()->setScale(Vec3(0.2, 0.2, 0.2));
    this->getCube()->getTransform()->setPosition(Vec3(-100, -100, 0));
    
    // FileTest
    Data *data = File::read("Info.plist", FilePathType_Bundle);

    printf("%s \n", data->getBytes());
    printf("\n %ld \n\n", data->hashCode());
    return true;
}

void SimpleScene::update(long deltaTime)
{
    Vec3 rotation = this->getShape()->getTransform()->getRotation();
    rotation.y += deltaTime / 25.f * 2;
    this->getShape()->getTransform()->setRotation(rotation);
    this->getShape()->getTransform()->setScale(Vec3(0.2, 0.2, 0.2));
    
    rotation.y -= deltaTime / 25.f * 4;
    this->getCube()->getTransform()->setRotation(rotation);
}
