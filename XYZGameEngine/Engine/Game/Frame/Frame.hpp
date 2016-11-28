//
//  Frame.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef Frame_hpp
#define Frame_hpp

#include <stdio.h>
#include "GLESBuffer.hpp"

namespace XYZGame
{
    class Frame
    {
    private:
        Frame();
        GLESBuffer *buffer;
        void draw();
        
    public:
        
        static Frame *sharedFrame();
        
        void initBuffer();
        void destoryBuffer();
        void update();
    };
}

#endif /* Frame_hpp */
