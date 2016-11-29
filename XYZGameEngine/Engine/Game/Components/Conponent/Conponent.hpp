//
//  Conponent.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef Conponent_hpp
#define Conponent_hpp

#include <stdio.h>
#include "Object.hpp"

namespace XYZGame
{
    class Conponent : public Object
    {
    private:
        bool isEnable;
        
    public:
        CreateInit(Conponent);
        
        void setEnable(bool enable);
        bool enable();
        
        virtual void update();
    };
}

#endif /* Conponent_hpp */
