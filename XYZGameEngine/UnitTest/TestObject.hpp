//
//  TestObject.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/29.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef TestObject_hpp
#define TestObject_hpp

#include <stdio.h>
#include "Object.hpp"

namespace XYZGame
{
    class TestObject : public Object
    {
    public:
        char *message;
        CreateInit(TestObject);
    };
}

#endif /* TestObject_hpp */
