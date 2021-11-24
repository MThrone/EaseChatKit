//
//  EaseChatViewControllerDelegate.h
//  EaseChatKit
//
//  Created by zhangchong on 2020/11/25.
//

#import <UIKit/UIKit.h>
#import "EaseUserProfile.h"
#import "EaseMessageModel.h"
#import "EaseExtMenuModel.h"

NS_ASSUME_NONNULL_BEGIN

//Chat controller callback
@protocol EaseChatViewControllerDelegate <NSObject>

@optional

/* cell callback */

/**
 * Return user profile
 *
 * @param   huanxinID        huanxin ID
 *
 */
- (id<EaseUserProfile>)userProfile:(NSString *)huanxinID;

/**
 * Avatar click event
 *
 * @param   userData        The profile of the user pointed to by the currently clicked avatar
 *
 */
- (void)avatarDidSelected:(id<EaseUserProfile>)userData;

/**
 * Avatar long press event
 *
 * @param   userData        The current long-pressed Avatar points to the user profile
 *
 */
- (void)avatarDidLongPress:(id<EaseUserProfile>)userData;

/**
 * Group notification receipt details
 *
 * @param   message        Current group notification message
 * @param   groupId        ID of the group to which the current message belongs
 *
 */
- (void)groupMessageReadReceiptDetail:(AgoraChatMessage *)message groupId:(NSString*)groupId;

/**
 * Custom cell
 */
- (UITableViewCell *)cellForItem:(UITableView *)tableView messageModel:(EaseMessageModel *)messageModel;

/**
 * 当前所长按的 自定义cell 的扩展区数据模型组
 *
 * @param   defaultLongPressItems       默认长按扩展区功能数据模型组      （默认共有：复制，删除，撤回（发送消息时间距当前时间小于2分钟））
 * @param   customCell                               当前长按的自定义cell
 *
 */
- (NSMutableArray<EaseExtMenuModel *> *)customCellLongPressExtMenuItemArray:(NSMutableArray<EaseExtMenuModel*>*)defaultLongPressItems customCell:(UITableViewCell*)customCell;


/*输入区回调*/

/**
 * EaseChatKit发送消息前回调
 *
 * @param   aMessage      将要发送的消息
 *
 */
- (AgoraChatMessage *)willSendMessage:(AgoraChatMessage *)aMessage;

/**
 * 发送消息完成回调
 *
 * @param   message       发送完成的消息
 * @param   error         发送消息结果
 *
 */
-(void)didSendMessage:(AgoraChatMessage *)message error:(AgoraChatError *)error;

/**
 * 当前会话输入扩展区数据模型组
 *
 * @param   defaultInputBarItems        默认功能数据模型组   （默认有序：相册，相机，位置，文件）
 * @param   conversationType                 当前会话类型：单聊，群聊，聊天室
 *
 */
- (NSMutableArray<EaseExtMenuModel *> *)inputBarExtMenuItemArray:(NSMutableArray<EaseExtMenuModel*>*)defaultInputBarItems conversationType:(AgoraChatConversationType)conversationType;
/**
 * 输入区键盘输入变化回调  例：@群成员
 */
- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;

/**
 对方正在输入
*/
- (void)beginTyping;

/**
 对方结束输入
*/
- (void)endTyping;


/* 消息事件回调 */

/**
 * 消息点击事件 （返回是否需要执行默认点击事件） 默认 YES
 *
 * @param   message         当前点击的消息
 * @param   userData        当前点击的消息携带的用户资料
 *
 */
- (BOOL)didSelectMessageItem:(AgoraChatMessage *)message userProfile:(id<EaseUserProfile>)userData;

/**
 * 当前所长按消息的扩展区数据模型组
 *
 * @param   defaultLongPressItems       默认长按扩展区功能数据模型组  （默认共有：复制，删除， 撤回）
 * @param   message                     当前长按的消息
 *
 */
- (NSMutableArray<EaseExtMenuModel *> *)messageLongPressExtMenuItemArray:(NSMutableArray<EaseExtMenuModel*>*)defaultLongPressItems message:(AgoraChatMessage*)message;


/* 页面下拉加载回调 */

/**
 * 下拉加载更多消息回调 
 *
 * @param   firstMessageId          第一条消息 id
 * @param   messageList             当前消息列表
 *
 */
- (void)loadMoreMessageData:(NSString *)firstMessageId currentMessageList:(NSArray<AgoraChatMessage *> *)messageList;

@end

NS_ASSUME_NONNULL_END
