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

using namespace std;

namespace XYZGame
{
    typedef struct _DictionaryNode
    {
        Object *data;
        _DictionaryNode *next;
    }DictionaryNode;
    
    class Dictionary : public Object
    {
        
    };
}

#endif /* Dictionary_hpp */
