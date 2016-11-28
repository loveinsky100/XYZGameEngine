//
//  GLESBuffer.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "GLESBuffer.hpp"
#include <OpenGLES/ES2/glext.h>

using namespace XYZGame;

GLESBuffer::GLESBuffer()
{
    
}

void GLESBuffer::setupBuffer()
{
    glGenRenderbuffers(1, &renderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, renderBuffer);
    
    glGenFramebuffers(1, &frameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
    
    glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                              GL_COLOR_ATTACHMENT0,
                              GL_RENDERBUFFER,
                              frameBuffer);
    
    int width, height;
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &width);
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &height);
    
    glGenRenderbuffers(1, &stencilDeepthBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, stencilDeepthBuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8_OES, width, height);
    
    glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                              GL_DEPTH_ATTACHMENT,
                              GL_RENDERBUFFER,
                              stencilDeepthBuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                              GL_STENCIL_ATTACHMENT,
                              GL_RENDERBUFFER,
                              stencilDeepthBuffer);
    
    GLenum state = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if(state == GL_FRAMEBUFFER_COMPLETE)
    {
        printf("GL_FRAMEBUFFER_COMPLETE\n");
    }
    else if(state == GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT)
    {
        printf("GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT\n");
    }
    else if(state == GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS)
    {
        printf("GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS\n");
    }
    else if(state == GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT)
    {
        printf("GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT\n");
    }
    else if(state == GL_FRAMEBUFFER_UNSUPPORTED)
    {
        printf("GL_FRAMEBUFFER_UNSUPPORTED\n");
    }
}

void GLESBuffer::destoryBuffer()
{
    glDeleteRenderbuffers(1, &renderBuffer);
    glDeleteFramebuffers(1, &frameBuffer);
    glDeleteRenderbuffers(1, &stencilDeepthBuffer);
    renderBuffer = 0;
    frameBuffer = 0;
    stencilDeepthBuffer = 0;
}
