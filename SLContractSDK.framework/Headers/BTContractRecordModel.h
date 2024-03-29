//
//  BTContractRecordModel.h
//  SLContractSDK
//
//  Created by WWLy on 2018/7/26.
//  Copyright © 2018年 Karl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BTContractsModel.h"
typedef NS_ENUM(NSInteger, BTContractRecordWay) {
    CONTRACT_TRADE_WAY_UN_KNOW = 0,
    CONTRACT_ORDER_WAY_BUY_OPEN_LONG,           // 开多 买
    CONTRACT_ORDER_WAY_BUY_CLOSE_SHORT,         // 平空 买
    CONTRACT_ORDER_WAY_SELL_CLOSE_LONG,         // 平多 卖
    CONTRACT_ORDER_WAY_SELL_OPEN_SHORT,         // 开空 卖
    CONTRACT_WAY_BB_TRANSFER_IN,                //从现货账号转入
    CONTRACT_WAY_TRANSFER_TO_BB,                //转出到现货账号
    CONTRACT_WAY_CONTRACT_TRANSFER_IN,          //从合约账号转入
    CONTRACT_WAY_TRANSFER_TO_CONTRACT,          //转出到合约账号
    CONTRACT_WAY_REDUCE_DEPOSIT_TRANSFER,       //减少保证金,将保证金从仓位转移到合约账户
    CONTRACT_WAY_INCREA_DEPOSIT_TRANSFER,       //增加保证金,将合约账户的资产转移到仓位保证金
    CONTRACT_WAY_POSITION_FUND_FEE              //仓位的资金费用
};

@interface BTContractLipRecordModel : NSObject
@property (nonatomic, copy) NSString *coinCode;
@property (nonatomic, copy) NSString *marginCoin;
@property (nonatomic, copy) NSString *forcePrice;
@property (nonatomic, copy) NSString *trigger_price;
@property (nonatomic, assign) int64_t account_id;
@property (nonatomic, assign) int64_t contract_id;
@property (nonatomic, copy) NSString *created_at;
@property (nonatomic, copy) NSString *mmr;
@property (nonatomic, copy) NSString *order_id;
@property (nonatomic, copy) NSString *order_price;
@property (nonatomic, assign) int64_t position_id;
@property (nonatomic, assign) int64_t subsidies;
@property (nonatomic, assign) NSInteger type;
- (instancetype)initWithDict:(NSDictionary *)dict;
@end

@interface BTContractRecordModel : NSObject
@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) int64_t order_id;         // taker order id
@property (nonatomic, assign) int64_t trade_id;         // trade id
@property (nonatomic, assign) int64_t contract_id;      // 合约ID
@property (nonatomic, copy) NSString *deal_price;       // 成交价
@property (nonatomic, copy) NSString *deal_vol;         // 成交量

@property (nonatomic, copy) NSString *avai;             // 价值

@property (nonatomic, copy) NSString *make_fee;         // make fee
@property (nonatomic, copy) NSString *take_fee;         // take fee
@property (nonatomic, copy) NSString *created_at;       // 创建时间
@property (nonatomic, assign) BTContractRecordWay way;  // 交易方向
@property (nonatomic, copy) NSString *fluctuation;      // 对行情的影响

@property (nonatomic, strong) BTContractsModel *contractInfo;

- (instancetype)initWithDict:(NSDictionary *)dict;

@end
