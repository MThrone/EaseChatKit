//
//  UIImage+EaseUI.m
//  EaseChatKit
//
//  Created by 杜洁鹏 on 2020/11/15.
//

#import "UIImage+EaseUI.h"
#import <objc/runtime.h>

@implementation UIImage (EaseUI)
+ (UIImage *)easeUIImageNamed:(NSString *)name {
    NSString *path = [[NSBundle mainBundle] pathForResource:@"EaseChatKit" ofType:@"bundle"];
    NSString *imagePath = [path stringByAppendingPathComponent:[NSString stringWithFormat:@"%@.png",name]];
    return [UIImage imageWithContentsOfFile:imagePath];
}
@end
