//
//  GLESBuffer.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef GLESBuffer_hpp
#define GLESBuffer_hpp

#include <stdio.h>
#include <OpenGLES/ES2/gl.h>
#include "Object.hpp"

namespace XYZGame
{
    class GLESBuffer : public Object
    {
        AssignProtectedProperty(GLuint, renderBuffer, RenderBuffer);
        AssignProtectedProperty(GLuint, frameBuffer, FrameBuffer);
        AssignProtectedProperty(GLuint, stencilDeepthBuffer, StencilDeepthBuffer);
        
    public:
        GLESBuffer();
        CreateInit(GLESBuffer);
        
        void setupRenderBuffer();
        void setupFrameBuffer();
        void destoryBuffer();
        
        void bindRenderBuffer();
        void bindFrameBuffer();
    };
}

#endif /* GLESBuffer_hpp */
