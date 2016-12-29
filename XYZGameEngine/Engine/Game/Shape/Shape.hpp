//
//  Shape.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>
#include "Object.hpp"
#include "Mesh.hpp"
#include <list>
#include "Transform.hpp"

using namespace std;

namespace XYZGame
{
    class Shape : public Object
    {
        RetainProperty(Mesh *, mesh, Mesh)
        RetainProperty(Transform *, transform, Transform)
        RetainProperty(GLESProgram *, program, program)
        
        RetainReadOnlyProperty(Array *, subShapes, SubShapes);
        AssignProtectedProperty(bool, isStart, IsStart);
        
    public:
        ~Shape();
        CreateInit(Shape);
       
        void draw();
        void setNeededDraw();
        void addShape(Shape *shape);

    protected:
        virtual void dealloc();
        void drawShape();
        
    private:
        void useConponent(Conponent *conponent);
        GLESProgram *sharedProgram();
    };
}

#endif /* Shape_hpp */
