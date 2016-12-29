//
//  XYZGameDelegate.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/12/4.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef XYZGameDelegate_hpp
#define XYZGameDelegate_hpp

#include <stdio.h>
#include "Frame.hpp"
#include "GameDelegate.hpp"

namespace XYZGame
{
    class XYZGameDelegate : public GameDelegate
    {
        public:
        virtual void gameViewDidLoad(Frame *frame);
    };
}

#endif /* XYZGameDelegate_hpp */
