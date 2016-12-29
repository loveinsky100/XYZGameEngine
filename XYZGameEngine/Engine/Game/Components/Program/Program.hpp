//
//  Program.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/12/5.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef Program_hpp
#define Program_hpp

#include <stdio.h>
#include "Conponent.hpp"

namespace XYZGame
{
    class Program : public Conponent
    {
        RetainProtectedProperty(GLESProgram *, program, Program)
        AssignProperty(string, vertex, Vertex)
        AssignProperty(string, fragment, Fragment)
    public:
        CreateInit(Program);
        virtual void start();
        virtual void update();

    protected:
        virtual void dealloc();
    };
}

#endif /* Program_hpp */
