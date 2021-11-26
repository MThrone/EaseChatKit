//
//  MineViewController.m
//  EaseChatKitDemo
//
//  Created by 杜洁鹏 on 2020/11/5.
//  Copyright © 2020 djp. All rights reserved.
//

#import "MineViewController.h"

@interface MineViewController ()
@property (weak, nonatomic) IBOutlet UILabel *userLabel;
@property (weak, nonatomic) IBOutlet UILabel *versionLabel;

@end

@implementation MineViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.navigationController.navigationBar setShadowImage:[UIImage new]];
    self.userLabel.text = AgoraChatClient.sharedClient.currentUsername;
    self.versionLabel.text = AgoraChatClient.sharedClient.version;
}

- (IBAction)logoutBtnClicked:(id)sender {
//    [AgoraChatClient.sharedClient logout:YES completion:^(AgoraChatError *aError) {
//            
//    }];
}


@end
