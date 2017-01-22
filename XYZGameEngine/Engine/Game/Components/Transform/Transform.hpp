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
        RetainProtectedProperty(GLESMatrix *, matrix, Matrix)
        AssignProperty(Vec3, position, Position)
        AssignProperty(Vec3, rotation, Rotation)
        AssignProperty(Vec3, scale, Scale)

    public:
        CreateInit(Transform)
        virtual void start();
        virtual void update();
        
    protected:
        virtual void dealloc();
    };
}

#endif /* Transform_hpp */
