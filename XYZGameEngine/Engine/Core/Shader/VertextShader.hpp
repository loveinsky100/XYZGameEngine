//
//  VertextShader.h
//  XYZGameEngine
//
//  Created by Leo on 2016/11/29.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef VertextShader_h
#define VertextShader_h

namespace XYZGame
{
    #define STRINGIFY(A)  #A
    static const char* TextureShader_vert = STRINGIFY(

    attribute vec4 vPosition;

    uniform mat4 modelView;
//    uniform mat4 projection;

    varying vec4 aColor;
                                                      
    void main(void)
    {
//        gl_Position = projection * modelView * vPosition;
        gl_Position = modelView * vPosition;
        aColor = vPosition;
    }
                                               );

}

#endif /* VertextShader_h */
