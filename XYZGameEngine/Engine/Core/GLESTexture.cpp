//
//  GLESTexture.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "GLESTexture.hpp"

using namespace XYZGame;

void GLESTexture::dealloc()
{
    Object::dealloc();
    Release(this->program);
}

bool GLESTexture::init()
{
    return true;
}

void GLESTexture::gen(GLint *imageBytes, GLint width, GLint height)
{
    GLuint current_texture_id = 0;
    GLint last_texture_id = 0;
    
    glGenTextures(1, &current_texture_id);
    glGetIntegerv(GL_TEXTURE_2D, &last_texture_id);
    glBindTexture(GL_TEXTURE_2D, current_texture_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageBytes);
    glBindTexture(GL_TEXTURE_2D, last_texture_id);
    
    this->setTextureId(current_texture_id);
}

void GLESTexture::use(string name, GLenum texture)
{
    if(this->program != NULL)
    {
        glActiveTexture(texture);
        glBindTexture(GL_TEXTURE_2D, this->textureId);
        
        GLuint texture = this->program->uniformIndex(name);
        glUniform1i(texture, texture - GL_TEXTURE0);
    }
}
