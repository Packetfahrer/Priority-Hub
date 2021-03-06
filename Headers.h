//Headers.h
#import <SpringBoard/SBApplicationIcon.h>
#import <SpringBoard/SBAwayListItem.h>
// #import <SpringBoard/SBApplicationController.h>
#import <CoreGraphics/CoreGraphics.h>

@interface SBApplicationController
+ (id)sharedInstance;
- (id)applicationWithBundleIdentifier:(NSString*)id;
- (id)applicationWithDisplayIdentifier:(NSString*)id;
@end

@protocol SBLockScreenNotificationModel
- (SBAwayListItem *)listItemAtIndexPath:(NSIndexPath *)arg1;
@end

@interface BBBulletin
@property(copy, nonatomic) NSString *sectionID; // @synthesize sectionID=_sectionID;
@end

@interface BBObserver
- (void)clearSection:(NSString*)arg1;
@end

@interface SBAwayBulletinListItem
@property(retain) BBBulletin* activeBulletin;
-(Class)class;
@end

@interface SBLockScreenNotificationTableView : UITableView
@end

@interface SBLockScreenNotificationCell {
	UIView* _topSeparatorView;
	UIView* _bottomSeparatorView;
}
-(id)initWithStyle:(long long)style reuseIdentifier:(NSString*)identifier;
@end

@interface SBLockScreenNotificationListView : UIView {
	UITableView* _tableView;
	UIView* _containerView;
	id<SBLockScreenNotificationModel> _model;
}
@property(assign, nonatomic) id<SBLockScreenNotificationModel> model;
- (void)_cellTextFadeTimerFired:(id)arg1;
- (void)_textDisabledTimerFired:(id)arg1;
- (void)_clearTextFadeTimer;
- (void)_clearTextDisabledTimer;
- (void)_resetAllFadeTimers;
-(void)resetTimers;
-(void)_resetAllFadeTimers;
-(BOOL)_disableIdleTimer:(BOOL)timer;
-(CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath;
-(void)setInScreenOffMode:(BOOL)screenOffMode;
-(void)addSubview:(UIView*)arg1;
@end

@interface SBLockScreenNotificationListController {
	SBLockScreenNotificationListView* _notificationView;
	NSMutableArray* _listItems;
  BBObserver* _observer;
}
-(id)listItemAtIndexPath:(NSIndexPath*)indexPath;
-(void)observer:(BBObserver*)observer removeBulletin:(BBBulletin*)bulletin;
-(void)observer:(BBObserver*)observer addBulletin:(BBBulletin*)bulletin forFeed:(unsigned long long)feed;
-(void)loadView;
-(int)count;
@end

@interface CTCallCenter
@property(retain) NSSet *currentCalls;
@end

@interface IMAVCallManager
+(instancetype)sharedInstance;
-(BOOL)hasActiveCall;
@end
