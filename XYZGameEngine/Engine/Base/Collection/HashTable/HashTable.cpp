//
//  HashTable.cpp
//  XYZGameEngine
//
//  Created by Leo on 2017/2/9.
//  Copyright © 2017年 Leo. All rights reserved.
//

#include "HashTable.hpp"
#include "HashNode.hpp"

using namespace XYZGame;

void HashTable::dealloc()
{
    Object::dealloc();
    Release(this->hashArray);
}

bool HashTable::init()
{
    return Object::init();
}

void HashTable::initArray()
{
    this->count = 0;
    this->setHashArray(Array::create());
    for (int i = 0; i < this->getSize(); i++)
    {
        HashNode *node = HashNode::create();
        node->setNext(nullptr);
        node->setHash(0);
        node->setValue(nullptr);
        this->getHashArray()->add(node);
    }
}

HashTable *HashTable::create(int size)
{
    HashTable *object = new HashTable();
    if(!object -> init())
    {
        delete object;
        object = nullptr;
    }
    else
    {
        if(size < 1)
        {
            size = 10;
        }
        
        object -> size  = size;
        object -> initArray();
        object -> autorelease();
    }
    
    return object;
}

void HashTable::set(Object *key, Object *value)
{
    int hash = key->hashCode() % this->getSize();
    HashNode *node = (HashNode *)this->getHashArray()->objectAt(hash);
    if(node->getNext() == nullptr)
    {
        HashNode *newNode = HashNode::create();
        newNode->setValue(value);
        newNode->setHash(key->hashCode());
        newNode->setNext(nullptr);
        node->setNext(newNode);
        this->count++;
        return;
    }
    
    HashNode *currentNode;
    HashNode *lastNode = node;
    
    while (node != nullptr)
    {
        lastNode = node;
        if(node->getHash() == key->hashCode())
        {
            currentNode = node;
            currentNode->setValue(value);
            return;
        }
        
        node = node->getNext();
    }
    
    HashNode *newNode = HashNode::create();
    newNode->setNext(nullptr);
    newNode->setValue(value);
    newNode->setHash(key->hashCode());
    
    lastNode->setNext(newNode);
    this->count++;
}

Object *HashTable::get(Object *key)
{
    int hash = key->hashCode() % this->getSize();
    HashNode *node = (HashNode *)this->getHashArray()->objectAt(hash);
    if(node->getNext() == nullptr)
    {
        return nullptr;
    }
    
    HashNode *lastNode = node;
    
    while (node != nullptr)
    {
        lastNode = node;
        if(node->getHash() == key->hashCode())
        {
            return node->getValue();
        }
        
        node = node->getNext();
    }
    
    return nullptr;
}

void HashTable::remove(Object *key)
{
    int hash = key->hashCode() % this->getSize();
    HashNode *node = (HashNode *)this->getHashArray()->objectAt(hash);
    if(node->getNext() == nullptr)
    {
        return;
    }
    
    HashNode *currentNode;
    HashNode *lastNode = node;
    
    while (node != nullptr)
    {
        if(node->getHash() == key->hashCode())
        {
            currentNode = node;
            break;
        }
        
        lastNode = node;
        node = node->getNext();
    }
    
    if(currentNode != nullptr &&
       lastNode != nullptr)
    {
        lastNode->setNext(currentNode->getNext());
        currentNode->release();
        this->count--;
    }
}

void HashTable::removeAll()
{
    this->initArray();
}

