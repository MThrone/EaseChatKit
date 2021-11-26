//
//  ChatViewController.h
//  EaseChatKitDemo
//
//  Created by zhangchong on 2020/11/17.
//  Copyright © 2020 djp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <EaseChatKit/EaseChatKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface ChatViewController : UIViewController
@property (nonatomic, strong) NSString *chatter;
@property (nonatomic) AgoraChatConversationType conversationType;
@end

NS_ASSUME_NONNULL_END
