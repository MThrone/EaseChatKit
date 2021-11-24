//
//  EaseExtFuncViewModel.h
//  EaseChatKit
//
//  Created by zhangchong on 2020/12/7.
//  Copyright © 2020 djp. All rights reserved.
//

#import <UIKit/UIKit.h>

/*!
 *  inputBar "+" ext function style
 */
typedef NS_ENUM(NSInteger, EaseExtFuncStyle) {
    EaseInputBarExtFuncView = 1,  //inputBar ext funcrion view
    EasePopupView,                //viewcontroller popup view
};

NS_ASSUME_NONNULL_BEGIN

@interface EaseExtFuncViewModel : NSObject

// Icon background color
@property (nonatomic, strong) UIColor *iconBgColor;

// View background color
@property (nonatomic, strong) UIColor *viewBgColor;

// Font color
@property (nonatomic, strong) UIColor *fontColor;

// Font size
@property (nonatomic, assign) CGFloat fontSize;

// View size
@property (nonatomic, assign) CGSize collectionViewSize;

// Ext function style
@property (nonatomic) EaseExtFuncStyle extFuncStyle;

@end

NS_ASSUME_NONNULL_END
