//
//  EMImageBrowser.m
//  EaseChat
//
//  Created by XieYajie on 2019/1/29.
//  Copyright © 2019 XieYajie. All rights reserved.
//

#import "EMImageBrowser.h"


#define IMAGE_MAX_SIZE_5k 5120*2880

static EMImageBrowser *browser = nil;
@interface EMImageBrowser()<EasePhotoBrowserDelegate>

@property (nonatomic, strong) NSArray *photos;

@property (strong, nonatomic) EasePhotoBrowser *photoBrowser;

@property (nonatomic, strong) UINavigationController *photoNavigationController;

@property (nonatomic, strong) UIViewController *superController;

@end


@implementation EMImageBrowser

+ (instancetype)sharedBrowser
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        browser = [[EMImageBrowser alloc] init];
    });
    
    return browser;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        _photoBrowser = [[EasePhotoBrowser alloc] initWithDelegate:self];
        _photoBrowser.delegate = self;
        _photoBrowser.displayActionButton = YES;
        _photoBrowser.displayNavArrows = YES;
        _photoBrowser.displaySelectionButtons = NO;
        _photoBrowser.alwaysShowControls = NO;
        _photoBrowser.zoomPhotosToFill = YES;
        _photoBrowser.enableGrid = NO;
        _photoBrowser.startOnGrid = NO;
        [_photoBrowser setCurrentPhotoIndex:0];
        
        _photoNavigationController = [[UINavigationController alloc] initWithRootViewController:self.photoBrowser];
        _photoNavigationController.modalTransitionStyle = UIModalTransitionStyleCrossDissolve;
    }
    
    return self;
}

#pragma mark - EasePhotoBrowserDelegate

- (NSUInteger)numberOfPhotosInPhotoBrowser:(EasePhotoBrowser *)photoBrowser
{
    return [self.photos count];
}

- (id <EasePhoto>)photoBrowser:(EasePhotoBrowser *)photoBrowser photoAtIndex:(NSUInteger)index
{
    if (index < self.photos.count) {
        return [self.photos objectAtIndex:index];
    }
    
    return nil;
}

- (void)photoBrowserDidFinishModalPresentation:(EasePhotoBrowser *)photoBrowser
{
    [self dismissViewController];
}

#pragma mark - Private

- (UIImage *)_scaleImage:(UIImage *)aImage
                 toScale:(float)aScaleSize
{
    UIGraphicsBeginImageContext(CGSizeMake(aImage.size.width * aScaleSize, aImage.size.height * aScaleSize));
    [aImage drawInRect:CGRectMake(0, 0, aImage.size.width * aScaleSize, aImage.size.height * aScaleSize)];
    UIImage *scaledImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return scaledImage;
}

#pragma mark - Public

- (void)showImages:(NSArray<UIImage *> *)aImageArray
    fromController:(UIViewController *)aController
{
    if ([aImageArray count] == 0) {
        return;
    }
    
    NSMutableArray *photoArray = [NSMutableArray array];
    for (id obj in aImageArray) {
        EasePhoto *photo;
        if ([obj isKindOfClass:[UIImage class]]) {
            UIImage *img = (UIImage *)obj;
            CGFloat imageSize = img.size.width * img.size.height;
            if (imageSize > IMAGE_MAX_SIZE_5k) {
                photo = [EasePhoto photoWithImage:[self _scaleImage:img toScale:(IMAGE_MAX_SIZE_5k)/imageSize]];
            } else {
                photo = [EasePhoto photoWithImage:obj];
            }
        }
        
        if (photo) {
            [photoArray addObject:photo];
        }
    }
    
    self.photos = photoArray;
    [self.photoBrowser reloadData];
    self.superController = aController;
    self.photoNavigationController.modalPresentationStyle = 0;
    [aController presentViewController:self.photoNavigationController animated:YES completion:nil];
}

- (void)dismissViewController
{
    [self.superController dismissViewControllerAnimated:YES completion:^{
        self.superController = nil;
    }];
}

@end
