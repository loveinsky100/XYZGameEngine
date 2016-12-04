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
#import "GLESBuffer.hpp"
#import "GameDelegate.hpp"

@interface XYZGameEngineView()
@property (nonatomic, strong) CADisplayLink *displayLink;
@property (nonatomic, strong) EAGLContext *context;
@property (nonatomic, assign) GLuint renderBuffer;
@property (nonatomic, assign) GLuint frameBuffer;

@end

@implementation XYZGameEngineView
{
    XYZGame::GLESBuffer *buffer;
    XYZGame::GameDelegate *delegate;
}

+ (Class)layerClass
{
    return [CAEAGLLayer class];
}

- (instancetype)initWithFrame:(CGRect)frame
{
    if(self = [super initWithFrame:frame])
    {
        [self setupContext];
        [self useContext];
        
        self.displayLink = [CADisplayLink displayLinkWithTarget:self
                                                       selector:@selector(update)];
        
        buffer = XYZGame::GLESBuffer::create()->retain();
        delegate = new XYZGame::XYZGameDelegate();
        delegate->gameViewDidLoad(XYZGame::Frame::sharedFrame());
        
        [self.displayLink addToRunLoop:[NSRunLoop mainRunLoop]
                               forMode:NSRunLoopCommonModes];
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
    buffer->destoryBuffer();
    buffer->setupRenderBuffer();
    [self.context renderbufferStorage:GL_RENDERBUFFER
                         fromDrawable:(CAEAGLLayer *)self.layer];
    buffer->setupFrameBuffer();
    buffer->bindRenderBuffer();
    buffer->bindFrameBuffer();
}

- (void)draw
{
    glClearColor(1, 0, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, self.bounds.size.width, self.bounds.size.height);
}

- (void)commit
{
    [self.context presentRenderbuffer:GL_RENDERBUFFER];
}

- (void)update
{
    [self draw];
    XYZGame::Frame::sharedFrame()->update();
    
    [self commit];
}

@end
