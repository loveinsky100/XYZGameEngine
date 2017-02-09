//
//  Dictionary.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "Dictionary.hpp"

using namespace XYZGame;

void Dictionary::dealloc()
{
    Object::dealloc();
    Release(this->hashTable);
}

bool Dictionary::init()
{
    this->setHashTable(HashTable::create(16));
    return Object::init();
}

void Dictionary::set(Object *key, Object *value)
{
    this->getHashTable()->set(key, value);
}

Object *Dictionary::get(Object *key)
{
    return this->getHashTable()->get(key);
}

void Dictionary::remove(Object *key)
{
    this->getHashTable()->remove(key);
}

void Dictionary::removeAll()
{
    this->getHashTable()->removeAll();
}

int Dictionary::count()
{
    return this->getHashTable()->getCount();
}
