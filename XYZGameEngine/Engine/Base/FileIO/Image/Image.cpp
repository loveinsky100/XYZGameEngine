//
//  Image.cpp
//  XYZGameEngine
//
//  Created by Leo on 2017/2/9.
//  Copyright © 2017年 Leo. All rights reserved.
//

#include "Image.hpp"
#include "File.hpp"
#include "png.h"

using namespace XYZGame;

bool Image::init()
{
    return Object::init();
}

void Image::dealloc()
{
    Object::dealloc();
}

Image *Image::create(string file)
{
    return Image::create(File::read(file, FilePathType_Bundle));
}

Image *Image::create(Data *data)
{
    return nullptr;
}
