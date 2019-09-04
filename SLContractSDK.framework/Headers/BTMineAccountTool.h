//
//  BTMineAccountTool.h
//  BTStore
//
//  Created by WWLy on 2018/1/31.
//  Copyright © 2018年 Karl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BTMineAccountModel.h"

@interface BTMineAccountTool : NSObject

@property (nonatomic, strong) BTMineAccountModel *mineAccountModel;

@property (nonatomic, strong) NSArray <BTItemCoinModel *>*contractAccountArr;

@property (nonatomic, assign) BOOL loadAssetSuccess;

+ (instancetype)shareMineAccountTool;

- (void)loadCurrentAccountPropertyInfoWithParames:(NSDictionary *)parames success:(void (^)(BTMineAccountModel *response))success failure:(void (^)(NSError *))failure;

- (void)loadContractAccountPropertyInfoWithContractID:(NSString *)contractID success:(void (^)(NSArray <BTItemCoinModel *>*response))success failure:(void (^)(NSError *))failure;

+ (BTItemCoinModel *)getCoinAssetsWithCoinCode:(NSString *)coin_code;

+ (BTItemCoinModel *)getSpotCoinAssetsWithCoinCode:(NSString *)coin_code;

// 判断该币种有没有开通账户
+ (BOOL)hasOpenContractAccountWithCoin:(NSString *)coinCode;

@end
