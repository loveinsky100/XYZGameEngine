//
//  XYZGameEngineView.m
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#import "XYZGameEngineView.h"
#import <OpenGLES/ES2/gl.h>
#import "Frame.hpp"

@interface XYZGameEngineView()
@property (nonatomic, strong) CADisplayLink *displayLink;
@property (nonatomic, strong) EAGLContext *context;
@property (nonatomic, assign) GLuint renderBuffer;
@property (nonatomic, assign) GLuint frameBuffer;

@end

@implementation XYZGameEngineView

+ (Class)layerClass
{
    return [CAEAGLLayer class];
}

- (void)dealloc
{
    
}

- (instancetype)initWithFrame:(CGRect)frame
{
    if(self = [super initWithFrame:frame])
    {
        [self setupContext];
        [self useContext];
        
        self.displayLink = [CADisplayLink displayLinkWithTarget:self
                                                       selector:@selector(update)];
    }
    
    return self;
}

- (void)setupContext
{
    self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
}

- (void)useContext
{
    [EAGLContext setCurrentContext:self.context];
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    XYZGame::Frame::sharedFrame()->setCurrentSize(XYZGame::Size(self.bounds.size.width, self.bounds.size.height));
}

- (void)draw
{
    glClearColor(1, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}

- (void)commit
{
    [self.context presentRenderbuffer:GL_RENDERBUFFER];
}

- (void)update
{
    XYZGame::Frame::sharedFrame()->update();
}

@end
