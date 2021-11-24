//
//  EaseInputBar.h
//  EaseChat
//
//  Updated by zhangchong on 2020/06/05.
//  Copyright © 2019 XieYajie. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "EaseChatInputBarEmoticonView.h"
#import "EaseInputBarRecordAudioView.h"
#import "EaseExtFunctionView.h"
#import "EaseChatViewModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol EaseInputBarDelegate;
@interface EaseInputBar : UIView

@property (nonatomic, copy) NSString *text;

@property (nonatomic, weak) id<EaseInputBarDelegate> delegate;
@property (nonatomic, strong) EaseInputBarRecordAudioView *recordAudioView;
@property (nonatomic, strong) EaseChatInputBarEmoticonView *moreEmoticonView;
@property (nonatomic, strong) EaseExtFunctionView *extFunctionView;

- (instancetype)initWithViewModel:(EaseChatViewModel *)viewModel;

- (void)setGradientBackgroundWithColors:(NSArray<UIColor *> *_Nullable)colors locations:(NSArray<NSNumber *> *_Nullable)locations startPoint:(CGPoint)startPoint endPoint:(CGPoint)endPoint;

- (void)clearInputViewText;

- (void)inputViewAppendText:(NSString *)aText;

- (BOOL)deleteTailText;

- (void)clearMoreViewAndSelectedButton;

@end


@protocol EaseInputBarDelegate <NSObject>

@optional

- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;

- (void)inputViewDidChange:(UITextView *)textView;

- (void)inputBarDidShowToolbarAction;

- (void)inputBarSendMsgAction:(NSString *)text;

- (void)didSelectExtFuncPopupView;

@end

NS_ASSUME_NONNULL_END
