//
//  GameDelegate.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/12/4.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef GameDelegate_hpp
#define GameDelegate_hpp

#include <stdio.h>
#include "Frame.hpp"

namespace XYZGame
{
    class GameDelegate
    {
    public:
        virtual void gameViewDidLoad(Frame *frame) = 0;
    };
    
    class XYZGameDelegate : public GameDelegate
    {
        public:
        virtual void gameViewDidLoad(Frame *frame);
    };
}

#endif /* GameDelegate_hpp */
