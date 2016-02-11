//
//  SDPlaylistHeader.h
//  SevenDigital
//
//  Created by Ryan Smale on 22/12/15.
//  Copyright © 2015 7 Digital. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SDPlaylistHeader : NSObject


@property (nonatomic,strong) NSString * playlistTitle;
@property (nonatomic,strong) NSString * playlistID;
@property (nonatomic) BOOL publicPlaylist;
@property (nonatomic,strong) NSDate * lastUpdated;
@property (nonatomic) NSInteger * trackCount;
@property (nonatomic,strong) NSString * imageURlString;
//these two I dont use so I'm just gonna pass you the array of NSDictionaries.
@property (nonatomic,strong) NSArray * annotations;
@property (nonatomic,strong) NSArray * links;

@end
