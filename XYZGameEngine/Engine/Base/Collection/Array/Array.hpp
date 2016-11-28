//
//  Array.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>
#include "Object.hpp"
#include "Locker.h"

namespace XYZGame
{
    typedef struct _ArrayNode
    {
    public:
        _ArrayNode *next;
        _ArrayNode *pre;
        Object *object;
        _ArrayNode(Object *object)
        {
            this->object = object;
        }
        
    }ArrayNode;
    
    class Array : Object
    {
    private:
        Mutex lock;
        ArrayNode *first;
        ArrayNode *last;
        int size;
        
        void remove(ArrayNode *node);
        
    public:
        void add(Object *object);
        void insert(int index, Object *object);
        
        bool contain(Object *object);
        
        void remove(Object *object);
        void removeAt(int index);
        
        Object *objectAt(int index);
        
        int count();
    };
}

#endif /* Array_hpp */
