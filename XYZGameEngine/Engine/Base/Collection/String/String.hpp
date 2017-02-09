//
//  String.hpp
//  XYZGameEngine
//
//  Created by Leo on 2017/2/9.
//  Copyright © 2017年 Leo. All rights reserved.
//

#ifndef String_hpp
#define String_hpp

#include <stdio.h>
#include "Object.hpp"

using namespace std;

namespace XYZGame
{
    class String : public Object
    {
        AssignReadOnlyProperty(string, value, Value)
        
    public:
        static String *create(string value);
        
        virtual bool init();
        ObjectMRC(String)
        
        void append(String *aString);
        void append(string aString);
        
    protected:
        virtual void dealloc();
        virtual long hashCode();
    };
}

#endif /* String_hpp */
