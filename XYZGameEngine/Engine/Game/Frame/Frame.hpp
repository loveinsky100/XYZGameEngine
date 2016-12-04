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
#include <OpenGLES/ES2/gl.h>
#include "Scene.hpp"

namespace XYZGame
{
    typedef struct _Size
    {
        GLfloat width;
        GLfloat height;
        
        _Size() {};
        _Size(GLfloat width, GLfloat height)
        {
            this->width = width;
            this->height = height;
        }
    }Size;
    
    class Frame
    {
    private:
        Size size;
        Scene *rootScene;
        
    private:
        Frame();
        void draw();
        
    public:
        
        static Frame *sharedFrame();
        Size currentSize();
        void setCurrentSize(Size size);
        
        void setRootScene(Scene *scene);
        void update();
        
    };
}

#endif /* Frame_hpp */
