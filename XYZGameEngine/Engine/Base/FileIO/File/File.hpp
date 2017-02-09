//
//  File.hpp
//  XYZGameEngine
//
//  Created by Leo on 2017/2/7.
//  Copyright © 2017年 Leo. All rights reserved.
//

#ifndef FileManager_hpp
#define FileManager_hpp

#include <stdio.h>
#include "Object.hpp"
#include "Data.hpp"

using namespace std;

namespace XYZGame
{
    typedef enum _FilePathType
    {
        FilePathType_Bundle,
        FilePathType_Document,
        FilePathType_Cache
        
    }FilePathType;
    
    class File : public Object
    {
    public:
        CreateInit(File);
        
        static void setPath(string path, FilePathType type);
        static string getPath(FilePathType type);
        
        static Data *read(string file, FilePathType type);
        static void save(Data *data, string file, FilePathType type);
        static void deleteFile(string file, FilePathType type);
        
    protected:
        
        virtual void dealloc();
    };
}

#endif /* FileManager_hpp */
