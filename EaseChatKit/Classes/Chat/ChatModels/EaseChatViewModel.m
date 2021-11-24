//
//  EaseChatViewModel.m
//  EaseChatKit
//
//  Created by zhangchong on 2020/11/17.
//

#import "EaseChatViewModel.h"
#import "UIImage+EaseUI.h"
#import "UIColor+EaseUI.h"

@implementation EaseChatViewModel

- (instancetype)init
{
    self = [super init];
    if (self) {
        _chatViewBgColor = [UIColor colorWithRed:255/255 green:255/255 blue:255/255 alpha:1];
        _inputBarBgColor = [UIColor colorWithWhite:1.0 alpha:0.8];
        _extFuncModel = [[EaseExtFuncViewModel alloc]init];
        _msgTimeItemBgColor = [UIColor whiteColor];
        _msgTimeItemFont = [UIFont fontWithName:@"PingFang SC" size:12.0];
        _msgTimeItemFontColor = [UIColor colorWithHexString:@"#999999"];
        _receiveBubbleBgImage = [UIImage easeUIImageNamed:@"msg_bg_recv"];
        _sendBubbleBgImage = [UIImage easeUIImageNamed:@"msg_bg_send"];
        BubbleCornerRadius right = {16, 16, 16, 4};
        BubbleCornerRadius left = {16, 16, 4, 16};
        _rightAlignmentCornerRadius = right;
        _leftAlignmentCornerRadius = left;
        _bubbleBgEdgeInset = UIEdgeInsetsMake(16, 16, 16, 16);
        _oneselfFontColor = [UIColor whiteColor];
        _otherFontColor = [UIColor blackColor];
        _contentFontSize = 16.f;
        _inputBarStyle = EaseInputBarStyleAll;
        _avatarStyle = Circular;
        _avatarCornerRadius = 0;
        _displayOtherAvatar = YES;
        _displayOtherName = YES;
        _displayOneselfName = YES;
        _displayOneselfAvatar = YES;
    }
    return self;
}

- (void)setChatViewBgColor:(UIColor *)chatViewBgColor
{
    if (chatViewBgColor) {
        _chatViewBgColor = chatViewBgColor;
    }
}

- (void)setInputBarBgColor:(UIColor *)inputBarBgColor
{
    _inputBarBgColor = inputBarBgColor;
}

- (void)setExtFuncModel:(EaseExtFuncViewModel *)extFuncModel
{
    if (extFuncModel) {
        _extFuncModel = extFuncModel;
    }
}

- (void)setMsgTimeItemBgColor:(UIColor *)msgTimeItemBgColor
{
    if (msgTimeItemBgColor) {
        _msgTimeItemBgColor = msgTimeItemBgColor;
    }
}

- (void)setMsgTimeItemFontColor:(UIColor *)msgTimeItemFontColor
{
    if (msgTimeItemFontColor) {
        _msgTimeItemFontColor = msgTimeItemFontColor;
    }
}

- (void)setreceiveBubbleBgImage:(UIImage *)receiveBubbleBgImage
{
    if (receiveBubbleBgImage) {
        _receiveBubbleBgImage = receiveBubbleBgImage;
    } else {
        _receiveBubbleBgImage = [UIImage easeUIImageNamed:@""];
    }
}

- (void)setsendBubbleBgImage:(UIImage *)sendBubbleBgImage
{
    if (sendBubbleBgImage) {
        _sendBubbleBgImage = sendBubbleBgImage;
    } else {
        _sendBubbleBgImage = [UIImage easeUIImageNamed:@"“"];
    }
}

- (void)setBubbleBgEdgeInset:(UIEdgeInsets)bubbleBgEdgeInset
{
    _bubbleBgEdgeInset = bubbleBgEdgeInset;
}

- (void)setOneselfFontColor:(UIColor *)oneselfFontColor
{
    if (oneselfFontColor) {
        _oneselfFontColor = oneselfFontColor;
    }
}

- (void)setOtherFontColor:(UIColor *)otherFontColor
{
    if (otherFontColor) {
        _otherFontColor = otherFontColor;
    }
}

- (void)setContentFontSize:(CGFloat)contentFontSize
{
    if (contentFontSize > 0) {
        _contentFontSize = contentFontSize;
    }
}

- (void)setInputBarStyle:(EaseInputBarStyle)inputBarStyle
{
    if (inputBarStyle >= 1 && inputBarStyle <= 5) {
        _inputBarStyle = inputBarStyle;
    }
}

- (void)setAvatarStyle:(EaseChatAvatarStyle)avatarStyle
{
    if (avatarStyle >= 1 && avatarStyle <= 3) {
        _avatarStyle = avatarStyle;
    }
}

- (void)setAvatarCornerRadius:(CGFloat)avatarCornerRadius
{
    if (avatarCornerRadius > 0) {
        _avatarCornerRadius = avatarCornerRadius;
    }
}

@end
