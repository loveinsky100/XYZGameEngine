//
//  ArrayTest.m
//  XYZGameEngine
//
//  Created by Leo on 2016/11/29.
//  Copyright © 2016年 Leo. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "Array.hpp"
#include "TestObject.hpp"

using namespace XYZGame;

@interface ArrayTest : XCTestCase

@end

@implementation ArrayTest

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testAddRemoveObject {
    Array *array = Array::create();
    Object *object = Object::create();
    array->add(object);
    array->add(object);
    
    XCTAssert(object->getRetainCount() == 3);
    XCTAssert(array->count() == 2);
    
    array->remove(object);
    XCTAssert(object->getRetainCount() == 1);
    XCTAssert(array->count() == 0);
}

- (void)addObject:(Array *)array message:(NSString *)message
{
    TestObject *object = TestObject::create();
    object->message = (char *)[message UTF8String];
    array->add(object);
}

- (void)insetObject:(Array *)array message:(NSString *)message at:(NSInteger)index
{
    TestObject *object = TestObject::create();
    object->message = (char *)[message UTF8String];
    array->insert((int)index, object);
}

- (NSString *)print:(Array *)array
{
    NSMutableString *aString = [[NSMutableString alloc] initWithCapacity:array->count()];
    printf("----------------------------------\n");
    array->enumerate([&](Object *object, int index) {
        TestObject *tObject = (TestObject *)object;
        printf("---------- %s\n", tObject->message);
        [aString appendString:[NSString stringWithUTF8String:tObject->message]];
    });
    
    return aString;
}

- (void)testAddRemoveInsertIndexObject {
    
}

- (void)testRemoveAll {
    // This is an example of a performance test case.
    [self measureBlock:^{
        Array *array = Array::create();
        
        [self addObject:array message:@"1"];
        [self addObject:array message:@"2"];
        [self addObject:array message:@"4"];
        
        [self insetObject:array message:@"0" at:0];
        [self insetObject:array message:@"3" at:3];
        [self insetObject:array message:@"5" at:5];
        
        TestObject *object = TestObject::create();
        object->message = (char *)[@"6" UTF8String];
        array->insert(6, object);
        
        TestObject *object2 = TestObject::create();
        object2->message = (char *)[@"7" UTF8String];
        array->insert(7, object2);
        
        TestObject *object3 = TestObject::create();
        object3->message = (char *)[@"-1" UTF8String];
        array->insert(0, object3);
        
        TestObject *object4 = TestObject::create();
        object4->message = (char *)[@"-1" UTF8String];
        
        XCTAssert(array->contain(object));
        XCTAssert(array->contain(object2));
        XCTAssert(array->contain(object3));
        XCTAssert(!array->contain(object4));
        
        // -1, 0, 1, 2, 3, 4, 5, 6, 7
        XCTAssert([[self print:array] isEqualToString:@"-101234567"]);
        
        array->remove(object);
        // -1, 0, 1, 2, 3, 4, 5, 7
        XCTAssert([[self print:array] isEqualToString:@"-10123457"]);
        
        array->remove(object2);
        // -1, 0, 1, 2, 3, 4, 5
        XCTAssert([[self print:array] isEqualToString:@"-1012345"]);
        
        array->remove(object3);
        // 0, 1, 2, 3, 4, 5
        XCTAssert([[self print:array] isEqualToString:@"012345"]);
        
        array->removeAt(3);
        // 0, 1, 2, 4, 5
        XCTAssert([[self print:array] isEqualToString:@"01245"]);
        
        array->removeAt(array->count() - 1);
        // 0, 1, 2, 4
        XCTAssert([[self print:array] isEqualToString:@"0124"]);
        
        array->removeAt(3);
        // 0, 1, 2
        XCTAssert([[self print:array] isEqualToString:@"012"]);
        
        array->removeAt(0);
        // 1, 2
        XCTAssert([[self print:array] isEqualToString:@"12"]);
        
        array->removeAll();
        XCTAssert([[self print:array] isEqualToString:@""]);
    }];
}

@end
