//
//  JKIAPVerifyManager.h
//  JKIAPHelp
//
//  Created by kane on 2018/8/13.
//  Copyright © 2018年 kane. All rights reserved.
//

#import <Foundation/Foundation.h>

@class JKIAPTransactionModel;
NS_ASSUME_NONNULL_BEGIN

@protocol JKIAPVerifyManagerDelegate <NSObject>

- (void)startPaymentTransactionVerifingModel:(JKIAPTransactionModel *)transactionModel;

@end


@interface JKIAPVerifyManager : NSObject

/* 代理 */
@property (nonatomic,weak)id<JKIAPVerifyManagerDelegate> delegate;

@property (nonatomic, copy) NSString *userId;

/**
 * 初始化方法.
 */
- (instancetype)initWithUserId:(NSString *)userId ;


/**
 获取所有交易模型
 
 @return model
 */
- (NSMutableSet <JKIAPTransactionModel *>*)fetchAllPaymentTransactionModel;

/**
 * 添加需要验证的 model.
 */
- (void)appendPaymentTransactionModel:(JKIAPTransactionModel *)transactionModel;


/**
 开始支付凭证验证队列

 @param transactionModel 验证的model
 */
- (void)startPaymentTransactionVerifingModel:(JKIAPTransactionModel *)transactionModel;



/**
 更新model

 @param transactionModel model
 */
- (void)updatePaymentTransactionModelStatus:(JKIAPTransactionModel *)transactionModel;




/**
 * 删除失败 model.
 */
- (void)deletePaymentTransactionModel:(JKIAPTransactionModel *)transactionModel;



/**
⚠️ 删除所有已储存订单
 */
- (void)cleanAllModels;



/**
 检测苹果支付完成未验证的订单
 */
- (void)checkUnfinishedTransaction;
@end

NS_ASSUME_NONNULL_END
