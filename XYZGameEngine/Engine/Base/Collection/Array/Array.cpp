//
//  Array.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "Array.hpp"

using namespace XYZGame;

bool Array::init()
{
    Object::init();
    this->first = nullptr;
    this->last = nullptr;
    
    return true;
}

void Array::add(Object *object)
{
    Locker l(lock);
    ArrayNode *arrayNode = new ArrayNode(object);
    arrayNode->next = nullptr;
    if(this->size == 0)
    {
        this->first = arrayNode;
        arrayNode->pre = arrayNode;
    }
    else
    {
        arrayNode->pre = this->last;
        this->last->next = arrayNode;
    }
    
    this->last = arrayNode;
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
        for(ArrayNode *node = this->first; node != nullptr; node = node->next)
        {
            if(count == index)
            {
                node->pre->next = arrayNode;
                arrayNode->pre = node->pre;
                node->pre = arrayNode;
                arrayNode->next = node;
                
                break;
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
    
    for(ArrayNode *node = this->first; node != nullptr; node = node->next)
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
    
    ArrayNode *node = this->first;
    while (node != nullptr)
    {
        ArrayNode *nextNode = node -> next;
        if(object == node->object)
        {
            this->remove(node);
        }
        
        node = nextNode;
    }
}

void Array::remove(ArrayNode *node)
{
    if(node->object == this->first->object)
    {
        this->first = this->first->next;
        if(this->first != nullptr)
        {
            this->first->pre = this->first;
        }
        else
        {
            this->last = nullptr;
        }
    }
    else if(node->object == this->last->object)
    {
        this->last = this->last->pre;
        this->last->next = nullptr;
    }
    else
    {
        node->next->pre = node->pre;
        node->pre->next = node->next;
    }
    
    node->object->release();
    delete node;
    this->size--;
}

void Array::removeAt(int index)
{
    Locker l(lock);
    if(this->first == nullptr || index >= this->size || index < 0)
    {
        return;
    }
    
    int count = 0;
    ArrayNode *node = this->first;
    while (node != nullptr)
    {
        ArrayNode *nextNode = node -> next;
        if(count == index)
        {
            this->remove(node);
            return;
        }
        
        node = nextNode;
        count++;
    }
}

void Array::removeAll()
{
    Locker l(lock);
    if(this->size == 0)
    {
        return;
    }
    
    ArrayNode *node = this->first;
    while (node != nullptr)
    {
        ArrayNode *nextNode = node -> next;
        this->remove(node);
        
        node = nextNode;
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
    for(ArrayNode *node = this->first; node != nullptr; node = node->next)
    {
        if(count == index)
        {
            return node->object;
        }
        
        count++;
    }
    
    return nullptr;
}

void Array::enumerate(ArrayEnunmerateFunc func)
{
    Locker l(lock);
    int count = 0;
    ArrayNode *node = this->first;
    while (node != nullptr)
    {
        ArrayNode *nextNode = node -> next;
        
        func(node->object, count);
        
        node = nextNode;
        count++;
    }
}

int Array::count()
{
    Locker l(lock);
    return this->size;
}
