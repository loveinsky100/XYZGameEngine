//
//  Image.hpp
//  XYZGameEngine
//
//  Created by Leo on 2017/2/9.
//  Copyright © 2017年 Leo. All rights reserved.
//

#ifndef Image_hpp
#define Image_hpp

#include <stdio.h>
#include "Object.hpp"
#include "Data.hpp"

using namespace std;

namespace XYZGame
{
    class Image : public Object
    {
        AssignReadOnlyProperty(int, width, Width)
        AssignReadOnlyProperty(int, height, Height)
        
    public:
        static Image *create(string file);
        static Image *create(Data *data);
        
        virtual bool init();
        
    protected:
        virtual void dealloc();
    };
}

#endif /* Image_hpp */
