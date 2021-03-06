//
//  Shape.cpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "Shape.hpp"
#include <OpenGLES/ES2/gl.h>
#include "Cube.hpp"

using namespace XYZGame;

Shape::~Shape()
{
    
}

void Shape::dealloc()
{
    Release(this->mesh);
    Release(this->subShapes);
    Release(this->transform);
}

bool Shape::init()
{
    Program *program = Program::create();
    program->setVertex(string(TextureShader_vert));
    program->setFragment(string(TextureShader_frag));
    
    this->setProgram(program);
    this->setMesh(Cube::create());
    this->setTransform(Transform::create());
    return true;
}

/**
 开始绘制
 */
void Shape::draw()
{
    this->drawShape();
}

/**
 添加一个子节点

 @param Shape 子节点
 */
void Shape::addShape(Shape *Shape)
{
    if(this->getSubShapes() == nullptr)
    {
        this->setSubShapes(Array::create());
    }
    
    this->getSubShapes()->add(Shape);
}

/**
 绘制所有的Shape，将会递归的进行绘制，在这里进行缓存顶点数据
 */
void Shape::drawShape()
{
    this->useConponent(this->program);
    this->useConponent(this->mesh);
    this->useConponent(this->transform);

    if(this->subShapes != nullptr)
    {
        this->subShapes->enumerate([&](Object *object, int index){
            Shape *shape = (Shape *)object;
            shape->drawShape();
        });
    }
    
    this->isStart = true;
}

void Shape::useConponent(Conponent *conponent)
{
    if(conponent != this->program)
    {
        conponent->setProgram(this->program);
    }
    
    if(conponent != nullptr && conponent->getEnable())
    {
        conponent->setProgram(this->getProgram());
        if(!this->isStart)
        {
            conponent->start();
        }
        
        conponent->update();
    }
}

/**
 下一次绘制的时候将会重新缓存顶点数据
 */
void Shape::setNeededDraw()
{
    this->isStart = false;
}
