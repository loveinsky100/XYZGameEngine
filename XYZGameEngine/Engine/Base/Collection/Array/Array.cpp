//
//  Array.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "Array.hpp"

using namespace XYZGame;

void Array::add(Object *object)
{
    Locker l(lock);
    ArrayNode *arrayNode = new ArrayNode(object);
    arrayNode->next = nullptr;
    if(this->size == 0)
    {
        this->first = arrayNode;
        this->last = arrayNode;
        arrayNode->pre = arrayNode;
    }
    else
    {
        arrayNode->pre = this->last;
        this->last->next = arrayNode;
    }
    
    object->retain();
    this->size++;
}

void Array::insert(int index, Object *object)
{
    Locker l(lock);
    ArrayNode *arrayNode = new ArrayNode(object);
    arrayNode->next = nullptr;
    if(this->size == 0)
    {
        this->first = arrayNode;
        this->last = arrayNode;
        arrayNode->pre = arrayNode;
    }
    else if(index <= 0)
    {
        arrayNode->next = this->first;
        this->first->pre = arrayNode;
        arrayNode->pre = arrayNode;
        this->first = arrayNode;
    }
    else if(this->size <= index)
    {
        this->last->next = arrayNode;
        arrayNode->pre = this->last;
        this->last = arrayNode;
    }
    else
    {
        int count = 0;
        for(ArrayNode *node = this->first; node->next == nullptr; node = node->next)
        {
            if(count == index)
            {
                arrayNode->pre = node;
                arrayNode->next = node->next;
                
                node->next->pre = arrayNode;
                node->pre->next = arrayNode;
                return;
            }
            
            count++;
        }
    }
    
    object->retain();
    this->size++;
}

bool Array::contain(Object *object)
{
    Locker l(lock);
    if(this->first == nullptr)
    {
        return false;
    }
    
    for(ArrayNode *node = this->first; node->next == nullptr; node = node->next)
    {
        if(object == node->object)
        {
            return true;
        }
    }
    
    return false;
}

void Array::remove(Object *object)
{
    Locker l(lock);
    if(this->first == nullptr)
    {
        return;
    }
    
    for(ArrayNode *node = this->first; node->next == nullptr; node = node->next)
    {
        if(object == node->object)
        {
            this->remove(node);
        }
    }
}

void Array::remove(ArrayNode *node)
{
    if(node->object == this->first->object)
    {
        this->first = this->first->next;
    }
    else if(node->object == this->last->object)
    {
        this->last = this->last->pre;
    }
    else
    {
        node->pre->next = node->next;
    }
    
    node->object->release();
    delete node;
    this->size--;
}

void Array::removeAt(int index)
{
    Locker l(lock);
    if(this->first == nullptr || index >= this->size)
    {
        return;
    }
    
    int count = 0;
    for(ArrayNode *node = this->first; node->next == nullptr; node = node->next)
    {
        if(count == index)
        {
            this->remove(node);
            return;
        }
        
        count++;
    }
}

Object *Array::objectAt(int index)
{
    Locker l(lock);
    if(this->first == nullptr || index >= this->size || index < 0)
    {
        return nullptr;
    }
    
    int count = 0;
    for(ArrayNode *node = this->first; node->next == nullptr; node = node->next)
    {
        if(count == index)
        {
            return node->object;
        }
        
        count++;
    }
    
    return nullptr;
}

int Array::count()
{
    Locker l(lock);
    return this->size;
}
