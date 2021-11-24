//
//  EaseChatViewController.h
//  EaseChatKit
//
//  Update © 2020 zhangchong. All rights reserved.
//


#import "EaseChatViewModel.h"
#import "EaseChatViewControllerDelegate.h"
#import "EaseInputBar.h"

NS_ASSUME_NONNULL_BEGIN

@interface EaseChatViewController : UIViewController <UIScrollViewDelegate, UITableViewDelegate, UITableViewDataSource, UIDocumentInteractionControllerDelegate, AgoraChatManagerDelegate, EaseInputBarDelegate, EaseMessageCellDelegate, EaseChatInputBarEmoticonViewDelegate, EaseInputBarRecordAudioViewDelegate>

@property (nonatomic, weak) id<EaseChatViewControllerDelegate> delegate;

@property (nonatomic, strong) AgoraChatConversation *currentConversation;
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSMutableArray *dataArray;
@property (nonatomic, strong) NSString *moreMsgId;  //Message ID of the first message
@property (nonatomic) NSTimeInterval msgTimelTag;   //Message time formatting

+ (EaseChatViewController *)initWithConversationId:(NSString *)aConversationId
                                  conversationType:(AgoraChatConversationType)aType
                                     chatViewModel:(EaseChatViewModel *)aModel;

// Resetting the data source
- (void)resetUserProfiles:(NSArray<id<EaseUserProfile>> *)userProfileAry;

// Reset the chat controller view
- (void)resetChatVCWithViewModel:(EaseChatViewModel *)viewModel;

// Setup inputbar
- (void)setupInputBar:(EaseInputBar *)inputbar;

// Sets whether to display input status
- (void)setEditingStatusVisible:(BOOL)editingStatusVisible;

// Sending text messages
- (void)sendTextAction:(NSString *)aText ext:(NSDictionary * __nullable)aExt;

// Sending message body
- (void)sendMessageWithBody:(AgoraChatMessageBody *)aBody ext:(NSDictionary * __nullable)aExt;

// Sending message read receipt
- (void)sendReadReceipt:(AgoraChatMessage *)msg;

// Refresh tableview.
//      isScrollBottom:Whether the list scrolls to the bottom (at the latest message)
- (void)refreshTableView:(BOOL)isScrollBottom;

// Refresh tableview with messaegs.
//      isInsertBottom:Whether the message is inserted to the tail (header by default)
//      isScrollBottom:Whether the list scrolls to the bottom (at the latest message)
- (void)refreshTableViewWithData:(NSArray<AgoraChatMessage *> *)messages isInsertBottom:(BOOL)isInsertBottom isScrollBottom:(BOOL)isScrollBottom;

// Clear other controller pages that pop up from the chat page (for example, clean album popup page, picture browsing page, input expansion area, etc.)
- (void)cleanPopupControllerView;

// Stop playing audio
- (void)stopAudioPlayer;

@end

NS_ASSUME_NONNULL_END
