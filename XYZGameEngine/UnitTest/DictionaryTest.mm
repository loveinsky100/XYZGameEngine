//
//  DictionaryTest.m
//  XYZGameEngine
//
//  Created by Leo on 2017/2/9.
//  Copyright © 2017年 Leo. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "Dictionary.hpp"
#include "TestObject.hpp"
#include "String.hpp"

using namespace XYZGame;

@interface DictionaryTest : XCTestCase

@end

@implementation DictionaryTest

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testSet
{
    String *key1 = String::create("apple");
    String *value1 = String::create("windows");
    
    String *key2 = String::create("hello");
    String *value2 = String::create("world");
    
    Dictionary *dictionary = Dictionary::create();
    
    dictionary->set(key1, value1);
    dictionary->set(key2, value2);
    
    XCTAssert(dictionary->get(key1) == value1);
    XCTAssert(dictionary->get(key2) == value2);
}

@end
