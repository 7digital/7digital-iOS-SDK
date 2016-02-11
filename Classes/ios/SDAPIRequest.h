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
@property (nonatomic, copy) NSData * bodyData;
@property (nonatomic, strong) NSURL *fixedURL;
@property (nonatomic, strong) NSString *acceptHeader;

- (id)initWithPath:(NSString *)path;
- (id)initWithPath:(NSString *)path params:(NSDictionary *)params;


/**
 Creates a SDAPIRequest object to use with the performRequest:onSuccess:onFailure: call in SevenDigital.h
 
 @see SevenDigital
 @param path    The api path (for example: /user/locker)
 @param method  One of SDHTTPMethodGet, SDHTTPMethodPut or SDHTTPMethodPost
 @param params  A dictionary of parameters, as defined by the required and optional parameters from the API docs. see http://developer.7digital.com/resources/api-docs/introduction for more information. 
 
 note: you should always send through a country code, as determined by
 @code
 NSString *countryCode = [[NSLocale currentLocale] objectForKey: NSLocaleCountryCode];
 @endcode
 
 */

- (id)initWithPath:(NSString *)path method:(NSString *)method params:(NSDictionary *)params;


/**
 extra nsdata for posting json for playlist api calls etc.
 **/
- (id)initWithPath:(NSString *)path method:(NSString *)method params:(NSDictionary *)params withJsonData:(NSData*)bodyData;

- (id)initWithFixedURL:(NSURL *)fixedURL;

@end
