//
//  Number.hpp
//  XYZGameEngine
//
//  Created by Leo on 2017/2/9.
//  Copyright © 2017年 Leo. All rights reserved.
//

#ifndef Number_hpp
#define Number_hpp

#include <stdio.h>
#include "Object.hpp"

namespace XYZGame
{
    template <class TYPE>
    class Number : public Object
    {
        AssignReadOnlyProperty(TYPE, value, Value)
        
    public:
        static Number<TYPE> *create(TYPE value)
        {
            Number<TYPE> *object = new Number<TYPE>();
            if(!object -> init())
            {
                delete object;
                object = nullptr;
            }
            else
            {
                object -> setValue(value);
                object -> autorelease();
            }
            
            return object;
        }
        
        virtual bool init()
        {
            return Object::init();
        }
        
        ObjectMRC(Number)
        
    protected:
        virtual void dealloc()
        {
            Object::dealloc();
        }
    };
}

#endif /* Number_hpp */
