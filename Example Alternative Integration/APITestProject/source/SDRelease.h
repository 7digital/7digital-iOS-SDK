//
//  SDRelease.h
//  7digital
//
//  Created by Daniel Too on 3/04/14.
//  Copyright (c) 2014 7digital. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SDArtist.h"


/**
 
 This is an object to represent a 7Digital Release (An album, single, EP etc)
 
 */

@interface SDRelease : NSObject

@property (assign, nonatomic) NSInteger releaseId;

@property (strong, nonatomic) NSString *releaseTitle;

@property (assign, nonatomic) NSInteger version;

@property (strong, nonatomic) NSString *releaseType;

@property (assign, nonatomic) NSInteger barcode;

@property (strong, nonatomic) SDArtist *artist;

@property (strong, nonatomic) NSString *SDURL;

@property (strong, nonatomic) NSString *imageURL;

@property (strong, nonatomic) NSDate *releaseDate;

@property (strong, nonatomic) NSArray *tracks;


/**
 
 Takes in the data from an API call after it has been transformed into a dictionary, and turns it into a SD Release object, with any related tracks and artists.
 
 @param apiDictionary
 
 */

- (id)initWithDictionary:(NSDictionary *)apiDictionary;

@end
