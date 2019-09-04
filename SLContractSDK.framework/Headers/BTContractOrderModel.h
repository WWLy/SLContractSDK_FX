//
//  BTContractOrderModel.h
//  SLContractSDK
//
//  Created by WWLy on 2018/7/18.
//  Copyright © 2018年 Karl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BTPositionModel.h"

// 订单方向
typedef NS_ENUM(NSInteger, BTContractOrderWay) {
    BTContractOrderWayUnkown = 0,
    BTContractOrderWayBuy_OpenLong,             // 买多
    BTContractOrderWayBuy_CloseShort,           // 平空
    BTContractOrderWaySell_CloseLong,           // 平多
    BTContractOrderWaySell_OpenShort            // 买空
};

// 订单类型
typedef NS_ENUM(NSInteger, BTContractOrderCategory) {
    BTContractOrderCategoryUnkown = 0,
    BTContractOrderCategoryNormal = 1,      // 限价委托
    BTContractOrderCategoryMarket = 2,      // 市价委托
    BTContractOrderCategoryStopLoss = 3,    // 止损委托
    BTContractOrderCategoryStopFill = 4,    // 止盈委托
    BTContractOrderCategoryHidden = 5,      // 隐藏委托
    BTContractOrderCategoryIceMountain = 6, // 冰山委托
    BTContractOrderCategoryPassive = 7,     // 被动委托
    BTContractOrderCategoryPlan = 8,       // 计划委托
    BTContractOrderCategoryTrigger = 129,     // 触发委托
    BTContractOrderCategoryBreak = 257,
    BTContractOrderCategoryDetail = 513
};

// 订单状态
typedef NS_ENUM(NSInteger, BTContractOrderStatus) {
    BTContractOrderStatusUnkown = 0,
    BTContractOrderStatusApproval,             // 申报中
    BTContractOrderStatusWait,                 // 委托中
    BTContractOrderStatusFinished = 4,              // 结束
};


// 订单完成的原因
typedef NS_ENUM(NSInteger, BTContractOrderErrNO) {
    BTContractOrderErrNONoErr = 0,  // 没有原因,在订单完成的状态下表示订单已经全部成交
    BTContractOrderErrCancel,           // 订单被取消
    BTContractOrderErrTimeout,          // 订单超时,暂时不用
    BTContractOrderErrASSETS,           // 用户资产不够,转撤销
    BTContractOrderErrUNDO,             // 系统部分转撤销
    BTContractOrderErrCLOSE,            // 部分平仓导致的部分转撤销
    BTContractOrderErrReduce,           // 自动减仓导致的部分转撤销
    BTContractOrderErrCompensate,       // 盈利补偿导致的部分转撤销(暂时没有用)
    BTContractOrderErrPositionErr,      // 仓位错误导致的部分转撤销
};

// 订单状态
typedef NS_ENUM(NSInteger, BTContractOrderViewStatus) {
    BTContractOrderViewStatusUnkown = 0,
    BTContractOrderViewStatusCanceling,             // 正在取消中
};

// 价类型
typedef NS_ENUM(NSInteger, BTContractOrderPriceType) {
    BTContractOrderTradePriceType = 1,              // 交易价
    BTContractOrderMarkPriceType  = 2,              // 标记价
    BTContractOrderIndexPriceType = 4               // 指数价
};

// 价格方向
typedef NS_ENUM(NSInteger, BTContractOrderPriceWay) {
    BTContractOrderPriceWayUp = 1,              // 看涨
    BTContractOrderPriceWayDown = 2,           // 看跌
};

@interface BTContractOrderModel : NSObject

@property (nonatomic, assign) int64_t order_id;      // 订单ID
@property (nonatomic, assign) int64_t contract_id;  // 合约ID
@property (nonatomic, assign) int64_t position_id;  // 仓位ID
@property (nonatomic, copy) NSString *name;         // 合约名称
@property (nonatomic, copy) NSString *avai;         // 合约价值
@property (nonatomic, copy) NSString *price;        // 订单价格
@property (nonatomic, copy) NSString *vol;          // 订单量
@property (nonatomic, copy) NSString *leverage;     // 杠杆
@property (nonatomic, copy) NSString *done_avg_price;   // 成交均价
@property (nonatomic, copy) NSString *done_vol;  // 成交量
@property (nonatomic, copy) NSString *executive_price; // 执行价格
@property (nonatomic, assign) BTContractOrderPriceType price_type; // 价格类型
@property (nonatomic, assign) BTContractOrderPriceWay price_way;  // 价格方向
@property (nonatomic, copy) NSString *life_cycle;   // 委托周期,单位小时
@property (nonatomic, assign) BTContractOrderWay way;
@property (nonatomic, assign) BTContractOrderCategory category;
@property (nonatomic, assign) BTPositionOpenType open_type;
@property (nonatomic, copy) NSString * make_fee;
@property (nonatomic, copy) NSString * take_fee;
@property (nonatomic, copy) NSString * takeFeeRatio;
@property (nonatomic, copy) NSString * makeFeeRatio;
@property (nonatomic, copy) NSString * origin;
@property (nonatomic, copy) NSString * feeCoinCode;
@property (nonatomic, copy) NSString * doneFee;
@property (nonatomic, copy) NSString * created_at;
@property (nonatomic, copy) NSString * finished_at;
@property (nonatomic, assign) BTContractOrderStatus status;
@property (nonatomic, assign) BTContractOrderErrNO errorno;
@property (nonatomic, copy) NSNumber * nonce;
@property (nonatomic, copy) NSString *forceTips;
@property (nonatomic, copy) NSString *currentPrice;  // 当前市场最新价格
@property (nonatomic, copy) NSString *open_avg_price; // 预计开仓均价

@property (nonatomic, assign) BTPositionType orderPositionType;

@property (nonatomic, assign) BTPositionType OrderLogicPositionType;

@property (nonatomic, copy) NSString *IMR; // 开仓保证金率
@property (nonatomic, copy) NSString *MMR; // 维持保证金率
@property (nonatomic, copy) NSString *BTR; // 破产保证金率
@property (nonatomic, copy) NSString *liquidatePrice; // 强平价格
@property (nonatomic, copy) NSString *index_price; // 指数价格
@property (nonatomic, copy) NSString *quote_coin; // 计价单位
@property (nonatomic, copy) NSString *freezAssets; // 开仓成本
@property (nonatomic, copy) NSString *freezShort; // 开空仓成本
@property (nonatomic, copy) NSString *balanceAssets; // 余额
@property (nonatomic, copy) NSString *markPrice;

@property (nonatomic, strong) BTContractsModel *contractInfo;

- (instancetype)initWithDict:(NSDictionary *)dict;
+ (instancetype)contractOrderWithDict:(NSDictionary *)dict;

// 创建开仓订单
+ (instancetype)newContractOpenOrderWithContractId:(int64_t)contract_id
                 category:(BTContractOrderCategory)category
                      way:(BTContractOrderWay)way
                 openType:(BTPositionOpenType)open_type
                 leverage:(NSString *)leverage
                    price:(NSString *)price
                      vol:(NSString *)vol;

// 创建平仓订单
+ (instancetype)newContractCloseOrderWithContractId:(int64_t)contract_id
                                      category:(BTContractOrderCategory)category
                                           way:(BTContractOrderWay)way
                                    positionID:(int64_t)position_id
                                         price:(NSString *)price
                                           vol:(NSString *)vol;

// 根据仓位生成订单
+ (instancetype)orderWithPositionContractID:(int64_t)contract_id
                                      price:(NSString *)price
                                        vol:(NSString *)vol;

// 开仓订单数据
- (NSDictionary *)buildSubmitContractOpenOrderData;

// 计划委托开仓订单数据
- (NSDictionary *)buildSubmitPlanContractOpenOrderData;

// 计划委托平仓数据
- (NSDictionary *)buildSubmitPlanContractCloseOrderData;

// 平仓订单数据
- (NSDictionary *)buildSubmitContractCloseOrderData;

@end
