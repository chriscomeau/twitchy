//
//  TwitchAPIClient.h
//  Twitchy
//
//  Created by James Eunson on 4/04/2016.
//  Copyright © 2016 JEON. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TwitchStream.h"
#import "TwitchGame.h"
#import "TwitchGameListing.h"
#import "TwitchFeaturedStreamListing.h"
#import "TwitchVideo.h"
#import "TwitchUser.h"

#import "TwitchAPIKeys.h"

#define kAPIBaseURL @"https://api.twitch.tv/kraken"
#define kAPIAccessTokenBaseURL @"https://api.twitch.tv"
#define kAPIUsherBaseURL @"http://usher.twitch.tv"

#define kAPITwitchyBackendURL @"http://twitchy.jeon.com.au/api"

#define kTwitchAPIClientEmoticonsFinishedLoadingNotification @"kTwitchAPIClientEmoticonsFinishedLoadingNotification"

@interface TwitchAPIClient : NSObject

+ (TwitchAPIClient*)sharedClient;

// Games
- (void)loadTopGamesWithPageNumber:(NSInteger)pageNumber withCompletion: (void (^)(NSArray * result, BOOL pagesRemaining))completion;
- (void)loadTopGamesWithCompletion: (void (^)(NSArray * result, BOOL pagesRemaining))completion;

// Videos
- (void)loadTopVideosWithCompletion: (void (^)(NSArray * result, BOOL pagesRemaining))completion;
- (void)loadTopVideosWithPageNumber:(NSInteger)pageNumber withCompletion: (void (^)(NSArray * result, BOOL pagesRemaining))completion;

// Streams
- (void)loadTopStreamsWithCompletion: (void (^)(NSArray * result, BOOL pagesRemaining))completion;
- (void)loadTopStreamsWithGameFilter:(TwitchGame*)game withCompletion: (void (^)(NSArray * result, BOOL pagesRemaining))completion;
- (void)loadTopStreamsWithGameFilter:(TwitchGame*)game withPageNumber:(NSInteger)pageNumber withCompletion: (void (^)(NSArray * result, BOOL pagesRemaining))completion;

// Featured
- (void)loadFeaturedStreamsWithCompletion: (void (^)(NSArray * result))completion;

// Authentication
- (void)loadAccessTokenForVideo:(TwitchVideo*)video withCompletion: (void (^)(NSDictionary * result))completion;
- (void)loadAccessTokenForChannel:(TwitchChannel*)channel withCompletion: (void (^)(NSDictionary * result))completion;

// Search
- (void)searchGamesWithQuery:(NSString*)query withCompletion:(void (^)(NSArray * result))completion;
- (void)searchStreamsWithQuery:(NSString*)query withCompletion:(void (^)(NSArray * result))completion;

// Chat Emoticons
- (void)loadChatEmoticonsWithCompletion:(void (^)(NSString * result))completion;

// OAuth Authentication
- (void)getOAuthTokenWithCompletion: (void (^)(NSDictionary * result))completion;
- (void)checkOAuthAuthenticationStatusWithCode:(NSString*)code completion: (void (^)(NSDictionary * result))completion;

// OAuth Logged in Methods
- (void)loadUserDetails: (void (^)(TwitchUser * result))completion;
- (void)loadUserFollowedStreamsWithPageNumber:(NSInteger)pageNumber withCompletion:(void (^)(NSArray * result, BOOL pagesRemaining))completion;

// Helper methods
+ (NSURL*)generateStreamingURLForChannel:(TwitchChannel*)channel withToken:(NSDictionary*)token;
+ (NSURL*)generateVideoURLForVideo:(TwitchVideo*)video withToken:(NSDictionary*)token;

@end
