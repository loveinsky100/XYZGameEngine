//
//  GLESTexture.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef GLESTexture_hpp
#define GLESTexture_hpp

#include <stdio.h>
#include "Object.hpp"
#include "GLESProgram.hpp"
#include <OpenGLES/ES2/gl.h>

namespace XYZGame
{
    class GLESTexture : public Object
    {
        AssignProperty(GLuint, textureId, TextureId);
        AssignProperty(GLESProgram *, program, Program);

    public:
        CreateInit(GLESTexture);
//        void setCurrentProgram();
        void loadTexture();
    };
}

#endif /* GLESTexture_hpp */
