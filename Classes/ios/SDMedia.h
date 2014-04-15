//
//  SDMedia.h
//  SevenDigital
//
//  Created by Daniel Too on 3/04/14.
//  Copyright (c) 2014 7digital. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SDTrack;

typedef NS_ENUM(NSInteger, kSDMediaType) {
    kSDMediaTypeDownload = 0,            // Suitable for downloading for offline play.
    kSDMediaTypeDownloadHighQuality,     // Downloads in 320 AAC
    kSDMediaTypeDownloadStandardQuality, // Downloads in 128 MP3 
    kSDMediaTypeStreamingLocker,        // Suitable for streaming purchased content from the user's locker
    kSDMediaTypeStreamingSubscription,  // Suitable for streaming from a paid subscription, and is licensed differently
    kSDMediaTypeStreamingInternetRadio, // Suitable for ad-supported free content and previews
    kSDMediaTypeCount
};

@interface SDMedia : NSObject


/**
 Returns a URL for a 7digital track appropriate for streaming or downloading.  The NSURL will contain all of the appropriate oAuth parameters for the logged in user.
 See the 7Digital media API at http://developer.7digital.com/resources/api-docs/media-delivery-api
 
 @see kSDMediaType for
 @param track           The SDTrack object for the song
 @param mediaType       one of the kSDMediaType options for the appropriate type of file.
 
 */
+ (NSURL *)urlForTrack:(SDTrack *)track mediaType:(kSDMediaType)mediaType;

@end
