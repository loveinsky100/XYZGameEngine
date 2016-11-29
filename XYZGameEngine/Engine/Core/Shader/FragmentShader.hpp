//
//  FragmentShader.h
//  XYZGameEngine
//
//  Created by Leo on 2016/11/29.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef FragmentShader_h
#define FragmentShader_h

namespace XYZGame
{
    #define STRINGIFY(A)  #A
    static const char* TextureShader_frag = STRINGIFY
    (
        precision mediump float; //设置工作精度
     
        varying vec2 vTexture;
        uniform sampler2D sTexture;
     
        void main()
        {
            //    gl_FragColor = texture2D(sTexture, vTexture);
            gl_FragColor = vec4(1, 0, 0, 1);
        }
    );
}

#endif /* FragmentShader_h */
