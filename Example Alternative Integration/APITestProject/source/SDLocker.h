//
//  SDLocker.h
//  7digital
//
//  Created by Daniel Too on 3/04/14.
//  Copyright (c) 2014 7digital. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SDRelease.h"
#import "SDTrack.h"
#import "SDArtist.h"

/**
 
 This is a request to return releases from a user's locker (library of all purchased tracks).
 
 */

@class SDAPIResponse;

@interface SDLocker : NSObject

+ (void)requestLockerForCurrentUserWithParams:(NSDictionary *)params completion:(void(^)(SDAPIResponse *response, NSArray *releasesArray, NSError *error))completion;


@end
