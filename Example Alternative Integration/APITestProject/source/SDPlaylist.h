//
//  SDPlaylist.h
//  SevenDigital
//
//  Created by Ryan Smale on 19/06/14.
//  Copyright (c) 2014 7 Digital. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SDPlaylistTrack.h"

@interface SDPlaylist : NSObject


/**
 create a playlist and it returns the playlistID for your playlist, handy to keep refrence for any localy stored 
 
 @param title           The title of your playlist
 @param tracksArray     A array with the track dictionaries inside.
 
 @return the playlistID
 **/

+(void)createPlaylistWithTitle:(NSString*)title withTracksArray:(NSArray*)tracksArray returningPlaylistID:(void(^)(NSString* playlistID, NSArray* tracksArray))completion;


/**
 Get an array of users playlists.
 
 @param pageSize    Optional parameter for how many playlists you want to return from your call.
 @param page        an optional parameter to set a specific page of of playlists you want returned
 @param userID      a optional parameter to returns a specific users public playlists
 
 @return an array of SDPlaylistHeader's
 **/

+(void)getPlaylists:(NSInteger*)pageSize page:(NSInteger*)page forOptionalSpecificUserID:(NSString*)userID returningPlaylistsArray:(void(^)(NSArray * playlistsArray, NSInteger* totalNumberOfPlaylists, NSError * error)) completion;


/**
 Get tracks for a specific playlist.
 
 @param playlsitID    Optional parameter for how many playlists you want to return from your call.
 
 @return the array of playlistTracks and a NSError for unsuccessful states.
 **/

+(void)getPlaylistTracksForPlaylistID:(NSString*)playlistID withCompetion:(void(^)(NSArray * playlistTrackArray, NSError * error))completion;


@end

