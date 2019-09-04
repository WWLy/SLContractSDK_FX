//
//  BTContractsModel.h
//  SLContractSDK
//
//  Created by WWLy on 2018/7/18.
//  Copyright © 2018年 Karl. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, BTContractType) {
    BTContractUnkown = 0,
    BTContractSustainable,     // 永续
    BTContractFuntracts        // 期货
};

typedef NS_ENUM(NSInteger, BTContract_SettleType) { // 结算类型
    BTContractSettleTypeUnkown = 0,
    BTContractSettleAutomaticType,  // 自动
    BTContractSettleManualType,     // 手动
};

typedef NS_ENUM(NSInteger, BTPositionOpenType) {
    BTPositionOpen_UnKnow = 0,
    BTPositionOpen_PursueType = 1,  // 逐仓
    BTPositionOpen_AllType,         // 全仓
    BTPositionOpen_BothType         // 都支持
};

typedef NS_ENUM(NSInteger, BTContract_CompensateType) { // 穿仓补偿方式
    BTContractCompensateTypeUnkown = 0,
    BTContractCompensateADLType,        // ADL方式
    BTContractCompensateProfitSharType, //盈利均摊
};

typedef NS_ENUM(NSInteger, BTContract_Block_Type) {
    CONTRACT_BLOCK_UNKOWN = 0,
    CONTRACT_BLOCK_USDT,        // USDT区域
    CONTRACT_BLOCK_INVERSE = 3,     // 币本位
    CONTRACT_BLOCK_SIMULATION,  // 模拟大赛
};

typedef NS_ENUM(NSInteger, BTDefinePickViewType) {
    BTDefinePickOrderType = 1,  // 市价限价单
    BTDefinePickLerverType      // 杠杆倍数
};

typedef NS_ENUM(NSInteger, BTContractOrderType) {
    BTDefineContractOpen = 30001, // 开仓单
    BTDefineContractClose,        // 平仓单
};

typedef NS_ENUM(NSInteger, BTDefineOrderType) {
    BTDefineOrderLimitType = 0,
    BTDefineOrderMarketType
};

typedef enum : NSUInteger {
    BTTradeTypeBuy = 10001,
    BTTradeTypeSell,
} BTTradeType;


@interface BTContract :NSObject
@property (nonatomic, assign) int64_t contract_id;      // 合约ID
@property (nonatomic, assign) int64_t index_id;         // 指数ID
@property (nonatomic, copy) NSString *name;             // 合约名称
@property (nonatomic, copy) NSString *display_name;     // 合约中文显示名称
@property (nonatomic, copy) NSString *display_name_en;  // 合约英文显示名称
@property (nonatomic, assign) BTContractType contract_type;
@property (nonatomic, copy) NSString *base_coin;        // 基础币
@property (nonatomic, copy) NSString *quote_coin;       // 计价币
@property (nonatomic, copy) NSString *price_coin;       // 合约大小的单位币
@property (nonatomic, assign) BOOL isReverse; // 是否是反向合约
@property (nonatomic, copy) NSString *marginCoin;
@property (nonatomic, copy) NSString *contract_size;    // 合约大小
@property (nonatomic, assign) int64_t delivery_cycle;   // 交割周期（秒）
@property (nonatomic, copy) NSString *min_leverage;     // 支持的最小杠杆
@property (nonatomic, copy) NSString *max_leverage;     // 支持的最大杠杆

@property (nonatomic, strong) NSArray *leverageArr;

@property (nonatomic, copy) NSString *price_unit;       // 价格精度
@property (nonatomic, copy) NSString *vol_unit;         // 数量精度
@property (nonatomic, copy) NSString *value_unit;       // 价值精度
@property (nonatomic, copy) NSString *min_vol;          // 合约支持的最小交易量
@property (nonatomic, copy) NSString *max_vol;          // 合约支持的最大交易量
@property (nonatomic, copy) NSString *liquidation_warn_ratio; // 平仓预警系数
@property (nonatomic, copy) NSString *fast_liquidation_ratio; // 快速平仓系数
@property (nonatomic, assign) BTContract_SettleType settle_type; // 结算类型
@property (nonatomic, assign) BTPositionOpenType open_type; //开仓类型
@property (nonatomic, assign) BTContract_CompensateType compensate_type; // 穿仓补偿方式
@property (nonatomic, copy) NSNumber *created_at;       // created_at
@property (nonatomic, assign) BTContract_Block_Type block;
- (instancetype)initWithDict:(NSDictionary *)dict;
@end

@interface BTContractRiskLimitModel : NSObject
@property (nonatomic, assign) int64_t contract_id;  // 合约ID
@property (nonatomic, copy) NSString *base_limit;   // 风险限额基础
@property (nonatomic, copy) NSString *step;         // 步长
@property (nonatomic, copy) NSString *maintenance_margin; // 维持保证金率
@property (nonatomic, copy) NSString *initial_margin;  // // 基本开仓保证金率
- (instancetype)initWithDict:(NSDictionary *)dict;
@end

@interface BTContractFeeConfigModel : NSObject
@property (nonatomic, assign) int64_t contract_id;  // 合约ID
@property (nonatomic, copy) NSString *maker_fee;    //makefee系数
@property (nonatomic, copy) NSString *taker_fee;    //makefee系数
@property (nonatomic, copy) NSString *settlement_fee; //交割手续费率，到期合约才有
@property (nonatomic, copy) NSString *long_funding; //多仓资金费率，掉期合约才有
@property (nonatomic, copy) NSString *short_funding; //空仓资金费率，掉期合约才有
@property (nonatomic, assign) int64_t funding_interval; //资金费率时间段，掉期合约才有,单位秒
@property (nonatomic, copy) NSNumber *created_at;

- (instancetype)initWithDict:(NSDictionary *)dict;

@end

@interface BTContractsModel : NSObject
@property (nonatomic, strong) BTContract *contract;
@property (nonatomic, strong) BTContractRiskLimitModel *risk_limit;
@property (nonatomic, strong) BTContractFeeConfigModel *fee_config;

+ (BTContractsModel *)decodeModelWithDict:(NSDictionary *)dict;

@end
