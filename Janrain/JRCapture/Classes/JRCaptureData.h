#import "JRCaptureEnvironment.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Copyright (c) 2012, Janrain, Inc.

 All rights reserved.

 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation and/or
   other materials provided with the distribution.
 * Neither the name of the Janrain, Inc. nor the names of its
   contributors may be used to endorse or promote products derived from this
   software without specific prior written permission.


 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@class JRCaptureConfig;
@class JRCaptureFlow;

/**
 * @internal
 */
@interface JRCaptureData : NSObject <JRCaptureEnvironment>

@property(nonatomic, readonly) NSString *captureBaseUrl;
@property(nonatomic, readonly) NSString *captureRedirectUri;
@property(nonatomic, readonly) NSString *clientId;
@property(nonatomic, readonly) NSString *accessToken;
@property(nonatomic, readonly) NSString *refreshSecret;
@property(nonatomic, readonly) NSString *captureLocale;
@property(nonatomic, readonly) NSString *captureTraditionalSignInFormName;
@property(nonatomic, readonly) NSString *captureFlowName;
@property(nonatomic, readonly) NSString *captureTraditionalRegistrationFormName;
@property(nonatomic, readonly) NSString *captureSocialRegistrationFormName;
@property(nonatomic, readonly) NSString *captureFlowVersion;
@property(nonatomic, readonly) NSString *captureAppId;
@property(nonatomic, readonly) JRCaptureFlow *captureFlow;
@property(nonatomic, readonly) NSString *captureForgottenPasswordFormName;
@property(nonatomic, readonly) NSString *captureEditProfileFormName;
@property(nonatomic, readonly) NSString *resendEmailVerificationFormName;
@property(nonatomic) BOOL flowUsesTestingCdn;
@property(nonatomic, readonly) NSArray *linkedProfiles;
@property(nonatomic, readonly) BOOL socialSignMode;

+ (void)setAccessToken:(NSString *)token;

+ (void)setCaptureRedirectUri:(NSString *)redirectUri;

+ (void)setCaptureConfig:(JRCaptureConfig *)config;

+ (NSString *)captureTokenUrlWithMergeToken:(NSString *)mergeToken delegate:(id)delegate;

+ (NSString *)captureTokenUrlWithMergeToken:(NSString *)mergeToken forAccountLinking:(BOOL)linkAccount delegate:(id)delegate;

+ (void)clearSignInState;

+ (JRCaptureData *)sharedCaptureData;

+ (NSString *)generateAndStoreRefreshSecret;

+ (NSMutableURLRequest *)requestWithPath:(NSString *)path;

+ (void)setLinkedProfiles:(NSArray *)profileData;

+ (NSArray *)getLinkedProfiles;

+ (void)setCaptureClientId:(NSString*)captureClientId;

+ (void)setCaptureBaseUrl:(NSString *)baseUrl;

- (NSString *)downloadedFlowVersion;

- (NSString *)redirectUri;

- (void)loadFlow;

- (NSString *)getForgottenPasswordFieldName;

- (NSString *)responseType:(id)delegate;
@end
