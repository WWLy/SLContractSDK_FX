//
//  SLSDKUIConfig.h
//  SLContractSDK
//
//  Created by WWLy on 2019/8/14.
//  Copyright © 2019 Karl. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SLSDKUIConfig : NSObject
+ (SLSDKUIConfig *)sharedInstance;
@property (nonatomic, strong) UIColor *main_Color; // 主色调
@property (nonatomic, strong) UIColor *main_btnColor; // 主题颜色
@property (nonatomic, strong) UIColor *main_BackgroundColor;
@property (nonatomic, strong) UIColor *main_TextColor;
@property (nonatomic, strong) UIColor *main_GaryTextColor;
@property (nonatomic, strong) UIColor *bottomLineColor;
@property (nonatomic, strong) UIColor *btn_TextColor; // 按钮字体颜色

@property (nonatomic, strong) UIColor *raiseColor;
@property (nonatomic, strong) UIColor *downColor;
@end
