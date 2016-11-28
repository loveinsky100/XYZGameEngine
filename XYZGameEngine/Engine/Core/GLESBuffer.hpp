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

namespace XYZGame
{
    class GLESBuffer
    {
    private:
        GLuint renderBuffer;
        GLuint frameBuffer;
        GLuint stencilDeepthBuffer;
        
    public:
        GLESBuffer();
        
        void setupBuffer();
        void destoryBuffer();
    };
}

#endif /* GLESBuffer_hpp */
