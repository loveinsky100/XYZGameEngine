//
//  KindOfClassTest.m
//  XYZGameEngine
//
//  Created by Leo on 2016/12/5.
//  Copyright © 2016年 Leo. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "Cube.hpp"
#import "Scene.hpp"
#import "ReleasePool.hpp"

using namespace XYZGame;

@interface KindOfClassTest : XCTestCase

@end

@implementation KindOfClassTest

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
    XCTAssert(Cube::isSubOfClass<Object>());
    
    Cube *cube = Cube::create();
    XCTAssert(cube->isKindOfClass<Object>());
    
    XCTAssert(Cube::isSubOfClass<Cube>());
    XCTAssert(!Cube::isSubOfClass<Scene>());
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
