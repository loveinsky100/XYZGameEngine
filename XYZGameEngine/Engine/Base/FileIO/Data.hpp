//
//  Data.hpp
//  XYZGameEngine
//
//  Created by Leo on 2017/2/9.
//  Copyright © 2017年 Leo. All rights reserved.
//

#ifndef Data_hpp
#define Data_hpp

#include <stdio.h>
#include "Object.hpp"

namespace XYZGame
{
    class Data : public Object
    {
        AssignProperty(char *, bytes, Bytes)
        
    public:
        CreateInit(Data);
        
    protected:
        virtual void dealloc();
    };
}

#endif /* Data_hpp */
