//
//  SDDownloadUrl.h
//  SevenDigital
//
//  Created by Daniel Too on 15/04/14.
//  Copyright (c) 2014 7 Digital. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SDDownloadUrl : NSObject

/*
 
 This object represents a server recommended download format
 
 */

@property (strong, nonatomic) NSString *downloadUrlString;

@property (assign, nonatomic) NSInteger formatId;

@property (strong, nonatomic) NSString *fileFormat;

@property (assign, nonatomic) NSInteger bitRate;

@property (assign, nonatomic) BOOL isDrmFree;

- (id)initWithDictionary:(NSDictionary *)apiDictionary;

@end
