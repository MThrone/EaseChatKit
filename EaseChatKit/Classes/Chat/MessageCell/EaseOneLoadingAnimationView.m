//
//  OneLoadingAnimation.m
//  OneLoadingAnimationStep1
//
//  Created by thatsoul on 15/11/15.
//  Copyright © 2015年 chenms.m2. All rights reserved.
//

#import "EaseOneLoadingAnimationView.h"
#import "EaseLoadingCALayer.h"

static CGFloat kRadius = 9;
static CGFloat kLineWidth = 2;
static CGFloat kStep1Duration = 3.0;

@interface EaseOneLoadingAnimationView ()
{
    NSTimer *_timer;
}
@property (nonatomic) EaseLoadingCALayer *arcToCircleLayer;
@end

@implementation EaseOneLoadingAnimationView

- (instancetype)initWithRadius:(CGFloat)radius
{
    self = [super init];
    if (self) {
        kRadius = radius;
    }
    return self;
}

- (void)awakeFromNib {
    [super awakeFromNib];
}

#pragma mark - public
- (void)startAnimation {
    //self.arcToCircleLayer = [EaseLoadingCALayer layer];
    
    [self startTimer];
}

#pragma mark - animation
- (void)reset {
    [self.arcToCircleLayer removeFromSuperlayer];
    self.arcToCircleLayer = nil;
}

- (void)doStep {
    self.arcToCircleLayer = [EaseLoadingCALayer layer];
    self.arcToCircleLayer.contentsScale = [UIScreen mainScreen].scale;
    [self.layer addSublayer:self.arcToCircleLayer];

    self.arcToCircleLayer.bounds = CGRectMake(0, 0, kRadius * 2 + kLineWidth, kRadius * 2 + kLineWidth);
    self.arcToCircleLayer.position = CGPointMake(10, 10);

    // animation
    self.arcToCircleLayer.progress = 1; // end status

    CABasicAnimation *animation = [CABasicAnimation animationWithKeyPath:@"progress"];
    animation.duration = kStep1Duration;
    animation.fromValue = @0.0;
    animation.toValue = @1.0;
    [self.arcToCircleLayer addAnimation:animation forKey:nil];
}

- (void)startTimer {
    [self stopTimer];
    _timer = [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(startAnimate) userInfo:nil repeats:YES];
    [_timer fire];
}

- (void)startAnimate
{
    [self reset];
    [self doStep];
}

- (void)stopAnimate
{
    [self.layer removeAllAnimations];
    [self.arcToCircleLayer removeAllAnimations];
    [self reset];
    [self stopTimer];
}

- (void)stopTimer {
    if (_timer) {
        [_timer invalidate];
        _timer = nil;
    }
}

@end
