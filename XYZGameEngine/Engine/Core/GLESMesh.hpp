//
//  GLESMesh.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/29.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef GLESMesh_hpp
#define GLESMesh_hpp

#include <stdio.h>
#include <OpenGLES/ES2/gl.h>
#include "Object.hpp"
#include "GLESProgram.hpp"

namespace XYZGame
{
    class GLESMesh : public Object
    {
    public:
        assign GLint size;
        assign GLenum type;
        assign GLboolean normalized;
        assign GLsizei stride;
        assign GLvoid* ptr;
        
    private:
        assign GLuint buffer;
        assign string name;
        
        weak GLESProgram *program;

    public:
        CreateInit(GLESMesh);
        GLuint genBuffer(GLvoid *vertexs, GLsizeiptr size);
        
        void destoryBuffer();
        
        void setCurrentProgram(GLESProgram *program);
        
        void bind();
        void load();
    };
}

#endif /* GLESMesh_hpp */
