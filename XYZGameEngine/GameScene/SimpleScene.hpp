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
    RetainProtectedProperty(Shape *, cube1, Cube1)
    RetainProtectedProperty(Shape *, cube2, Cube2)
    RetainProtectedProperty(Shape *, cube3, Cube3)
    RetainProtectedProperty(Shape *, cube4, Cube4)
    RetainProtectedProperty(Shape *, cube5, Cube5)
    RetainProtectedProperty(Shape *, cube6, Cube6)
public:
    CreateInit(SimpleScene);
    
protected:
    virtual void update(long deltaTime);
};

#endif /* SimpleScene_hpp */
