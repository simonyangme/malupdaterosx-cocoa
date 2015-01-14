//
//  MyAnimeList.h
//  MAL Updater OS X
//
//  Created by James M. on 8/7/10.
//  Copyright 2009-2014 Atelier Shiori. All rights reserved. Code licensed under New BSD License
//

#import <Cocoa/Cocoa.h>
#import <OgreKit/OgreKit.h>
#import "MAL_Updater_OS_XAppDelegate.h"

@interface MyAnimeList : NSObject {
	NSString * Base64Token;
	NSString * MALApiUrl;
	NSString * LastScrobbledTitle;
	NSString * LastScrobbledEpisode;
	NSString * LastScrobbledActualTitle;
	NSDictionary * LastScrobbledInfo;
	NSString * DetectedTitle;
	NSString * DetectedEpisode;
    BOOL DetectedTitleisMovie;
    int DetectedSeason;
	NSString * DetectedCurrentEpisode;
	NSString * TotalEpisodes;
	NSString * WatchStatus;
	NSString * TitleScore;
	NSString * TitleState;
    NSString * AniID;
	BOOL LastScrobbledTitleNew;
	BOOL confirmed;
	BOOL Success;
    BOOL online;
	BOOL correcting;
	int choice;
}
- (int)startscrobbling;
-(int)scrobbleagain:(NSString *)showtitle Episode:(NSString *)episode;
-(int)scrobble;
-(BOOL)confirmupdate;
-(BOOL)updatestatus:(NSString *)titleid
              score:(int)showscore
        watchstatus:(NSString*)showwatchstatus;
-(bool)removetitle:(NSString *)titleid;
-(NSString *)getLastScrobbledTitle;
-(NSString *)getLastScrobbledEpisode;
-(NSString *)getLastScrobbledActualTitle;
-(NSString *)getAniID;
-(NSString *)getTotalEpisodes;
-(int)getCurrentEpisode;
-(BOOL)getConfirmed;
-(int)getScore;
-(int)getWatchStatus;
-(BOOL)getSuccess;
-(BOOL)getisNewTitle;
-(NSDictionary *)getLastScrobbledInfo;
-(void)clearAnimeInfo;
@end
