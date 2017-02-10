//
//  Scene.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "Scene.hpp"
#include <sys/time.h>
#include "Frame.hpp"

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
        this->setFrameTime(0);
        this->setFrameCount(0);
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
    long offsetTime = now - this->drawTime;
    
    currentScene->update(offsetTime);
    
    if(!this->isLoseFrame(offsetTime))
    {
        // 掉帧的话就不更新视图了
        if(currentScene->getShape() != nullptr)
        {
            this->clear();
            currentScene->getShape()->draw();
        }
    }
    
    struct timeval tv2;
    gettimeofday(&tv2, NULL);
    this->drawTime = tv2.tv_sec * 1000 + tv2.tv_usec / 1000;
}

void Scene::clear()
{
    GLESMesh::clear();
    GLESMesh::viewPort(Frame::sharedFrame()->currentSize().width,
                       Frame::sharedFrame()->currentSize().height);
}

/**
 刷新一桢

 @param deltaTime 时间间隔单位ms
 */
void Scene::update(long deltaTime)
{
    
}

bool Scene::isLoseFrame(long frameTime)
{
    // 根据当前的frameTime判断是否存在掉帧的情况，如果掉帧了，需要跳过此次
    this->frameCount ++;
    this->frameTime += frameTime;
    
    // 每隔60桢重新计算平均帧率
    if(this->frameCount > 60)
    {
        this->frameTime = this->frameCount / this->frameCount;
        this->frameCount = 1;
    }
    
    long average = this->frameTime / this->frameCount;
    
    if((float)average / (float)frameTime > 1.5)
    {
        // 掉帧了
        return true;
    }
    else
    {
        return false;
    }
}
