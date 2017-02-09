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
        AssignReadOnlyProperty(char *, bytes, Bytes)
        AssignReadOnlyProperty(long, length, Length)
        
    public:
        static Data *createWithSize(long size);
        virtual bool init();
        ObjectMRC(Data)
        
    protected:
        virtual void dealloc();
    };
}

#endif /* Data_hpp */
