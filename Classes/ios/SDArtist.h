//
//  SDArtist.h
//  7digital
//
//  Created by Daniel Too on 4/04/14.
//  Copyright (c) 2014 7digital. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SDArtist : NSObject

/**
 
 This is an object to represent an Artist.
 
 */

@property (assign, nonatomic) NSInteger artistId;

@property (strong, nonatomic) NSString *artistName;

@property (strong, nonatomic) NSString *artistAppearsAs;

@property (strong, nonatomic) NSString *SDURL;

- (id)initWithDictionary:(NSDictionary *)apiDictionary;


@end
