//
//  AppDelegate.m
//  EaseChatKitDemo
//
//  Created by 杜洁鹏 on 2020/10/29.
//  Copyright © 2020 djp. All rights reserved.
//

#import "AppDelegate.h"
#import <AgoraChat/AgoraChat.h>
#import "AgoraChatHttpRequest.h"

#define kDefaultName @"bye"
#define kDefaultNickname @"custom"

#define USER_NAME @"user_name"
#define USER_NICKNAME @"nick_name"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    AgoraChatOptions *options = [AgoraChatOptions optionsWithAppkey:@"61117440#460199"];
    options.enableConsoleLog = YES;
    options.enableDeliveryAck = YES;

    [EaseChatKitManager initWithAgoraChatOptions:options];
    [self doLogin];
    
    return YES;
}

- (void)doLogin {
    void (^finishBlock) (NSString *aName, NSString *nickName, AgoraChatError *aError) = ^(NSString *aName, NSString *nickName, AgoraChatError *aError) {
        if (!aError) {
            if (nickName) {
                [AgoraChatClient.sharedClient.userInfoManager updateOwnUserInfo:nickName withType:AgoraChatUserInfoTypeNickName completion:^(AgoraChatUserInfo *aUserInfo, AgoraChatError *aError) {
                    if (!aError) {
                    }
                }];
            }
            
            NSUserDefaults *shareDefault = [NSUserDefaults standardUserDefaults];
            [shareDefault setObject:aName forKey:USER_NAME];
            [shareDefault setObject:nickName forKey:USER_NICKNAME];
            [shareDefault synchronize];
        
            UIAlertView *alertError = [[UIAlertView alloc] initWithTitle:nil message:@"login success !" delegate:nil cancelButtonTitle:nil otherButtonTitles:NSLocalizedString(@"login.ok", @"Ok"), nil];
            [alertError show];
            return ;
        }
        
        NSString *errorDes = NSLocalizedString(@"login.failure", @"login failure");
        switch (aError.code) {
            case AgoraChatErrorServerNotReachable:
                errorDes = NSLocalizedString(@"error.connectServerFail", @"Connect to the server failed!");
                break;
            case AgoraChatErrorNetworkUnavailable:
                errorDes = NSLocalizedString(@"error.connectNetworkFail", @"No network connection!");
                break;
            case AgoraChatErrorServerTimeout:
                errorDes = NSLocalizedString(@"error.connectServerTimeout", @"Connect to the server timed out!");
                break;
            case AgoraChatErrorUserAlreadyExist:
                errorDes = NSLocalizedString(@"login.taken", @"Username taken");
                break;
            default:
                errorDes = NSLocalizedString(@"login.failure", @"login failure");
                break;
        }
        UIAlertView *alertError = [[UIAlertView alloc] initWithTitle:nil message:errorDes delegate:nil cancelButtonTitle:nil otherButtonTitles:NSLocalizedString(@"login.ok", @"Ok"), nil];
        [alertError show];
    };
    
    if (AgoraChatClient.sharedClient.isLoggedIn) {
        [AgoraChatClient.sharedClient logout:YES];
    }
    
    //unify token login
    [[AgoraChatHttpRequest sharedManager] loginToApperServer:[kDefaultName lowercaseString] nickName:kDefaultNickname completion:^(NSInteger statusCode, NSString * _Nonnull response) {
        dispatch_async(dispatch_get_main_queue(), ^{
            NSString *alertStr = nil;
            if (response && response.length > 0 && statusCode) {
                NSData *responseData = [response dataUsingEncoding:NSUTF8StringEncoding];
                NSDictionary *responsedict = [NSJSONSerialization JSONObjectWithData:responseData options:0 error:nil];
                NSString *token = [responsedict objectForKey:@"accessToken"];
                NSString *loginName = [responsedict objectForKey:@"chatUserName"];
                NSString *nickName = [responsedict objectForKey:@"chatUserNickname"];
                if (token && token.length > 0) {
                    [[AgoraChatClient sharedClient] loginWithUsername:[loginName lowercaseString] agoraToken:token completion:^(NSString *aUsername, AgoraChatError *aError) {
                        finishBlock(aUsername, nickName, aError);
                    }];
                    return;
                } else {
                    alertStr = NSLocalizedString(@"login analysis token failure", @"analysis token failure");
                }
            } else {
                alertStr = NSLocalizedString(@"login appserver failure", @"Sign in appserver failure");
            }
            
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:nil message:alertStr delegate:nil cancelButtonTitle:nil otherButtonTitles:NSLocalizedString(@"loginAppServer.ok", @"Ok"), nil];
            [alert show];
        });
    }];
    
}


@end
