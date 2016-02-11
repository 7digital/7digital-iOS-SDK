//
//  SDSearch.h
//  SevenDigital
//
//  Created by Ryan Smale on 15/12/15.
//  Copyright © 2015 7 Digital. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SDSearch : NSObject

//Artist
/**
 a basic search.
 
 @param searchString    the string to search for.
 
 @return an success BOOL an NSArray of SDArtist objects and NSError which is nil on success.
 */

+(void)simpleSearchArtistsWithString:(NSString*)searchString withCompletion:(void(^)(BOOL success, NSArray * artistsArray, NSError * error))completion;

/**
 Search for Artist.
 
 @param searchString    the string to search for.
 @param streamable      optional parameter if set will return only streamable or non streamable artists.
 @param sortString      this is the string to set the sorting field. string should be formatted  "{sortColumn} {sortOrder}" when not specified the string is equvalent to "{core desc} {ascending}".
 @param countryCode     country catalougue the search is being searched against.
 @param page            what page number you want back, starts with 1.
 @param pageSize        how many items you want back in a page
 
@return an success BOOL an NSArray of SDArtist objects, a count of the number of items that match search parameters and NSError which is nil on success.
 */

+(void)searchArtistsWithString:(NSString*)searchString whoAreStreamable:(BOOL*)streamable withSortString:(NSString*)sortString fromCountryCatalougue:(NSString*)countryCode page:(int)page pageSize:(int)pageSize withCompletion:(void(^)(BOOL success, NSArray * artistsArray, NSInteger totalMatchingSearchItems , NSError * error))completion;


//Release
/**
 Search for Release.
 
 @param searchString    the string to search for.
 @param streamable      optional parameter if set will return only streamable or non streamable artists.
 @param releaseType     Filter results via type of album,single,video as a string.
 @param countryCode     country catalougue the search is being searched against.
 @param page            what page number you want back, starts with 1.
 @param pageSize        how many items you want back in a page
 
 @return an success BOOL an NSArray of SDRelease objects, a count of the number of items that match search parameters and NSError which is nil on success.
 */
+(void)searchReleasesWithString:(NSString*)searchString thatAreStreamable:(BOOL*)streamable ofType:(NSString*)releaseType fromCountryCatalougue:(NSString*)countryCode page:(int)page pageSize:(int)pageSize withCompletion:(void(^)(BOOL success, NSArray * releasesArray, NSInteger totalMatchingSearchItems , NSError * error))completion;

//tracks
/**
 Search for Tracks.
 
 @param searchString    the string to search for.
 @param streamable      optional parameter if set will return only streamable or non streamable artists.
 @param packageIdsString    string of desired packages seperated by comma.
 @param countryCode     country catalougue the search is being searched against.
 @param page            what page number you want back, starts with 1.
 @param pageSize        how many items you want back in a page
 
 
 @return an success BOOL an NSArray of SDTrack objects, a count of the number of items that match search parameters and NSError which is nil on success.
 */
+(void)searchTracksWithString:(NSString*)searchString thatAreStreamable:(BOOL*)streamable forPackageIds:(NSString*)packageIdsString fromCountryCatalougue:(NSString*)countryCode page:(int)page pageSize:(int)pageSize withCompletion:(void(^)(BOOL success, NSArray * releasesArray, NSInteger totalMatchingSearchItems , NSError * error))completion;


@end
