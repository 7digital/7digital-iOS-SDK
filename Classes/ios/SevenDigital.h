//
//  SevenDigital.h
//  7digital
//
//  Created by Daniel Too on 31/03/14.
//  Copyright (c) 2014 7digital. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SDAPIRequest.h"
#import "SDAPIResponse.h"
#import "SDDownloadUrl.h"
#import "SDLockerHelper.h"
#import "SDMedia.h"
#import "SDPlaylistHelper.h"
#import "SDUserAccountSetup.h"

#import <UIKit/UIKit.h>

#define SDAuthenticationChangedNotification @"SDAuthenticationChangedNotification"

@interface SevenDigital : NSObject

@property (nonatomic, readonly) NSString *currentUser;
@property (nonatomic, readonly) BOOL isCurrentUserAuthenticated;

@property (nonatomic, retain) NSNumber * serverOffset;

/**@brief reusable singleton for calling api methods*/
+ (SevenDigital *)sharedInstance;


/**
   Initializes the 7digital API with your consumer key and secret.

   @see Register as a developer at https://api-signup.7digital.com for more information
   @param key     Your 7digital Consumer Key
   @param secret  Your 7digital Consumer Secret

 */
+ (void)initializeWithConsumerKey:(NSString *)key andSecret:(NSString *)secret;


//
// General API Requests
//

/**
   Creates and sends an API call to the 7digital API.
   Example usage:
   @code
   SDAPIRequest *chartRequest = [[SDAPIRequest alloc] initWithPath:@"/release/chart" method:SDHTTPMethodGet params:@{@"country":@"GB"}];

   [[SevenDigital sharedInstance] performRequest:chartRequest onSuccess:^(SDAPIResponse *apiResponse) {
    NSDictionary *responseDictionary = apiResponse.responseItem;
    SDLog(@"successful call %@", responseDictionary);
   } onFailure:^(NSError *error) {
    SDLog(@"failure %@", error);
   }];
   @endcode

   @param request         A request with a relative URL and parameters for the API call
   @param successBlock    A handler for the api response
   @param failureBlock    A handler for any api errors

 */

- (void)performRequest:(SDAPIRequest *)request
        onSuccess:(void (^)(SDAPIResponse* apiResponse))successBlock
        onFailure:(void (^)(NSError *error))failureBlock;


/**
   Creates an NSURL which contains all of the oauth parameters. Useful as a helper to get
   tracks.

   @param url             The path as an NSURL that we would like to request from
   @param params          A dictionary with any url parameters

   @return an oauth-ready NSURL

 */

- (NSURL *)authenticatedURLWithURL:(NSURL *)url params:(NSDictionary *)params;

//
//\\Authentication with the 7digital API
//
// Login and logout methods



//\\General Access Key Login Method
/**
   Authenticates the user with the server by handling login by presenting a modal webview for the user to enter their details on the seven digital website.
   @param presentingFromView      The view presenting modaly the login page.

 */
-(void)presentLoginWebViewFromView:(UIViewController*)presentingFromView;



//\\Premium Login Requests
/**
   Logs a user into their 7digital account

   Requires Premium API Access! to inquire about gaining Premium API contact us at http://about.7digital.com/contact-us

   @param username        The user's 7digital account username or email address
   @param password        The user's 7digital account password
   @param successBlock    A handler for the success block, which also returns the logged in user's username

 */
- (void)loginUsername:(NSString*)username
        password:(NSString*)password
        onSuccess:(void (^)(NSString *username))successBlock
        onError:(void (^)(NSError *error))failureBlock;


- (void)loginWithUsername:(NSString*)username
        password:(NSString*)password;



/**
   Logs a user out of their 7digital account

 */

- (void)logout;

/**
    methods to force the calculating the server offset.
    this should usually generate itself on requests but i like to call it on applicationDidFinishLaunching
 */
- (void)calculateServerOffsetWithCompletion:(void (^)())completion;

- (void)calculateServerOffset;


@end
