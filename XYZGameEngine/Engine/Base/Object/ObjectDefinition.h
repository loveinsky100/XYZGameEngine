//
//  ObjectDefinition.h
//  XYZGameEngine
//
//  Created by Leo on 2016/12/4.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef ObjectDefinition_h
#define ObjectDefinition_h

namespace XYZGame
{
#define CreateInit(ObjectClass) \
virtual bool init(); \
static ObjectClass *create() \
{ \
ObjectClass *object = new ObjectClass(); \
if(!object -> init()) \
{ \
delete object; \
object = nullptr; \
} \
else \
{ \
object -> autorelease(); \
} \
\
return object; \
} \
ObjectClass *autorelease() \
{ \
this->_autorelease(); \
return this; \
} \
ObjectClass *retain() \
{ \
this->_retain(); \
return this; \
}
    
    
#define Release(ptr) \
if(ptr != nullptr) \
{ \
ptr->release(); \
ptr = nullptr; \
}
}


#define AssignPropertySetter(Type, name, Name) \
void set##Name(Type name) \
{ \
this->name = name; \
}
    
#define PropertyGetter(Type, name, Name) \
Type get##Name() \
{ \
return this->name; \
}
    
#define AssignProperty(Type, name, Name) \
protected: \
Type name; \
public: \
PropertyGetter(Type, name, Name) \
AssignPropertySetter(Type, name, Name)

#define AssignProtectedProperty(Type, name, Name) \
protected: \
Type name; \
AssignPropertySetter(Type, name, Name) \
PropertyGetter(Type, name, Name)
    
#define AssignReadOnlyProperty(Type, name, Name) \
protected: \
Type name; \
AssignPropertySetter(Type, name, Name) \
public: \
PropertyGetter(Type, name, Name)
    
#define AssignWriteOnlyProperty(Type, name, Name) \
protected: \
Type name; \
PropertyGetter(Type, name, Name) \
public: \
AssignPropertySetter(Type, name, Name)
    
    
    
    
#define RetainPropertySetter(Type, name, Name) \
void set##Name(Type name) \
{ \
Release(this->name); \
this->name = name; \
this->name->retain(); \
}
    
#define RetainProperty(Type, name, Name) \
protected: \
Type name; \
public: \
PropertyGetter(Type, name, Name) \
RetainPropertySetter(Type, name, Name)
    
#define RetainReadOnlyProperty(Type, name, Name) \
protected: \
Type name; \
RetainPropertySetter(Type, name, Name) \
public: \
PropertyGetter(Type, name, Name)
    
#define RetainProtectedProperty(Type, name, Name) \
protected: \
Type name; \
RetainPropertySetter(Type, name, Name) \
PropertyGetter(Type, name, Name)
    
#define RetainWriteProperty(Type, name, Name) \
protected: \
Type name; \
PropertyGetter(Type, name, Name) \
public: \
RetainPropertySetter(Type, name, Name)

#endif /* ObjectDefinition_h */