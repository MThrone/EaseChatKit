//
//  EaseExtFuncViewModel.h
//  EaseChatKit
//
//  Created by 娜塔莎 on 2020/12/7.
//  Copyright © 2020 djp. All rights reserved.
//

#import <UIKit/UIKit.h>

/*!
 *  inputBar "+" ext funcrion style
 */
typedef NS_ENUM(NSInteger, EaseExtFuncStyle) {
    EaseInputBarExtFuncView = 1,  //inputBar ext funcrion view
    EasePopupView,          //viewcontroller popup view
};

NS_ASSUME_NONNULL_BEGIN

@interface EaseExtFuncViewModel : NSObject

@property (nonatomic, strong) UIColor *iconBgColor;//图标背景色
@property (nonatomic, strong) UIColor *viewBgColor;//视图背景色
@property (nonatomic, strong) UIColor *fontColor;//字体颜色
@property (nonatomic, assign) CGFloat fontSize;//字体大小
@property (nonatomic, assign) CGSize collectionViewSize;//视图尺寸
@property (nonatomic) EaseExtFuncStyle extFuncStyle;

@end

NS_ASSUME_NONNULL_END
