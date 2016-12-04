//
//  Frame.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "Frame.hpp"
#include "ReleasePool.hpp"

using namespace XYZGame;

Frame *Frame::sharedFrame()
{
    static Frame *shardFrame = nullptr;
    if(shardFrame == nullptr)
    {
        shardFrame = new Frame();
    }
    
    return shardFrame;
}

Frame::Frame()
{
    this->size = Size(1, 1);
}

Size Frame::currentSize()
{
    return this->size;
}

void Frame::setCurrentSize(Size size)
{
    this->size = size;
}

void Frame::update()
{
    this->draw();
    
    ReleasePool::sharedReleasePool()->autoRelease();
    ReleasePool::sharedReleasePool()->destory();
}

void Frame::draw()
{
    if(this->rootScene != nullptr)
    {
        this->rootScene->draw();
    }
}

void Frame::setRootScene(Scene *scene)
{
    this->rootScene = scene->retain();
}
