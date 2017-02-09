//
//  HashTable.hpp
//  XYZGameEngine
//
//  Created by Leo on 2017/2/9.
//  Copyright © 2017年 Leo. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
#include "Object.hpp"
#include "Array.hpp"

namespace XYZGame
{
    class HashTable : public Object
    {
        AssignProtectedProperty(int, size, Size)
        RetainProtectedProperty(Array *, hashArray, HashArray)
        AssignReadOnlyProperty(int, count, Count)
        
    public:
        static HashTable *create(int size);
        
        void set(Object *key, Object *value);
        Object *get(Object *key);
        void remove(Object *key);
        void removeAll();
        
        virtual bool init();
        ObjectMRC(HashTable)
        
    protected:
        virtual void dealloc();
        void initArray();
    };
}

#endif /* HashTable_hpp */
