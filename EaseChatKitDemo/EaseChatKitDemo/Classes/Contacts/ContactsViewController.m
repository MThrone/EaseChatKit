//
//  AgoraContactListController.m
//  EaseChatKitDemo
//
//  Created by liang on 2021/10/21.
//  Copyright © 2021 easemob. All rights reserved.
//

#import "ContactsViewController.h"
#import "ChatViewController.h"

@interface ContactsViewController() <UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) UITableView *table;
@property (nonatomic, strong) NSMutableArray<NSString *> *dataArray;

@end

@implementation ContactsViewController

#pragma mark life cycle
- (instancetype)init {
    self = [super init];
    if (self) {
    }
    return  self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self tableDidTriggerHeaderRefresh];
}

#pragma mark refresh and load more

- (void)tableDidTriggerHeaderRefresh {
    __weak typeof(self) weakSelf = self;
    [[AgoraChatClient sharedClient].contactManager getContactsFromServerWithCompletion:^(NSArray *aList, AgoraChatError *aError) {
        if (aError == nil) {
            [weakSelf updateContacts:aList];
            [weakSelf.table reloadData];
        }
    }];
}

- (void)loadContactsFromServer
{
    [self tableDidTriggerHeaderRefresh];
}

- (void)reloadContacts {
    NSArray *bubbyList = [[AgoraChatClient sharedClient].contactManager getContacts];
    [self updateContacts:bubbyList];
    __weak typeof(self) weakSelf = self;
    dispatch_async(dispatch_get_main_queue(), ^(){
        [weakSelf.table reloadData];
    });
}


- (void)updateContacts:(NSArray *)bubbyList {
    NSArray *blockList = [[AgoraChatClient sharedClient].contactManager getBlackList];
    NSMutableArray *contacts = [NSMutableArray arrayWithArray:bubbyList];
    for (NSString *blockId in blockList) {
        [contacts removeObject:blockId];
    }
    [self.dataArray addObjectsFromArray:contacts];
    
}


#pragma mark NSNotification
- (void)settingBlackListDidChange {
    [self reloadContacts];
}

#pragma mark - Table view data source
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return  1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return self.dataArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {

    NSString *identify = @"contanctCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identify];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identify];
    }
    
    NSString *user = self.dataArray[indexPath.row];
    cell.textLabel.text = user;
    
    return cell;
}

#pragma mark - Table view delegate
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    NSString *user = self.dataArray[indexPath.row];
    
    ChatViewController *chatVC = [[ChatViewController alloc] init];
    chatVC.chatter = user;
    chatVC.conversationType = AgoraChatConversationTypeChat;
    chatVC.hidesBottomBarWhenPushed = YES;
    [self.navigationController pushViewController:chatVC animated:YES];
}

#pragma mark getter and setter
- (UITableView *)table {
    if (_table == nil) {
        _table = [[UITableView alloc] init];
        _table.delegate = self;
        _table.dataSource = self;
        _table.separatorStyle = UITableViewCellSeparatorStyleNone;
        _table.keyboardDismissMode = UIScrollViewKeyboardDismissModeOnDrag;
        _table.clipsToBounds = YES;
        _table.rowHeight = 54.0f;
        _table.sectionIndexBackgroundColor = [UIColor clearColor];

    }
    return _table;
}

@end
