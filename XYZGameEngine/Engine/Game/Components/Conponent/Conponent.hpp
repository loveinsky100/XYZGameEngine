//
//  Conponent.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef Conponent_hpp
#define Conponent_hpp

#include <stdio.h>
#include "Object.hpp"
#include "GLESProgram.hpp"

namespace XYZGame
{
    class Program;
    class Conponent : public Object
    {
        AssignWriteOnlyProperty(Program *, program, Program);
        AssignProperty(bool, enable, Enable);
        
    public:
        CreateInit(Conponent);
        
        virtual void start();
        virtual void update();
    };
}

#endif /* Conponent_hpp */
