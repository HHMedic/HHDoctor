//
//  HHSDKOptions.h
//  hhvDoctorSDK_OC
//
//  Created by 程言方 on 2021/1/27.
//

@protocol HHImageEngine <NSObject>

- (void) loadImageView : (UIImageView *) imageView placeholder : (UIImage *) placeholder url : (NSString *) url;

@end

@interface HHSDKOptions : NSObject
/**
 * 是否开启debug
*/
@property (nonatomic, assign) BOOL isDebug;
/**
 * isDevelopment  是测试环境 还是 生产环境  true 为 测试环境  false 为生产
 */
@property (nonatomic, assign) BOOL isDevelopment;
/**
 * 和缓分配的唯一id
 */
@property (nonatomic, strong) NSString * sdkProductId;

@property (nonatomic , weak) id <HHImageEngine> mImageEngine;

/**
 * sdk 扩展统计字段
*/
@property (nonatomic, strong) NSString * mExtensionString;

@property (nonatomic, strong) NSString * sdkVersion;

+ (HHSDKOptions *)sharedInstance;

/**
 * 初始化
 *
 * @param sdkProductId  和缓分配的唯一id
 * @param develop  是测试环境 还是 生产环境  true 为 测试环境  false 为生产
 * @param imageEngine 网络图片加载代理
 */
- (HHSDKOptions *) initWithSdkProductId : (NSString *) sdkProductId isDevelop : (BOOL) develop imageEngine : (id <HHImageEngine>) imageEngine;

- (void) loadConfig : (HHSDKOptions *) options;

@end
