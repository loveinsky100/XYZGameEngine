//
//  GLESMath.cpp
//  GameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#include "GLESMath.hpp"
#include <stdlib.h>
#include <string>
#include <math.h>

using namespace XYZGame;

//void * memcpy(void *, const void *, size_t);
//void * memset(void *, int, size_t);

unsigned int GLESMath::NextPot(unsigned int n)
{
    n--;
    n |= n >> 1; n |= n >> 2;
    n |= n >> 4; n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

//
// Matrix math utils
//

void GLESMath::Scale(Matrix4 *result, GLfloat sx, GLfloat sy, GLfloat sz)
{
    result->m[0][0] *= sx;
    result->m[0][1] *= sx;
    result->m[0][2] *= sx;
    result->m[0][3] *= sx;
    
    result->m[1][0] *= sy;
    result->m[1][1] *= sy;
    result->m[1][2] *= sy;
    result->m[1][3] *= sy;
    
    result->m[2][0] *= sz;
    result->m[2][1] *= sz;
    result->m[2][2] *= sz;
    result->m[2][3] *= sz;
}

void GLESMath::Translate(Matrix4 *result, GLfloat tx, GLfloat ty, GLfloat tz)
{
    result->m[3][0] += (result->m[0][0] * tx + result->m[1][0] * ty + result->m[2][0] * tz);
    result->m[3][1] += (result->m[0][1] * tx + result->m[1][1] * ty + result->m[2][1] * tz);
    result->m[3][2] += (result->m[0][2] * tx + result->m[1][2] * ty + result->m[2][2] * tz);
    result->m[3][3] += (result->m[0][3] * tx + result->m[1][3] * ty + result->m[2][3] * tz);
}

void GLESMath::Rotate(Matrix4 *result, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
    GLfloat sinAngle, cosAngle;
    GLfloat mag = sqrtf(x * x + y * y + z * z);
    
    sinAngle = sinf ( angle * M_PI / 180.0f );
    cosAngle = cosf ( angle * M_PI / 180.0f );
    if ( mag > 0.0f )
    {
        GLfloat xx, yy, zz, xy, yz, zx, xs, ys, zs;
        GLfloat oneMinusCos;
        Matrix4 rotMat;
        
        x /= mag;
        y /= mag;
        z /= mag;
        
        xx = x * x;
        yy = y * y;
        zz = z * z;
        xy = x * y;
        yz = y * z;
        zx = z * x;
        xs = x * sinAngle;
        ys = y * sinAngle;
        zs = z * sinAngle;
        oneMinusCos = 1.0f - cosAngle;
        
        rotMat.m[0][0] = (oneMinusCos * xx) + cosAngle;
        rotMat.m[0][1] = (oneMinusCos * xy) - zs;
        rotMat.m[0][2] = (oneMinusCos * zx) + ys;
        rotMat.m[0][3] = 0.0F;
        
        rotMat.m[1][0] = (oneMinusCos * xy) + zs;
        rotMat.m[1][1] = (oneMinusCos * yy) + cosAngle;
        rotMat.m[1][2] = (oneMinusCos * yz) - xs;
        rotMat.m[1][3] = 0.0F;
        
        rotMat.m[2][0] = (oneMinusCos * zx) - ys;
        rotMat.m[2][1] = (oneMinusCos * yz) + xs;
        rotMat.m[2][2] = (oneMinusCos * zz) + cosAngle;
        rotMat.m[2][3] = 0.0F;
        
        rotMat.m[3][0] = 0.0F;
        rotMat.m[3][1] = 0.0F;
        rotMat.m[3][2] = 0.0F;
        rotMat.m[3][3] = 1.0F;
        
        MatrixMultiply( result, &rotMat, result );
    }
}

void GLESMath::MatrixMultiply(Matrix4 *result, const Matrix4 *srcA, const Matrix4 *srcB)
{
    Matrix4    tmp;
    int         i;
    
    for (i=0; i<4; i++)
    {
        tmp.m[i][0] =	(srcA->m[i][0] * srcB->m[0][0]) +
        (srcA->m[i][1] * srcB->m[1][0]) +
        (srcA->m[i][2] * srcB->m[2][0]) +
        (srcA->m[i][3] * srcB->m[3][0]) ;
        
        tmp.m[i][1] =	(srcA->m[i][0] * srcB->m[0][1]) +
        (srcA->m[i][1] * srcB->m[1][1]) +
        (srcA->m[i][2] * srcB->m[2][1]) +
        (srcA->m[i][3] * srcB->m[3][1]) ;
        
        tmp.m[i][2] =	(srcA->m[i][0] * srcB->m[0][2]) +
        (srcA->m[i][1] * srcB->m[1][2]) +
        (srcA->m[i][2] * srcB->m[2][2]) +
        (srcA->m[i][3] * srcB->m[3][2]) ;
        
        tmp.m[i][3] =	(srcA->m[i][0] * srcB->m[0][3]) +
        (srcA->m[i][1] * srcB->m[1][3]) +
        (srcA->m[i][2] * srcB->m[2][3]) +
        (srcA->m[i][3] * srcB->m[3][3]) ;
    }
    
    memcpy(result, &tmp, sizeof(Matrix4));
}

void GLESMath::CopyMatrix4(Matrix4 * target, const Matrix4 * src)
{
    memcpy(target, src, sizeof(Matrix4));
}

void GLESMath::Matrix4ToMatrix3(Matrix3 * t, const Matrix4 * src)
{
    t->m[0][0] = src->m[0][0];
    t->m[0][1] = src->m[0][1];
    t->m[0][2] = src->m[0][2];
    t->m[1][0] = src->m[1][0];
    t->m[1][1] = src->m[1][1];
    t->m[1][2] = src->m[1][2];
    t->m[2][0] = src->m[2][0];
    t->m[2][1] = src->m[2][1];
    t->m[2][2] = src->m[2][2];
}

void GLESMath::MatrixLoadIdentity(Matrix4 *result)
{
    memset(result, 0x0, sizeof(Matrix4));
    
    result->m[0][0] = 1.0f;
    result->m[1][1] = 1.0f;
    result->m[2][2] = 1.0f;
    result->m[3][3] = 1.0f;
}

void GLESMath::Frustum(Matrix4 *result, float left, float right, float bottom, float top, float nearZ, float farZ)
{
    float       deltaX = right - left;
    float       deltaY = top - bottom;
    float       deltaZ = farZ - nearZ;
    Matrix4    frust;
    
    if ( (nearZ <= 0.0f) || (farZ <= 0.0f) ||
        (deltaX <= 0.0f) || (deltaY <= 0.0f) || (deltaZ <= 0.0f) )
    return;
    
    frust.m[0][0] = 2.0f * nearZ / deltaX;
    frust.m[0][1] = frust.m[0][2] = frust.m[0][3] = 0.0f;
    
    frust.m[1][1] = 2.0f * nearZ / deltaY;
    frust.m[1][0] = frust.m[1][2] = frust.m[1][3] = 0.0f;
    
    frust.m[2][0] = (right + left) / deltaX;
    frust.m[2][1] = (top + bottom) / deltaY;
    frust.m[2][2] = -(nearZ + farZ) / deltaZ;
    frust.m[2][3] = -1.0f;
    
    frust.m[3][2] = -2.0f * nearZ * farZ / deltaZ;
    frust.m[3][0] = frust.m[3][1] = frust.m[3][3] = 0.0f;
    
    MatrixMultiply(result, &frust, result);
}

void GLESMath::Perspective(Matrix4 *result, float fovy, float aspect, float nearZ, float farZ)
{
    GLfloat frustumW, frustumH;
    
    frustumH = tanf( fovy / 360.0f * M_PI ) * nearZ;
    frustumW = frustumH * aspect;
    
    Frustum( result, -frustumW, frustumW, -frustumH, frustumH, nearZ, farZ );
}

void GLESMath::Ortho(Matrix4 *result, float left, float right, float bottom, float top, float nearZ, float farZ)
{
    float       deltaX = right - left;
    float       deltaY = top - bottom;
    float       deltaZ = farZ - nearZ;
    Matrix4    ortho;
    
    if ( (deltaX == 0.0f) || (deltaY == 0.0f) || (deltaZ == 0.0f) )
    return;
    
    MatrixLoadIdentity(&ortho);
    ortho.m[0][0] = 2.0f / deltaX;
    ortho.m[3][0] = -(right + left) / deltaX;
    ortho.m[1][1] = 2.0f / deltaY;
    ortho.m[3][1] = -(top + bottom) / deltaY;
    ortho.m[2][2] = -2.0f / deltaZ;
    ortho.m[3][2] = -(nearZ + farZ) / deltaZ;
    
    MatrixMultiply(result, &ortho, result);
}
