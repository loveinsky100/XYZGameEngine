//
//  Transform.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/12/5.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef Transform_hpp
#define Transform_hpp

#include <stdio.h>
#include "Conponent.hpp"
#include "GLESMath.hpp"
#include "GLESMatrix.hpp"

namespace XYZGame
{
    class Transform : public Conponent
    {
        RetainProperty(GLESMatrix *, matrix, Matrix)
    public:
        Vec3 position;
        Vec3 rotation;
        Vec3 scale;
        
    public:
        CreateInit(Transform)
        virtual void start();
        virtual void update();
        
    protected:
        virtual void dealloc();
    };
}

#endif /* Transform_hpp */
