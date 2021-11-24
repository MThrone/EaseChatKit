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
 * The extension data model group of the current custom cell
 *
 * @param   defaultLongPressItems       Default long - press extended area functional data model group     (The default values are copy, delete, and recall (the sending time is less than 2 minutes).)
 * @param   customCell                  Current long - pressed custom cell
 *
 */
- (NSMutableArray<EaseExtMenuModel *> *)customCellLongPressExtMenuItemArray:(NSMutableArray<EaseExtMenuModel*>*)defaultLongPressItems customCell:(UITableViewCell*)customCell;


/* Input view callback */

/**
 * EaseChatKit callback before sending a message
 *
 * @param   aMessage      The message to be sent
 *
 */
- (AgoraChatMessage *)willSendMessage:(AgoraChatMessage *)aMessage;

/**
 * Send a message to complete the callback
 *
 * @param   message       Sending a completed message
 * @param   error         Message sending Result
 *
 */
-(void)didSendMessage:(AgoraChatMessage *)message error:(AgoraChatError *)error;

/**
 * The current session enters the extended area data model group
 *
 * @param   defaultInputBarItems        Default function Data model group (default order: photo album, camera, attachments)
 * @param   conversationType            Current session type: single chat, group chat, chat room
 *
 */
- (NSMutableArray<EaseExtMenuModel *> *)inputBarExtMenuItemArray:(NSMutableArray<EaseExtMenuModel*>*)defaultInputBarItems conversationType:(AgoraChatConversationType)conversationType;
/**
 * Input area Keyboard input change callback example: @ group member
 */
- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;

/**
 * The other party is typing
 */
- (void)beginTyping;

/**
 * End of input
 */
- (void)endTyping;


/* Message event callback */

/**
 * Message click event (returns whether the default click event needs to be executed) Defaults to YES
 *
 * @param   message         The currently clicked message
 * @param   userData        The user profile carried by the currently clicked message
 *
 */
- (BOOL)didSelectMessageItem:(AgoraChatMessage *)message userProfile:(id<EaseUserProfile>)userData;

/**
 * The extended area data model group for the current specific message
 *
 * @param   defaultLongPressItems       Default long press extended area function Data model group (default: copy, delete, recall)
 * @param   message                     Current long-press message
 *
 */
- (NSMutableArray<EaseExtMenuModel *> *)messageLongPressExtMenuItemArray:(NSMutableArray<EaseExtMenuModel*>*)defaultLongPressItems message:(AgoraChatMessage*)message;


/* Page dropdown load callback */

/**
 * Drop down to load more message callbacks
 *
 * @param   firstMessageId          First Message ID
 * @param   messageList             Current Message list
 *
 */
- (void)loadMoreMessageData:(NSString *)firstMessageId currentMessageList:(NSArray<AgoraChatMessage *> *)messageList;

@end

NS_ASSUME_NONNULL_END
