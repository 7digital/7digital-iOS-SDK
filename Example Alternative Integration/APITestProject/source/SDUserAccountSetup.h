//
//  SDUserAccountSetup.h
//  SevenDigital
//
//  Created by Ryan Smale on 11/12/15.
//  Copyright © 2015 7digital. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SDAPIResponse;

@interface SDUserAccountSetup : NSObject

#pragma mark - New user creation
/** 
    Sign up a new user for an 7digital account
 
    @param email        the users email adress.
    @param password     the users desired password.
 
    @return an success BOOL and NSError which is nil on success.
*/
+ (void)newUserWithEmail:(NSString*)email andPassword:(NSString*)password withCompletion:(void(^)(BOOL success, NSError * error))completion;

/**
 Sign up a new partner user
 
 @param partnerID              your partner ID.
 @param signUpEmailAddress     your users email address.
 
 @return an success BOOL and NSError which is nil on success.
 */
+ (void)newPartnerUser:(NSString*)partnerID withEmailAddress:(NSString*)signUpEmailAddress withCompletion:(void(^)(BOOL success, NSError * error))completion;

/**
    Set up a user for streaming
 
    @param allowOffline         whether or not the user has access to offline streaming
    @param usersCountry         country code of the user
 
    @return completion contains a success BOOL and NSError which is nil on success
 
 */

+ (void)authoriseDeviceForUnlimitedStreaming:(BOOL)allowOffline usersCountry:(NSString*)country withCompletion:(void(^)(BOOL success, NSError * error))completion;

+ (void)subscriptionStatusForCurrentUserWithCountry:(NSString*)country withCompletion:(void(^)(SDAPIResponse *response, NSString *level, NSDate *expiryDate, NSError * error))completion;

#pragma mark - Authorize device for off-line streaming
//Used to authorise a device for offline mode. After authorised, a device can download in bulk from the offline/subscription endpoint.

/**
 Authorise Offline Streaming for the user
 
 @param allowUnlimitedStreaming        bool for authorise or unauthorise
 @param country                        the users country of usage (this may be removed later)
 
 @return an success BOOL and NSError which is nil on success.
 */

+ (void)authoriseDeviceForOfflineStreaming:(BOOL)allowOffline usersCountry:(NSString*)country withCompletion:(void(^)(BOOL success, NSError * error))completion;





@end
