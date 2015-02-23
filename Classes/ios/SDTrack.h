//
//  SDTrack.h
//  7digital
//
//  Created by Daniel Too on 3/04/14.
//  Copyright (c) 2014 7digital. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SDArtist;

/**
 
 This is an object to represent a 7Digital Track
 
 */

@interface SDTrack : NSObject

@property (assign, nonatomic) NSInteger trackId;

@property (strong, nonatomic) NSString *title;

@property (assign, nonatomic) NSInteger version;

@property (assign, nonatomic) NSInteger trackNumber;

@property (assign, nonatomic) NSInteger duration;

@property (strong, nonatomic) NSString *isrc; //International Standard Recording Code

@property (strong, nonatomic) NSString *SDURL;

@property (strong, nonatomic) SDArtist *artist;

@property (strong, nonatomic) NSArray *downloadUrls;

//As some tracks have a limit on how many times a user can download a track.
@property (assign, nonatomic) NSInteger downloadsRemainingCount;

@property (strong, nonatomic) NSString *purchaseDateString;

- (id)initWithDictionary:(NSDictionary *)apiDictionary;

@end
