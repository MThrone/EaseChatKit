//
//  EaseChatKitManager.h
//  EaseChatKit
//
//  Created by 杜洁鹏 on 2020/10/29.
//

#import <Foundation/Foundation.h>
#import "EasePublicHeaders.h"

NS_ASSUME_NONNULL_BEGIN

//System notification interface
@protocol EaseChatKitSystemNotiDelegate <NSObject>
@optional

/**
 * Whether system notification is required: The default notification is required for friend/group applications
 */
- (BOOL)isNeedsSystemNotification;

/**
 * Return display information after receiving a request
 *
 * @param   conversationId   conversaion ID
 *  For single chat，conversation ID is to chat user's name
 *  For group chat, conversation ID is groupID(), different with getGroupName()
 *  For chat room, conversation ID is chatroom ID, different with chat room name()
 *  For help desk, it is same with single chat, conversationID is also chat user's name
 *
 * @param   requestUser   requester
 * @param   reason        reason
 */
- (NSString *)requestDidReceiveShowMessage:(NSString *)conversationId requestUser:(NSString *)requestUser reason:(EaseChatKitCallBackReason)reason;

/**
 * Return extended information on receipt of request
 *
 * @param   conversationId   conversaion ID
 *  For single chat，conversation ID is to chat user's name
 *  For group chat, conversation ID is groupID(), different with getGroupName()
 *  For chat room, conversation ID is chatroom ID, different with chat room name()
 *  For help desk, it is same with single chat, conversationID is also chat user's name
 *
 * @param   requestUser   requester
 * @param   reason        reason
 */
- (NSDictionary *)requestDidReceiveConversationExt:(NSString *)conversationId requestUser:(NSString *)requestUser reason:(EaseChatKitCallBackReason)reason;
@end



@protocol EaseChatKitManagerDelegate <NSObject>
@optional

/**
 * The total number of unread sessions changes
 *
 * @param   unreadCount     Total unread of the current session list
 */
- (void)conversationsUnreadCountUpdate:(NSInteger)unreadCount;

@end


@interface EaseChatKitManager : NSObject

@property (nonatomic, strong, readonly) NSString *version; //UIKit version
@property (nonatomic) id<EaseChatKitSystemNotiDelegate>systemNotiDelegate; //The system notifies the callback agent
+ (BOOL)initWithAgoraChatOptions:(AgoraChatOptions *)options;
+ (EaseChatKitManager *)shared;
+ (NSString *)EaseChatKitVersion;
- (void)addDelegate:(id<EaseChatKitManagerDelegate>)aDelegate;
- (void)removeDelegate:(id<EaseChatKitManagerDelegate>)aDelegate;

- (void)markAllMessagesAsReadWithConversation:(AgoraChatConversation *)conversation;

@end

NS_ASSUME_NONNULL_END
