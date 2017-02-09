//
//  Dictionary.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <stdio.h>
#include "Object.hpp"
#include <string>
#include "HashTable.hpp"

using namespace std;

namespace XYZGame
{
    class Dictionary : public Object
    {
        RetainProtectedProperty(HashTable *, hashTable, HashTable)
        
    public:
        CreateInit(Dictionary);
        
        void set(Object *key, Object *value);
        Object *get(Object *key);
        void remove(Object *key);
        void removeAll();
        int count();
        
    protected:
        virtual void dealloc();
    };
}

#endif /* Dictionary_hpp */
