//
//  EaseInputBarRecordAudioView.h
//  EaseChat
//
//  Created by XieYajie on 2019/1/29.
//  Copyright © 2019 XieYajie. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol EaseInputBarRecordAudioViewDelegate;
@interface EaseInputBarRecordAudioView : UIView

@property (nonatomic, weak) id<EaseInputBarRecordAudioViewDelegate> delegate;

- (instancetype)initWithRecordPath:(NSString *)aPath;

@end

@protocol EaseInputBarRecordAudioViewDelegate <NSObject>

@optional
- (void)chatBarRecordAudioViewStartRecord;

- (void)chatBarRecordAudioViewStopRecord:(NSString *)aPath
                              timeLength:(NSInteger)aTimeLength;

- (void)chatBarRecordAudioViewCancelRecord;

@end

NS_ASSUME_NONNULL_END
