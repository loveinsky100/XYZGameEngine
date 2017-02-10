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
#import "File.hpp"
#import "GLESBuffer.hpp"
#import "XYZGameDelegate.hpp"

using namespace XYZGame;

@interface XYZGameEngineView()
@property (nonatomic, strong) CADisplayLink *displayLink;
@property (nonatomic, strong) EAGLContext *context;
@end

@implementation XYZGameEngineView
{
    GLESBuffer *buffer;
    GameDelegate *delegate;
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
        
        File::setPath([[NSBundle mainBundle].bundlePath UTF8String], FilePathType_Bundle);
        
        NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
        NSString *documentsDirectory = [paths objectAtIndex:0];
        File::setPath([documentsDirectory UTF8String], FilePathType_Document);
        
        NSArray *caches = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES);
        NSString *cache = [caches objectAtIndex:0];
        File::setPath([cache UTF8String], FilePathType_Cache);
        
        self.displayLink = [CADisplayLink displayLinkWithTarget:self
                                                       selector:@selector(update)];

        buffer = GLESBuffer::create()->retain();
        delegate = new XYZGameDelegate();
        delegate->gameViewDidLoad(Frame::sharedFrame());
        
        [self.displayLink addToRunLoop:[NSRunLoop mainRunLoop]
                               forMode:NSDefaultRunLoopMode];
    }
    
    return self;
}

- (void)setupContext
{
    self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
    [self.context setMultiThreaded:YES];
}

- (void)useContext
{
    [EAGLContext setCurrentContext:self.context];
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    Frame::sharedFrame()->setCurrentSize(XYZGame::Size(self.bounds.size.width, self.bounds.size.height));
    buffer->destoryBuffer();
    buffer->setupRenderBuffer();
    [self.context renderbufferStorage:GL_RENDERBUFFER
                         fromDrawable:(CAEAGLLayer *)self.layer];
    buffer->setupFrameBuffer();
    buffer->bindRenderBuffer();
    buffer->bindFrameBuffer();
}

- (void)commit
{
    [self.context presentRenderbuffer:GL_RENDERBUFFER];
}

- (void)update
{
    Frame::sharedFrame()->update();
    [self commit];
}

@end
