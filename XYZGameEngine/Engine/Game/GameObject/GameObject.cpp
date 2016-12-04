//
//  GameObject.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "GameObject.hpp"
#include <OpenGLES/ES2/gl.h>
#include "Cube.hpp"

using namespace XYZGame;

GameObject::~GameObject()
{
    
}

void GameObject::dealloc()
{
    Release(this->conponents);
    Release(this->subGameObjects);
}

bool GameObject::init()
{
    this->addConponent(Cube::create());
    return true;
}

void GameObject::draw()
{
    this->drawGameObject();
}

void GameObject::addGameObject(GameObject *gameObject)
{
    if(this->getSubGameObjects() == nullptr)
    {
        this->setSubGameObjects(Array::create());
    }
    
    this->getSubGameObjects()->add(gameObject);
}

void GameObject::addConponent(Conponent *conponent)
{
    if(this->getConponents() == nullptr)
    {
        this->setConponents(Array::create());
    }
    
    this->getConponents()->add(conponent);
}

void GameObject::drawGameObject()
{
    if(this->conponents != nullptr)
    {
        this->conponents->enumerate([&](Object *object, int index){
            Conponent *conponent = (Conponent *)object;
            if(!this->isStart)
            {
                conponent->start();
            }
            
            conponent->update();
        });
    }

    if(this->subGameObjects != nullptr)
    {
        this->subGameObjects->enumerate([&](Object *object, int index){
            GameObject *gameObject = (GameObject *)object;
            gameObject->drawGameObject();
        });
    }
    
    this->isStart = true;
}
