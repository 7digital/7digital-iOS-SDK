//
//  SDAPIRequest.h
//  7digital
//
//  Created by Tim Ross on 22/05/13.
//  Copyright (c) 2013 7digital. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SDHTTPMethodGet @"GET"
#define SDHTTPMethodPut @"PUT"
#define SDHTTPMethodPost @"POST"

@interface SDAPIRequest : NSObject

@property (nonatomic, copy) NSString *method;
@property (nonatomic, copy) NSString *path;
@property (nonatomic, strong) NSDictionary *params;
@property (nonatomic, strong) NSURL *fixedURL;

- (id)initWithPath:(NSString *)path;
- (id)initWithPath:(NSString *)path params:(NSDictionary *)params;
- (id)initWithPath:(NSString *)path method:(NSString *)method params:(NSDictionary *)params;
- (id)initWithFixedURL:(NSURL *)fixedURL;

@end
