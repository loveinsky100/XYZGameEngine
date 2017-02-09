//
//  File.cpp
//  XYZGameEngine
//
//  Created by Leo on 2017/2/7.
//  Copyright © 2017年 Leo. All rights reserved.
//

#include "File.hpp"
#include <mm_malloc.h>

using namespace XYZGame;

static string BundlePath;
static string DocumentPath;
static string CachePath;

void File::dealloc()
{
    Object::dealloc();
}

bool File::init()
{
    return Object::init();
}

void File::setPath(string path, FilePathType type)
{
    path += "/";
    switch (type)
    {
        case FilePathType_Bundle:
        {
            BundlePath = path;
        }
            break;
            
        case FilePathType_Document:
        {
            DocumentPath = path;
        }
            break;
            
        case FilePathType_Cache:
        {
            CachePath = path;
        }
            break;
    }
}

string File::getPath(FilePathType type)
{
    switch (type)
    {
        case FilePathType_Bundle:
        {
            return BundlePath;
        }
            break;
            
        case FilePathType_Document:
        {
            return DocumentPath;
        }
            break;
            
        case FilePathType_Cache:
        {
            return CachePath;
        }
            break;
    }
}

Data *File::read(string file, FilePathType type)
{
    Data *data = Data::create();
    string path = File::getPath(type) + file;
    FILE *pFile;
    long lSize;
    char *buffer;
    size_t result;
    
    pFile = fopen (path.c_str(), "rb");
    if (pFile == NULL)
    {
        return data;
    }
    
    fseek (pFile , 0 , SEEK_END);
    lSize = ftell (pFile);
    rewind (pFile);
    
    buffer = (char *)malloc(sizeof(char) * lSize);
    if(buffer == NULL)
    {
        return data;
    }
    
    result = fread (buffer,1,lSize,pFile);
    if (result != lSize)
    {
        return data;
    }

    fclose (pFile);
    data->setBytes(buffer);
    
//    free (buffer); // 此处在data里进行释放
    return data;
}

void File::save(Data *data, string file, FilePathType type)
{
    string path = File::getPath(type) + file;
    
}

void File::deleteFile(string file, FilePathType type)
{
    string path = File::getPath(type) + file;
    
}
