//
//  SimpleScene.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/12/5.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef SimpleScene_hpp
#define SimpleScene_hpp

#include <stdio.h>
#include "Scene.hpp"

using namespace XYZGame;

class SimpleScene : public Scene
{
    RetainProtectedProperty(Shape *, cube, Cube)

public:
    CreateInit(SimpleScene);
    
protected:
    virtual void update(long deltaTime);
};

#endif /* SimpleScene_hpp */
