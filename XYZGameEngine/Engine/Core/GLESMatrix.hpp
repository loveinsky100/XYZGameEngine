//
//  GLESMatrix.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/29.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef GLESMatrix_hpp
#define GLESMatrix_hpp

#include <stdio.h>
#include "Object.hpp"
#include "GLESProgram.hpp"
#include "GLESMath.hpp"

namespace XYZGame
{
    class GLESMatrix : public Object
    {
        AssignWriteOnlyProperty(GLESProgram *, program, CurrentProgram)

    public:
        CreateInit(GLESMatrix);
        
        void loadModel(Matrix4 model);
        void loadProjection(Matrix4 projection);
    };
}

#endif /* GLESMatrix_hpp */
