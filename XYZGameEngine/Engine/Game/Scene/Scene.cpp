//
//  Scene.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "Scene.hpp"
#include <sys/time.h>

using namespace XYZGame;

void Scene::dealloc()
{
    Object::dealloc();
    Release(shape);
    Release(subScenes);
}

bool Scene::init()
{
    if(Object::init())
    {
        this->setShape(Shape::create());
        return true;
    }
    
    return false;
}

void Scene::addSubScene(Scene *scene)
{
    if(this->getSubScenes() == nullptr)
    {
        this->setSubScenes(Array::create());
    }
    
    this->getSubScenes()->add(scene);
}

void Scene::draw()
{
    Scene *currentScene = this;
    if(this->getSubScenes() != nullptr && this->getSubScenes()->count() != 0)
    {
        currentScene = (Scene *)this->getSubScenes()->lastObject();
    }

    if(this->drawTime == 0)
    {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        this->drawTime = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    }
    
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long now = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    currentScene->update(now - this->drawTime);
  
    struct timeval tv2;
    gettimeofday(&tv2, NULL);
    this->drawTime = tv2.tv_sec * 1000 + tv2.tv_usec / 1000;
    if(currentScene->getShape() != nullptr)
    {
        currentScene->getShape()->draw();
    }
}

/**
 刷新一桢

 @param deltaTime 时间间隔单位ms
 */
void Scene::update(long deltaTime)
{
    
}
