//
//  SDPlaylistTrack.h
//  SevenDigital
//
//  Created by Ryan Smale on 30/09/15.
//  Copyright © 2015 7 Digital. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SDPlaylistTrack : NSObject

//the unique identifer for this track in the playlist.
@property (strong, nonatomic) NSString * playlistTrackID;

//the general track ID (may match to a track of origin 7digital, iTunes, Android)
@property (strong, nonatomic) NSString * trackID;

@property (strong, nonatomic) NSString * trackTitle;

@property (strong, nonatomic) NSString * artistAppearsAs;

//release properties
@property (assign, nonatomic) NSInteger releaseId;

@property (strong, nonatomic) NSString * releaseTitle;

@property (strong, nonatomic) NSString * releaseArtistAppearsAs;

@property (strong, nonatomic) NSString * releaseVersion;

//the source of the track (i'm using "7digital" for 7digital tracks, and "itunes" for my users itunes tracks)
@property (strong, nonatomic) NSString * source;

@property (strong, nonatomic) NSString * audioUrl;

@property (strong, nonatomic) NSDictionary * user;

@property (strong, nonatomic) NSDate * dateAdded;

@property (strong, nonatomic) NSString * imageString;


//population method pass a single dictionary from the tracks array to populate
- (id)initWithDictionary:(NSDictionary *)apiDictionary;


@end
