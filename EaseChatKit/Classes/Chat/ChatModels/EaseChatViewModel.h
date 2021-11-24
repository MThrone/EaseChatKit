//
//  EaseChatViewModel.h
//  EaseChatKit
//
//  Created by zhangchong on 2020/11/17.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "EaseChatEnums.h"
#import "EaseExtFuncViewModel.h"

/*!
 *  Input view type
 */
typedef NS_ENUM(NSInteger, EaseInputBarStyle) {
    EaseInputBarStyleAll = 1,          //All functions
    EaseInputBarStyleNoAudio,          //No Audio
    EaseInputBarStyleNoEmoji,          //No Emoji
    EaseInputBarStyleNoAudioAndEmoji,  //No Audio And Emoji
    EaseInputBarStyleOnlyText,         //Only Text
};

/*!
 *  Group chat message alignment
 */
typedef NS_ENUM(NSInteger, EaseAlignmentStyle) {
    EaseAlignmentNormal = 1,     //Left Right alignment
    EaseAlignmentlLeft,          //The left alignment
};

typedef struct BubbleCornerRadius {
    float topLeft;
    float topRight;
    float bottomLeft;
    float bottomRight;
} BubbleCornerRadius;

NS_ASSUME_NONNULL_BEGIN

@interface EaseChatViewModel : NSObject

// Chat view background color
@property (nonatomic, strong) UIColor *chatViewBgColor;

// Timeline background color
@property (nonatomic, strong) UIColor *msgTimeItemBgColor;

// Timeline font
@property (nonatomic, strong) UIFont *msgTimeItemFont;

// Timeline font color
@property (nonatomic, strong) UIColor *msgTimeItemFontColor;

// Bubble background image of received message
@property (nonatomic, strong) UIImage *receiveBubbleBgImage;

// Bubble background image of sent message
@property (nonatomic, strong) UIImage *sendBubbleBgImage;

// Right align image/video/attachment message bubble cornerRadius
@property (nonatomic) BubbleCornerRadius rightAlignmentCornerRadius;

// Left align image/video/attachment message bubble cornerRadius
@property (nonatomic) BubbleCornerRadius leftAlignmentCornerRadius;

// Message bubble background protected area
@property (nonatomic) UIEdgeInsets bubbleBgEdgeInset;

// Oneself message font color
@property (nonatomic, strong) UIColor *oneselfFontColor;

// Other message font Color
@property (nonatomic, strong) UIColor *otherFontColor;

// Text message font size
@property (nonatomic) CGFloat contentFontSize;

// Input viwe background color and input view gradient color mutually exclusive. display background color first
@property (nonatomic, strong) UIColor *inputBarBgColor;

// Input view extends functional data model
@property (nonatomic) EaseExtFuncViewModel *extFuncModel;

// Input view type
@property (nonatomic) EaseInputBarStyle inputBarStyle;

// Display oneself avatar
@property (nonatomic) BOOL displayOneselfAvatar;

// Display other avatar
@property (nonatomic) BOOL displayOtherAvatar;

// Display oneself name
@property (nonatomic) BOOL displayOneselfName;

// Display other name
@property (nonatomic) BOOL displayOtherName;

// Avatar style
@property (nonatomic) EaseChatAvatarStyle avatarStyle;

// Avatar cornerRadius Default: 0 (Only avatar type RoundedCorner)
@property (nonatomic) CGFloat avatarCornerRadius;

// Chat view message alignment (Only group chat can be set)
@property (nonatomic) EaseAlignmentStyle msgAlignmentStyle;

@end

NS_ASSUME_NONNULL_END
