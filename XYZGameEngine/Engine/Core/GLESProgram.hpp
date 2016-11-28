//
//  GLESProgram.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef GLESProgram_hpp
#define GLESProgram_hpp

#include <stdio.h>
#include <functional>
#include <string>
#include <OpenGLES/ES2/gl.h>
#include "GLESShader.h"

using namespace std;

namespace XYZGame
{
    class GLESProgram
    {
    private:
        GLuint programId;
        GLuint vertexShaderId;
        GLuint fragmentShaderId;
        
        void loadShader(string shader, GLenum shaderType);
    public:
        void loadVertexShader(string shader);
        void loadFragmentShader(string shader);
        
        void link();
        void use();
        
        GLuint attributeIndex(string attributeName);
        GLuint uniformIndex(string uniformName);
    };
}

#endif /* GLESProgram_hpp */
