//
//  Scene.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "Scene.hpp"

using namespace XYZGame;

void Scene::dealloc()
{
    Object::dealloc();
    Release(gameObject);
    Release(subScenes);
}

bool Scene::init()
{
    if(Object::init())
    {
        this->setGameObject(GameObject::create());
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

    if(currentScene->getGameObject() != nullptr)
    {
        currentScene->getGameObject()->draw();
    }
}
