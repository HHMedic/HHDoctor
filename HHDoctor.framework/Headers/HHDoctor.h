//
//  HHDoctor.h
//  HHDoctor
//
//  Created by 程言方 on 2021/1/27.
//

#import "HHSDKOptions.h"

typedef NS_ENUM(NSInteger, HHMCallingState) {
    onStart = 0,
    waitingDoctor,
    callFreeDoctor,
    callConnect,
    didRing,
};

typedef NS_ENUM(NSInteger, FailCode) {
    loginFail = -6,
    notLogin = -5,
    permision = -4,
    netError = -3,
    fail = -2,
    callMessageFail = -100002,
};

@protocol HHMVideoDelegate<NSObject>

/**
 * 启动呼叫
 */
- (void) onStart: (NSString*) orderId;

/**
 * 通话结束
 *
 * @param time  视频时长  单位秒
 */
- (void) onFinish: (long) time;

/**
 * 呼叫成功，等待医生接受
 */
- (void) onCallSuccess;

/**
 * 呼叫失败
 * @param code 错误码
 */
- (void) onFail: (NSInteger) code;

/**
 * 取消呼叫  含 取消排队
 */
- (void) onCancel;



@end


@interface HHDoctor : NSObject

+ (HHDoctor *) sharedInstance;

- (void) startWithOption : (HHSDKOptions * ) options;

/**
 * 登录
 * @param userToken token   和缓分配token
 * @param completion  完成回调
*/
- (void) loginWithUserToken : (NSString *) userToken
                 completion :(void (^)(NSString *errorMsg))completion;

/**
 * 发起呼叫
 *
 * 本方法不带UI，需要自己实现选择UI
 *
 *   userToken 请传咨询人信息 例如 给本人看 就传本人的userToken 给家庭成员看 就传家庭成员userToken
 *   @param userToken 咨询人
 *   @param delegate 回调
*/
- (void) startCallWithUserToken : (NSString *) userToken delegate: (id<HHMVideoDelegate>) delegate;

/**
 * @param ext 自定义参数
*/

-(void)setCallExtension:(NSString *)ext;

/**
 * 退出登录
*/
- (void) logout;

- (void) switchToDev: (BOOL) isDevelopment;

- (void) excute: (void (^)(id<HHMVideoDelegate> delegate))block;

- (void) remoteMessage: (NSString *) message;

/**
 * 病历详情 地址
 * @param medicId   病历id
 * @param userToken 登录帐号id
 * @param patientUserToken  真实患者id
 * 如果没有成员关系，patientUserToken 和     userToken 可以是一个值
*/
- (NSString *) getMedicDetailUrlWithMedicId : (NSString *) medicId userToken: (NSString *) userToken patientUserToken: (NSString *) patientUserToken;
@end



