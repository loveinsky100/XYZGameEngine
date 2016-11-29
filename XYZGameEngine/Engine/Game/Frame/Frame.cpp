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
    this->buffer = GLESBuffer::create();
    this->buffer->retain();
}

void Frame::initBuffer()
{
    this->buffer->setupBuffer();
}

void Frame::destoryBuffer()
{
    this->buffer->destoryBuffer();
}

void Frame::update()
{
    this->draw();
    
    ReleasePool::sharedReleasePool()->autoRelease();
    ReleasePool::sharedReleasePool()->destory();
}

void Frame::draw()
{
    
}
