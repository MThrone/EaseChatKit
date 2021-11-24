//
//  EaseChatInputBarEmoticonView.h
//  EaseChat
//
//  Created by XieYajie on 2019/1/30.
//  Copyright © 2019 XieYajie. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "EaseEmoticon.h"

NS_ASSUME_NONNULL_BEGIN

@protocol EaseChatInputBarEmoticonViewDelegate;
@interface EaseChatInputBarEmoticonView : UIView

@property (nonatomic, weak) id<EaseChatInputBarEmoticonViewDelegate> delegate;
@property (nonatomic, readonly) CGFloat viewHeight;

- (instancetype)initWithViewHeight:(CGFloat)viewHeight;
- (void)textDidChange:(BOOL)isEditing;
@end


@protocol EaseChatInputBarEmoticonViewDelegate <NSObject>

@optional

- (void)didSelectedEmoticon:(EaseEmoticonModel *)aModel;

- (BOOL)didSelectedTextDetele;

- (void)didChatBarEmoticonViewSendAction;

@end

NS_ASSUME_NONNULL_END
