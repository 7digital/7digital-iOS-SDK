//
//  SDStreamLogging.h
//  SevenDigital
//
//  Created by Ryan Smale on 14/12/15.
//  Copyright © 2015 7digital. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SDStreamLogging : NSObject


#pragma mark - enums for the methods so we can send the correct string to the api.

// how was the track played for subscription user.
	typedef enum Playmode : NSUInteger {
	playModeOnline = 0,
	playModeOffline = 1,
	playModeOnlineCached = 2
} Playmode;

// the reason playback ended for catalouge stream.
typedef enum endReason : NSUInteger {
	endedNaturalEnd = 0,
	endedUserSkipped = 1,
	endedOther = 2
} endReason;


#pragma mark - stream reporting methods.

/**
   Report a subscription stream.

   @param trackID         the 7digital id for the track.
   @param releaseID       the 7digital release id the track is from.
   @param trackFormatID   Format id of the track usually a 2 digit int.
   @param playDate        the date with time the stream begun.
   @param timePlayed      the duration of the play, send 0 if it was just precaching.
   @param playmode        enum starting with playMode for offline, online, onlineCached.


   @return an success BOOL and NSError which is nil on success.
 */

+(void) reportSubscriptionStreamForTrack:(int)trackID fromRelease:(int)releaseID trackFormatID:(int)trackformatID datePlayed:(NSDate*)playDate totalTimePlayed:(float)timePlayed forPlaymode:(Playmode)playmode withCompletion:(void (^)(BOOL success, NSError * error))completion;

/**
   Sign up a new partner user.

   @param trackID         the 7digital id for the track.
   @param releaseID       the 7digital release id the track is from.
   @param trackFormatID   Format id of the track usually a 2 digit int.
   @param playDate        the date with time the stream begun.
   @param timePlayed      the duration of the play, send 0 if it was just precaching.
   @param userID          the users unique identifier.
   @param endReason       enum starting with ended for naturalEnd, userSkipped, other.

   @return an success BOOL and NSError which is nil on success.
 */

+(void) reportCatalougueStreamForTrack:(int)trackID fromRelease:(int)releaseID trackFormatID:(int)trackformatID datePlayed:(NSDate*)playDate totalTimePlayed:(float)timePlayed userID:(NSString*)userID endedDueTo:(endReason*)endReason withCompletion:(void (^)(BOOL success, NSError * error))completion;

@end
