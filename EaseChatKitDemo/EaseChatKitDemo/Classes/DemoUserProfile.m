//
//  DemoUserProfile.m
//  EaseChatKitDemo
//
//  Created by 杜洁鹏 on 2020/11/23.
//  Copyright © 2020 djp. All rights reserved.
//

#import "DemoUserProfile.h"

@implementation DemoUserProfile
{
    NSString *_easeId;
}

- (instancetype)initWithEaseId:(NSString *)easeId {
    if (self = [super init]) {
        _easeId = easeId;
    }
    
    return self;
}

- (NSString *)showName {
    return _nickName ?: _easeId;
}

- (NSString *)easeId {
    return _easeId;
}

@end
