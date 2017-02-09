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
        AssignReadOnlyProperty(GLuint, textureId, TextureId);
        RetainWriteOnlyProperty(GLESProgram *, program, CurrentProgram)
//        AssignWriteOnlyProperty(GLboolean, mipMap, MipMap);
        
    public:
        CreateInit(GLESTexture);
        void gen(GLint *imageBytes, GLint width, GLint height);
        void use(string name, GLenum texture);
        
    protected:
        virtual void dealloc();
    };
}

#endif /* GLESTexture_hpp */
