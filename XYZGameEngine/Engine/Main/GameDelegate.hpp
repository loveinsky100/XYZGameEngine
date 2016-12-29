//
//  GameDelegate.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/12/5.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef GameDelegate_hpp
#define GameDelegate_hpp

#include <stdio.h>

namespace XYZGame
{
    class GameDelegate
    {
    public:
        virtual void gameViewDidLoad(Frame *frame) = 0;
    };
}

#endif /* GameDelegate_hpp */
