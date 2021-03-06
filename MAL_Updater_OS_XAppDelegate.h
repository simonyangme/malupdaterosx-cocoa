//
//  MAL_Updater_OS_XAppDelegate.h
//  MAL Updater OS X
//
//  Created by James M. on 8/7/10.
//  Copyright 2009-2015 Atelier Shiori. All rights reserved. Code licensed under New BSD License
//

#import <Cocoa/Cocoa.h>

@class MyAnimeList;
@class FixSearchDialog;
@class HistoryWindow;
@interface MAL_Updater_OS_XAppDelegate : NSObject <NSApplicationDelegate, NSUserNotificationCenterDelegate, NSSharingServiceDelegate> {
	/* Windows */
    __unsafe_unretained NSWindow *window;
	__unsafe_unretained NSWindow *updatepanel;
	/* General Stuff */
	IBOutlet NSMenu *statusMenu;
    NSStatusItem                *statusItem;
    NSImage                        *statusImage;
    NSManagedObjectModel *managedObjectModel;
	NSManagedObjectContext *managedObjectContext;
	NSPersistentStoreCoordinator *persistentStoreCoordinator;
	NSTimer * timer;
	IBOutlet NSMenuItem * togglescrobbler;
    IBOutlet NSMenuItem * updatenow;
	IBOutlet NSMenuItem * confirmupdate;
    IBOutlet NSMenuItem * findtitle;
    /* Updated Title Display and Operations */
    IBOutlet NSMenuItem * seperator;
    IBOutlet NSMenuItem * lastupdateheader;
    IBOutlet NSMenuItem * updatecorrectmenu;
    IBOutlet NSMenu * updatecorrect;
    IBOutlet NSMenuItem * updatedtitle;
    IBOutlet NSMenuItem * updatedepisode;
    IBOutlet NSMenuItem * seperator2;
    IBOutlet NSMenuItem * updatedcorrecttitle;
    IBOutlet NSMenuItem * updatedupdatestatus;
    IBOutlet NSMenuItem *shareMenuItem;
    IBOutlet NSMenu * shareMenu;
    /* Status Window */
	IBOutlet NSTextField * ScrobblerStatus;
	IBOutlet NSTextField * LastScrobbled;
    IBOutlet NSTextView * animeinfo;
    IBOutlet NSImageView * img;
    IBOutlet NSVisualEffectView * windowcontent;
    IBOutlet NSScrollView *animeinfooutside;
	int choice;
	BOOL scrobbling;
    BOOL scrobbleractive;
    bool panelactive;
	NSArray * shareItems;
	/* MAL Scrobbling/Updating Class */
	MyAnimeList * MALEngine;
	/* Update Status Sheet Window IBOutlets */
	IBOutlet NSToolbarItem * updatetoolbaritem;
    IBOutlet NSToolbarItem * correcttoolbaritem;
    IBOutlet NSToolbarItem * sharetoolbaritem;
    IBOutlet NSToolbarItem * openAnimePage;
	IBOutlet NSTextField * showtitle;
	IBOutlet NSPopUpButton * showstatus;
	IBOutlet NSPopUpButton * showscore;
    IBOutlet NSTextField * episodefield;
    IBOutlet NSNumberFormatter * epiformatter;
	NSWindowController *_preferencesWindowController;
}
@property (nonatomic, readonly) NSWindowController *preferencesWindowController;
@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet NSWindow *updatepanel;
@property (nonatomic, retain, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property (nonatomic, retain, readonly) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, retain, readonly) NSManagedObjectContext *managedObjectContext;
@property(strong) FixSearchDialog *fsdialog;
@property (strong) HistoryWindow * historywindowcontroller;

-(void)showhistory:(id)sender;
-(IBAction)togglescrobblewindow:(id)sender;
-(void)setStatusToolTip:(NSString*)toolTip;
-(IBAction)toggletimer:(id)sender;
-(void)autostarttimer;
-(void)firetimer:(NSTimer *)aTimer;
-(void)starttimer;
-(void)stoptimer;
-(void)setStatusText:(NSString*)messagetext;
-(void)setLastScrobbledTitle:(NSString*)messagetext;
-(void)setStatusMenuTitleEpisode:(NSString *)title episode:(NSString *) episode;
-(IBAction)updatestatus:(id)sender;
-(IBAction)updatestatusmenu:(id)sender;
-(void)showUpdateDialog:(NSWindow *) w;
-(IBAction)updatenow:(id)sender;
-(IBAction)closeupdatestatus:(id)sender;
-(IBAction)updatetitlestatus:(id)sender;
-(IBAction)showPreferences:(id)sender;
-(IBAction)getHelp:(id)sender;
- (void)appendToAnimeInfo:(NSString*)text;
-(void)showNotification:(NSString *)title message:(NSString *) message;
-(IBAction)showAboutWindow:(id)sender;
-(bool)getisScrobbling;
-(bool)getisScrobblingActive;
-(NSDictionary *)getNowPlaying;
-(NSManagedObjectContext *)getObjectContext;
-(MyAnimeList *)getMALEngineInstance;
@end
