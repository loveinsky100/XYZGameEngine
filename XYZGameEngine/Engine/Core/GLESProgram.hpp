//
//  GLESProgram.hpp
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef GLESProgram_hpp
#define GLESProgram_hpp

#include <stdio.h>
#include <OpenGLES/ES2/gl.h>
#include "GLESShader.hpp"
#include "Object.hpp"
#include "Dictionary.hpp"

using namespace std;

namespace XYZGame
{
    class GLESProgram : public Object
    {
        AssignProtectedProperty(GLuint, programId, ProgramId)
        AssignProtectedProperty(GLuint, vertexShaderId, VertexShaderId)
        AssignProtectedProperty(GLuint, fragmentShaderId, FragmentShaderId)
        RetainProtectedProperty(Dictionary *, attributeDictionary, AttributeDictionary);
        RetainProtectedProperty(Dictionary *, uniformDictionary, UniformDictionary);
        
    private:
        GLuint loadShader(string shader, GLenum shaderType);
        
    public:
        
        CreateInit(GLESProgram);
        
        void loadVertexShader(string shader);
        void loadFragmentShader(string shader);
        
        void link();
        void use();
        
        GLuint attributeIndex(string attributeName);
        GLuint uniformIndex(string uniformName);
        
    protected:
        virtual void dealloc();
    };
}

#endif /* GLESProgram_hpp */
