//
//  SLContractSDK.h
//  SLContractSDK
//
//  Created by WWLy on 2019/8/6.
//  Copyright © 2019 Karl. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SLSDK.h"
#import "SLPlatformSDK.h"
#import "BTContractsModel.h"
#import "BTContractsOpenModel.h"
#import "BTContractRecordModel.h"
#import "BTContractOrderModel.h"
#import "BTContractTradeModel.h"
#import "BTContractTool.h"
#import "BTPositionModel.h"
#import "SLSDKUIConfig.h"
#import "SLSocketDataManager.h"

//#import "BTMarketTableView.h"

// BTNotification
#define BTNoteCenter [NSNotificationCenter defaultCenter]

#pragma mark - send Post Notification

// 获取合约信息成功
#define BTLoadContractsInfo_Notification    @"BTLoadContractsInfo_Notification"
// 合约更新资产
#define BTFutureProperty_Notification       @"BTFutureProperty_Notification"
// 加载合约市场成功
#define BTLoadFuturesData_Notification      @"BTLoadFuturesData_Notification"

#pragma mark - websocket Notification

/// 实时价格更新
#define BTSocketDataUpdate_Ticker_Notification   @"BTSocketDataUpdate_Ticker_Notification"
/// 深度数据更新
#define BTSocketDataUpdate_Depth_Notification    @"BTSocketDataUpdate_Depth_Notification"
/// 私有信息更新
#define BTSocketDataUpdate_Unicast_Notification  @"BTSocketDataUpdate_Unicast_Notification"

//! Project version number for SLContractSDK.
FOUNDATION_EXPORT double SLContractSDKVersionNumber;

//! Project version string for SLContractSDK. 
FOUNDATION_EXPORT const unsigned char SLContractSDKVersionString[];


