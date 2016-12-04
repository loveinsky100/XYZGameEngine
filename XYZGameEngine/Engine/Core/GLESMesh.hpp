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
        // 分类element必须设置参数
        AssignWriteOnlyProperty(GLint, size, Size);
        AssignWriteOnlyProperty(GLenum, type, Type);
        AssignWriteOnlyProperty(GLboolean, normalized, Normalized);
        AssignWriteOnlyProperty(GLsizei, stride, Stride);
        AssignWriteOnlyProperty(GLvoid *, ptr, Ptr);

        AssignReadOnlyProperty(GLuint, buffer, Buffer);
        AssignWriteOnlyProperty(string, name, Name);
        AssignWriteOnlyProperty(GLESProgram *, program, Program);
        
        // 绘制，如果不绘制不需要赋值，或者为false，默认为false
        AssignWriteOnlyProperty(GLboolean, isElement, IsElement);
        AssignProperty(GLboolean, shouldDraw, ShouldDraw);
        AssignWriteOnlyProperty(GLenum, drawType, DrawType);
        
        // element必须设置参数
        AssignWriteOnlyProperty(GLuint, drawCount, DrawCount);
        AssignWriteOnlyProperty(GLenum, drawValueType, DrawValueType);
        AssignWriteOnlyProperty(GLvoid *, drawPtr, DrawPtr);
        
        // 非element的draw
        AssignWriteOnlyProperty(GLuint, drawFirst, DrawFirst);
        AssignWriteOnlyProperty(GLsizei, drawEnd, DrawEnd);
        
    public:
        CreateInit(GLESMesh);
        GLuint genBuffer(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
        
        void destoryBuffer();
        
        void setCurrentProgram(GLESProgram *program);
        
        void draw();
    };
}

#endif /* GLESMesh_hpp */
