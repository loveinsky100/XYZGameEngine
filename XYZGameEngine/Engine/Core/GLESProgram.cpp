//
//  GLESProgram.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "GLESProgram.hpp"
#include <stdlib.h>
#include "Number.hpp"
#include "String.hpp"

using namespace XYZGame;

bool GLESProgram::init()
{
    Object::init();
    this->setAttributeDictionary(Dictionary::create());
    this->setUniformDictionary(Dictionary::create());
    return true;
}

void GLESProgram::dealloc()
{
    Object::dealloc();
    Release(this->attributeDictionary);
    Release(this->uniformDictionary);
    glDeleteShader(this->vertexShaderId);
    glDeleteShader(this->fragmentShaderId);
    glDeleteProgram(this->programId);
}

void GLESProgram::loadVertexShader(string shader)
{
    this->vertexShaderId = this->loadShader(shader, GL_VERTEX_SHADER);
}

void GLESProgram::loadFragmentShader(string shader)
{
    this->fragmentShaderId = this->loadShader(shader, GL_FRAGMENT_SHADER);
}

GLuint GLESProgram::loadShader(string shader, GLenum shaderType)
{
    GLuint shaderId = glCreateShader(shaderType);
    const char *shaderStringUTF8 = shader.c_str();
    glShaderSource(shaderId, 1, &shaderStringUTF8, NULL);
    
    glCompileShader(shaderId);
    
    GLint compiled = 0;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compiled); // 判断是否成功
    
    if(!compiled)
    {
        GLint infoLen = 0;
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLen);
        
        if(infoLen > 1)
        {
            char *infoLog = (char *)malloc(sizeof(char) * infoLen);
            glGetShaderInfoLog (shaderId, infoLen, NULL, infoLog);
            printf("Error compiling program:\n%s\n", infoLog );
            free(infoLog);
        }
        
        glDeleteShader(shaderId);
        shaderId = 0;
    }
    
    return shaderId;
}

void GLESProgram::link()
{
    if(this->vertexShaderId == 0 || this->fragmentShaderId == 0)
    {
        return;
    }
    
    this->programId = glCreateProgram();
    glAttachShader(this->programId, this->vertexShaderId);
    glAttachShader(this->programId, this->fragmentShaderId);
    
    glLinkProgram(this->programId);
    GLint linked;
    glGetProgramiv(this->programId, GL_LINK_STATUS, &linked );
    if (!linked)
    {
        GLint infoLen = 0;
        glGetProgramiv (this->programId, GL_INFO_LOG_LENGTH, &infoLen );
        
        if (infoLen > 1)
        {
            char *infoLog = (char *)malloc(sizeof(char) * infoLen);
            glGetProgramInfoLog (this->programId, infoLen, NULL, infoLog );
            printf("Error linking program:\n%s\n", infoLog );
            
            free (infoLog );
        }
        
        glDeleteProgram(this->programId);
        this->programId = 0;
    }
}

void GLESProgram::use()
{
    if(this->programId == 0)
    {
        printf("GLESProgram use error");
        return;
    }
    
    glUseProgram(this->programId);
}

GLuint GLESProgram::attributeIndex(string attributeName)
{
    String *key = String::create(attributeName);
    Number<GLuint> *attribute = (Number<GLuint> *)this->getAttributeDictionary()->get(key);
    if(attribute == nullptr)
    {
        GLuint id = glGetAttribLocation(this->programId, attributeName.c_str());
        attribute = Number<GLuint>::create(id);
        this->getAttributeDictionary()->set(key, attribute);
        return id;
    }
    
    return attribute->getValue();
}

GLuint GLESProgram::uniformIndex(string uniformName)
{
    String *key = String::create(uniformName);
    Number<GLuint> *uniform = (Number<GLuint> *)this->getUniformDictionary()->get(key);
    if(uniform == nullptr)
    {
        GLuint id = glGetUniformLocation(this->programId, uniformName.c_str());
        uniform = Number<GLuint>::create(id);
        this->getAttributeDictionary()->set(key, uniform);
        return id;
    }
    
    return uniform->getValue();
}
