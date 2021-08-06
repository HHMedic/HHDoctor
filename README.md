## 和缓视频医生iOS SDK接入文档

#### 一、 iOS工程引入和缓视频医生SDK

##### 1. Podfile引入和缓视频医生SDK：

pod "HHDoctor"

##### 2. 第三方引用
注:这些库必须添加到引用当中

```
pod 'TXLiteAVSDK_TRTC', '~>7.7.0'
```

#### 二、 使用和缓视频医生SDK

##### 1. 初始化SDK（初始化方法需要在使用SDK其他部分之前做就可以）

```
HHSDKOptions * options = [[HHSDKOptions sharedInstance]initWithSdkProductId:sdkProductId isDevelop:YES imageEngine:imageEngine];
        
[[HHDoctor sharedInstance]startWithOption:options];
```

HHSDKOptions参数说明：

| 参数定义 | 说明 |
| --- | --- |
|sdkProductId|由和缓分配的标识产品的ID|
|isDevelop|是否测试环境|
|imageEngine|辅助SDK内部用到图片资源的图片加载引擎|

HHDoctor初始化参数说明

| 参数定义 | 说明 |
| --- | --- |
|options|初始化必备参数|

其中imageEngine是实现和缓视频SDK中HHImageEngine用来实现部分SDK图片的加载引擎，实现示例使用了SDWebImage加载方式如下：
```
@interface ViewController ()<HHImageEngine>
@end

@implementation ViewController
- (void)loadImageView:(UIImageView *)imageView placeholder:(UIImage *)placeholder url:(NSString *)url {
    [imageView sd_setImageWithURL:[NSURL URLWithString:url] placeholderImage:placeholder];
}
@end
```

##### 2. 登录和缓视频医生SDK

```
[HHDoctor.sharedInstance loginWithUserToken:userToken completion:^(NSString *errorMsg) {
            
    if (errorMsg == nil) {
        
    }
            
}];
```

[HHDoctor.sharedInstance loginWithUserToken:userToken completion:completion]参数说明

| 参数定义 | 说明 |
| --- | --- |
|userToken|和缓用户唯一标识|
|completion|登录状态回调|

##### 3. 登出和缓视频医生SDK（切换账号或登出账号的时候调用）

```
[HHDoctor.sharedInstance logout];
```

##### 4. 设置呼叫附加参数

```
[HHDoctor.sharedInstance setCallExtension:@"ext"];
```

| 参数定义 | 说明 |
| --- | --- |
|ext|呼叫附加参数|

##### 5. 呼叫视频医生

```
[HHDoctor.sharedInstance startCallWithUserToken: userToken delegate:HHMVideoDelegate];
```

参数说明：

| 参数定义 | 说明 |
| --- | --- |
|userToken|请传咨询人信息，例如给本人看就传本人的userToken，给家庭成员看就传家庭成员userToken|
|HHMVideoDelegate|呼叫状态回调代理|


##### 6. 获取病历详情地址

```
[HHDoctor.sharedInstance getMedicDetailUrlWithMedicId:@"medicId" userToken:@"userToken" patientUserToken:@"patientUserToken"];
```

参数说明：

| 参数定义 | 说明 |
| --- | --- |
|medicId|病历id|
|userToken|登录帐号userToken|
|patientUserToken|真实患者userToken|
