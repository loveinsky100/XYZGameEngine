//
//  GLESMath.hpp
//  GameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef GLESMath_hpp
#define GLESMath_hpp

#include <OpenGLES/ES2/gl.h>

namespace XYZGame
{
    typedef struct _Matrix3
    {
        GLfloat   m[3][3];
    } Matrix3;
    
    typedef struct
    {
        GLfloat   m[4][4];
    } Matrix4;
    
    typedef struct _Vec3
    {
        GLfloat x;
        GLfloat y;
        GLfloat z;
        _Vec3() {}
        _Vec3(GLfloat x, GLfloat y, GLfloat z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }
    } Vec3;
    
    typedef struct _Vec4
    {
        GLfloat x;
        GLfloat y;
        GLfloat z;
        GLfloat w;
        _Vec4() {}
        _Vec4(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
        {
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }
    } Vec4;
    
    typedef struct _Color
    {
        GLfloat r;
        GLfloat g;
        GLfloat b;
        GLfloat a;
        
        _Color(){}
        _Color(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
        {
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
        }
    } Color;
    
    class GLESMath
    {
    public:
        
        static unsigned int NextPot(unsigned int n);
        
        static void CopyMatrix4(Matrix4 * target, const Matrix4 * src);
        
        static void Matrix4ToMatrix3(Matrix3 * target, const Matrix4 * src);
        
        static void Scale(Matrix4 *result, GLfloat sx, GLfloat sy, GLfloat sz);
        
        static void Translate(Matrix4 *result, GLfloat tx, GLfloat ty, GLfloat tz);
        
        static void Rotate(Matrix4 *result, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
        
        static void MatrixMultiply(Matrix4 *result, const Matrix4 *srcA, const Matrix4 *srcB);
        
        static void MatrixLoadIdentity(Matrix4 *result);
        
        static void Perspective(Matrix4 *result, float fovy, float aspect, float nearZ, float farZ);
        
        static void Ortho(Matrix4 *result, float left, float right, float bottom, float top, float nearZ, float farZ);
        
        static void Frustum(Matrix4 *result, float left, float right, float bottom, float top, float nearZ, float farZ);
    };
}

#endif
