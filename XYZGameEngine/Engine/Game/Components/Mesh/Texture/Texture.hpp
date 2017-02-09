//
//  Texture.hpp
//  XYZGameEngine
//
//  Created by Leo on 2017/2/6.
//  Copyright © 2017年 Leo. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <stdio.h>
#include "Object.hpp"
#include "GLESTexture.hpp"
#include "Image.hpp"

namespace XYZGame
{
    class Texture : public Object
    {
        RetainProtectedProperty(GLESTexture *, texture, Texture);
        
    public:
        CreateInit(Texture);
        void load(Image *image);
    protected:
        virtual void dealloc();
    };
}

#endif /* Texture_hpp */
