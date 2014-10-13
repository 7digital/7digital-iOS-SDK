//
//  SDPlaylist.h
//  SevenDigital
//
//  Created by Ryan Smale on 19/06/14.
//  Copyright (c) 2014 7 Digital. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SDPlaylist : NSObject


/**
 create a playlist and it returns the playlistID for your playlist, handy to keep refrence for any localy stored 
 
 @param title           The title of your playlist
 @param tracksArray     A array with the track dictionaries inside.
 
 @returns the playlistID
 **/

+(void)createPlaylistWithTitle:(NSString*)title withTracksArray:(NSArray*)tracksArray returningPlaylistID:(void(^)(NSString* playlistID))completion;

@end
