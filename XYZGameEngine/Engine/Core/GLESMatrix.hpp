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
    private:
        weak GLESProgram *program;
    public:
        CreateInit(GLESMatrix);
        
        void setCurrentProgram(GLESProgram *program);
        
        void loadModel(Matrix4 model);
        void loadProjection(Matrix4 projection);
    };
}

#endif /* GLESMatrix_hpp */
