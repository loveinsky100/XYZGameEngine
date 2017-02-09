//
//  HashNode.hpp
//  XYZGameEngine
//
//  Created by Leo on 2017/2/9.
//  Copyright © 2017年 Leo. All rights reserved.
//

#ifndef HashNode_hpp
#define HashNode_hpp

#include <stdio.h>
#include "Object.hpp"

namespace XYZGame
{
    class HashNode : public Object
    {
        AssignProperty(long, hash, Hash);
        RetainProperty(Object *, value, Value);
        RetainProperty(HashNode *, next, Next);
        
    public:
        CreateInit(HashNode);
    
    protected:
        virtual void dealloc();
        
    };
}

#endif /* HashNode_hpp */
