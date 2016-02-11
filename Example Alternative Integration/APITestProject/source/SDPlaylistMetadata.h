//
//  SDPlaylistMetadata.h
//  SevenDigital
//
//  Created by Ryan Smale on 22/12/15.
//  Copyright © 2015 7digital. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SDPlaylistMetadata : NSObject

@property (nonatomic, strong) NSString *playlistTitle;

@property (nonatomic, strong) NSString *playlistID;

@property (nonatomic, assign) BOOL publicPlaylist;

@property (nonatomic, strong) NSDate *lastUpdated;

@property (nonatomic, assign) NSInteger trackCount;

@property (nonatomic, strong) NSString *imageURlString;

//these two I dont use so I'm just gonna pass you the array of NSDictionaries.
@property (nonatomic, strong) NSArray *annotations;
@property (nonatomic, strong) NSArray *links;

@end
