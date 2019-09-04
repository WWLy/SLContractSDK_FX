//
//  SLSocketDataManager.h
//  BTTest
//
//  Created by WWLy on 2019/8/16.
//  Copyright © 2019 wwly. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SLSocketDataManagerDelegate <NSObject>

@end

/// 负责数据的更新和传递
@interface SLSocketDataManager : NSObject

/// socket 数据更新
@property (nonatomic, copy) void (^sl_dataUpdatedFromSocket)(id data);

+ (instancetype)sharedInstance;

/**
 * 订阅实时价格 socket
 */
- (void)sl_subscribeTickerData;

/**
 订阅深度 socket
 @param contractID 合约ID
 */
- (void)sl_subscribeDepthDataWithContractID:(int64_t)contractID;

/**
 * 订阅私有信息(订单信息, 仓位信息, 合约资产, 现货资产)
 */
- (void)sl_subscribeUnicastData;

@end

NS_ASSUME_NONNULL_END
