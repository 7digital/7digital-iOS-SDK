//
//  SDStreamingHelper.h
//  SevenDigital
//
//  Created by Daniel Too on 13/01/16.
//  Copyright © 2016 7 Digital. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SDAPIResponse.h"

@interface SDStreamingHelper : NSObject

typedef NS_ENUM(NSInteger, kSDUsageType) {
    kSDUsageTypeDownload = 0,           // Suitable for downloading for offline play.
    kSDUsageTypeSubscriptionStreaming,  // Suitable for streaming
    kSDUsageTypeAdSupportedStreaming,   // Suitable for ad-supported free content and previews
    kSDUsageTypeCount
};

+ (void)requestTracksForReleaseId:(NSInteger)releaseId usageType:(kSDUsageType)usageType params:(NSDictionary *)params completion:(void(^)(SDAPIResponse *response, NSArray *tracks, NSError *error))completion;

@end
