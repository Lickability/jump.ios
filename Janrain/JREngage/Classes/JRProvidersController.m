/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Copyright (c) 2010, Janrain, Inc.

 All rights reserved.

 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation and/or
     other materials provided with the distribution.
 * Neither the name of the Janrain, Inc. nor the names of its
     contributors may be used to endorse or promote products derived from this
     software without specific prior written permission.


 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 File:   JRProvidersController.m
 Author: Lilli Szafranski - lilli@janrain.com, lillialexis@gmail.com
 Date:   Tuesday, June 1, 2010
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#import "debug_log.h"
#import "JRSessionData.h"
#import "JRUserInterfaceMaestro.h"
#import "JREngage+CustomInterface.h"
#import "JRProvidersController.h"
#import "JRInfoBar.h"
#import "JRUserLandingController.h"
#import "JRWebViewController.h"

@interface UITableViewCellProviders : UITableViewCell
{
}
@end

@implementation UITableViewCellProviders

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    if ((self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]))
    {}

    return self;
}

- (void)layoutSubviews
{
    [super layoutSubviews];

    self.imageView.frame = CGRectMake(10, 10, 30, 30);
    self.textLabel.frame = CGRectMake(50, 15, 200, 22);
}
@end

@interface JRProvidersController ()
- (void)createConventionalSignInLoadingView;

@property(retain) NSMutableArray *providers;
@property(retain) UIView *myConventionalSignInLoadingView;
@end

@implementation JRProvidersController
{
    JRSessionData   *sessionData;
    NSDictionary    *customInterface;

    //BOOL iPad;
    //BOOL hidesCancelButton;
    //BOOL userHitTheBackButton;

    UIView      *titleView;
    //UIView      *myBackgroundView;
    UITableView *myTableView;

    /* Activity Spinner and Label displayed while the list of configured providers is empty */
    NSTimer *timer;
    UILabel                 *myLoadingLabel;
    //UIActivityIndicatorView *myActivitySpinner;

    JRInfoBar   *infoBar;
}

@synthesize providers;
@synthesize hidesCancelButton;
@synthesize myBackgroundView;
@synthesize myTableView;
@synthesize myLoadingLabel;
@synthesize myActivitySpinner;
@synthesize myConventionalSignInLoadingView;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
   andCustomInterface:(NSDictionary *)theCustomInterface
{
    if ((self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil]))
    {
        sessionData = [JRSessionData jrSessionData];
        customInterface = [theCustomInterface retain];
    }

    return self;
}

- (void)viewDidLoad
{
    DLog(@"");
    [super viewDidLoad];
    myTableView.backgroundColor = [UIColor clearColor];

    // If there is a UIColor object set for the background color, use this
    if ([customInterface objectForKey:kJRAuthenticationBackgroundColor])
        myBackgroundView.backgroundColor = [customInterface objectForKey:kJRAuthenticationBackgroundColor];

    // Weird hack necessary on the iPad, as the iPad table views have some background view that is always gray
    if ([myTableView respondsToSelector:@selector(setBackgroundView:)])
        [myTableView setBackgroundView:nil];

    titleView = [customInterface objectForKey:kJRProviderTableTitleView];

    if (!titleView)
    {
        UILabel *titleLabel = [[[UILabel alloc] initWithFrame:CGRectMake(0, 0, 180, 44)] autorelease];
        titleLabel.backgroundColor = [UIColor clearColor];
        titleLabel.font = [UIFont boldSystemFontOfSize:20.0];
        titleLabel.shadowColor = [UIColor colorWithWhite:0.0 alpha:0.5];
        titleLabel.textAlignment = JR_TEXT_ALIGN_CENTER;
        titleLabel.textColor = [UIColor whiteColor];

        NSString *l10n = ([customInterface objectForKey:kJRProviderTableTitleString]) ?
            [customInterface objectForKey:kJRProviderTableTitleString] : @"Sign in with...";
        titleLabel.text = NSLocalizedString(l10n, @"");

        titleView = titleLabel;
    }

    self.navigationItem.titleView = titleView;
    myTableView.tableHeaderView = [customInterface objectForKey:kJRProviderTableHeaderView];
    myTableView.tableFooterView = [customInterface objectForKey:kJRProviderTableFooterView];

    id const maybeCaptureSignInVc = [customInterface objectForKey:kJRCaptureConventionalSigninViewController];
    if ([maybeCaptureSignInVc isKindOfClass:NSClassFromString(@"JRConventionalSignInViewController")])
    {
        [maybeCaptureSignInVc performSelector:NSSelectorFromString(@"setDelegate:") withObject:self];

        [self createConventionalSignInLoadingView];
    }

    if (!hidesCancelButton)
    {
        UIBarButtonItem *cancelButton =
                [[[UIBarButtonItem alloc]
                        initWithBarButtonSystemItem:UIBarButtonSystemItemCancel
                                             target:sessionData
                                             action:@selector(triggerAuthenticationDidCancel:)] autorelease];

        self.navigationItem.leftBarButtonItem = cancelButton;
        self.navigationItem.leftBarButtonItem.enabled = YES;
        self.navigationItem.leftBarButtonItem.style = UIBarButtonItemStyleBordered;
    }

    if (!infoBar)
    {
        CGRect frame = CGRectMake(0, self.view.frame.size.height - 30, self.view.frame.size.width, 30);
        infoBar = [[JRInfoBar alloc] initWithFrame:frame andStyle:(JRInfoBarStyle) [sessionData hidePoweredBy]];

        [self.view addSubview:infoBar];
    }
}

- (void)viewWillAppear:(BOOL)animated
{
    DLog(@"");
    [super viewWillAppear:animated];

    // We need to figure out if the user canceled authentication by hitting the back button or the cancel button,
    // or if it stopped because it failed or completed successfully on its own.  Assume that the user did hit the
    // back button until told otherwise.
    //userHitTheBackButton = YES;

    // Load the custom background view, if there is one.
    if ([customInterface objectForKey:kJRAuthenticationBackgroundImageView])
        [myBackgroundView addSubview:[customInterface objectForKey:kJRAuthenticationBackgroundImageView]];

    CGFloat tableAndSectionHeaderHeight = 0;
    if (myTableView.tableHeaderView)
        tableAndSectionHeaderHeight += myTableView.tableHeaderView.frame.size.height;

    tableAndSectionHeaderHeight += [self tableView:myTableView heightForHeaderInSection:0];

    if (tableAndSectionHeaderHeight)
    {
        DLog ("self.frame: %f %f", self.view.frame.size.width, self.view.frame.size.height);

        CGFloat loadingLabelAndSpinnerVerticalOffset =
                ((self.view.frame.size.height - tableAndSectionHeaderHeight) / 2) + tableAndSectionHeaderHeight;

        [myLoadingLabel setFrame:
                                CGRectMake(myLoadingLabel.frame.origin.x,
                                        loadingLabelAndSpinnerVerticalOffset - 40,
                                        myLoadingLabel.frame.size.width,
                                        myLoadingLabel.frame.size.height)];
        [myActivitySpinner setFrame:
                                   CGRectMake(myActivitySpinner.frame.origin.x,
                                           loadingLabelAndSpinnerVerticalOffset,
                                           myActivitySpinner.frame.size.width,
                                           myActivitySpinner.frame.size.height)];

        DLog ("label.frame: %f, %f", myLoadingLabel.frame.origin.x, myLoadingLabel.frame.origin.y);
    }

    if ([sessionData.authenticationProviders count] > 0)
    {
        self.providers = [NSMutableArray arrayWithArray:sessionData.authenticationProviders];
        [providers removeObjectsInArray:[customInterface objectForKey:kJRRemoveProvidersFromAuthentication]];
        // the new providers are not strings they are JRProvider instances
        [myActivitySpinner stopAnimating];
        [myActivitySpinner setHidden:YES];
        [myLoadingLabel setHidden:YES];

        // Load the table with the list of providers.
        [myTableView reloadData];
    }
    else
    {
        DLog(@"prov count = %d", [sessionData.authenticationProviders count]);

        // If the user calls the library before the session data object is done initializing -
        // because either the requests for the base URL or provider list haven't returned -
        // display the "Loading Providers" label and activity spinner.
        // sessionData = nil when the call to get the base URL hasn't returned
        // [sessionData.configuredProviders count] = 0 when the provider list hasn't returned
        [myActivitySpinner setHidden:NO];
        [myLoadingLabel setHidden:NO];

        [myActivitySpinner startAnimating];

        // Now poll every few milliseconds, for about 16 seconds, until the provider list is loaded or we time out.
        timer = [NSTimer scheduledTimerWithTimeInterval:0.5 target:self
                                               selector:@selector(checkSessionDataAndProviders:)
                                               userInfo:nil repeats:NO];
    }
}

- (void)viewDidAppear:(BOOL)animated
{
    DLog(@"");
    [super viewDidAppear:animated];

    self.contentSizeForViewInPopover = CGSizeMake(320, 416);
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    [sessionData triggerAuthenticationDidTimeOutConfiguration];
}

/* If the user calls the library before the session data object is done initializing -
   because either the requests for the base URL or provider list haven't returned -
   keep polling every few milliseconds, for about 16 seconds,
   until the provider list is loaded or we time out. */
- (void)checkSessionDataAndProviders:(NSTimer *)theTimer
{
    DLog(@"");
    static NSTimeInterval interval = 0.5;
    interval = interval + 0.5;

    timer = nil;

    DLog(@"prov count = %d", [sessionData.authenticationProviders count]);
    DLog(@"interval = %f", interval);

    // If we have our list of providers, stop the progress indicators and load the table.
    if ([sessionData.authenticationProviders count] > 0)
    {
        self.providers = [NSMutableArray arrayWithArray:sessionData.authenticationProviders];
        [providers removeObjectsInArray:[customInterface objectForKey:kJRRemoveProvidersFromAuthentication]];

        [myActivitySpinner stopAnimating];
        [myActivitySpinner setHidden:YES];
        [myLoadingLabel setHidden:YES];

        [myTableView reloadData];

        return;
    }

    // Otherwise, keep polling until we've timed out.
    if (interval >= 16.0)
    {
        DLog(@"No Available Providers");

        [myActivitySpinner setHidden:YES];
        [myLoadingLabel setHidden:YES];
        [myActivitySpinner stopAnimating];

        UIApplication *app = [UIApplication sharedApplication];
        app.networkActivityIndicatorVisible = YES;

        NSString *message = @"There are no available providers. Either there is a problem connecting or no providers "
                "have been configured. Please try again later.";
        UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:@"No Available Providers" message:message
                                                        delegate:self
                                               cancelButtonTitle:@"OK"
                                               otherButtonTitles:nil] autorelease];
        [alert show];
        return;
    }

    timer = [NSTimer scheduledTimerWithTimeInterval:0.5 target:self selector:@selector(checkSessionDataAndProviders:)
                                           userInfo:nil repeats:NO];
}

#define LOADING_VIEW_TAG         555
#define LOADING_VIEW_LABEL_TAG   666
#define LOADING_VIEW_SPINNER_TAG 777

- (void)authenticationDidComplete
{
    [sessionData triggerAuthenticationDidCancel];
}

//- (void)authenticationDidCancel
//{
//
//}
//
//- (void)authenticationDidFail
//{
//
//}

- (void)showLoading
{
    UIActivityIndicatorView *myConventionalSigninLoadingSpinner =
            (UIActivityIndicatorView *) [myConventionalSignInLoadingView viewWithTag:LOADING_VIEW_SPINNER_TAG];

    [myConventionalSignInLoadingView setHidden:NO];
    [myConventionalSigninLoadingSpinner startAnimating];

    [UIView beginAnimations:@"fade" context:nil];
    [UIView setAnimationDuration:0.2];
    [UIView setAnimationDelay:0.0];
    myConventionalSignInLoadingView.alpha = 0.8;
    [UIView commitAnimations];
}

- (void)hideLoading
{
    UIActivityIndicatorView *myConventionalSigninLoadingSpinner =
            (UIActivityIndicatorView *) [myConventionalSignInLoadingView viewWithTag:LOADING_VIEW_SPINNER_TAG];

    [UIView beginAnimations:@"fade" context:nil];
    [UIView setAnimationDuration:0.2];
    [UIView setAnimationDelay:0.0];
    myConventionalSignInLoadingView.alpha = 0.0;
    [UIView commitAnimations];

    [myConventionalSignInLoadingView setHidden:YES];
    [myConventionalSigninLoadingSpinner stopAnimating];
}

- (void)createConventionalSignInLoadingView
{
    self.myConventionalSignInLoadingView = [[[UIView alloc] initWithFrame:self.view.frame] autorelease];

    [self.myConventionalSignInLoadingView setBackgroundColor:[UIColor blackColor]];

    UILabel *loadingLabel = [[[UILabel alloc] initWithFrame:CGRectMake(0, 180, 320, 30)] autorelease];

    [loadingLabel setText:@"Completing Sign-In..."];
    [loadingLabel setFont:[UIFont systemFontOfSize:20.0]];
    [loadingLabel setTextAlignment:JR_TEXT_ALIGN_CENTER];
    [loadingLabel setTextColor:[UIColor whiteColor]];
    [loadingLabel setBackgroundColor:[UIColor clearColor]];
    [loadingLabel setAutoresizingMask:UIViewAutoresizingNone |
            UIViewAutoresizingFlexibleTopMargin |
            UIViewAutoresizingFlexibleBottomMargin |
            UIViewAutoresizingFlexibleRightMargin |
            UIViewAutoresizingFlexibleLeftMargin];

    UIActivityIndicatorView *loadingSpinner =
            [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
    [loadingSpinner autorelease];

    [loadingSpinner setFrame:CGRectMake(142, self.view.frame.size.height / 2 - 16, 37, 37)];
    [loadingLabel setAutoresizingMask:UIViewAutoresizingNone |
            UIViewAutoresizingFlexibleTopMargin |
            UIViewAutoresizingFlexibleBottomMargin |
            UIViewAutoresizingFlexibleRightMargin |
            UIViewAutoresizingFlexibleLeftMargin];

    [loadingLabel setTag:LOADING_VIEW_LABEL_TAG];
    [loadingSpinner setTag:LOADING_VIEW_SPINNER_TAG];

    [myConventionalSignInLoadingView addSubview:loadingLabel];
    [myConventionalSignInLoadingView addSubview:loadingSpinner];

    [myConventionalSignInLoadingView setTag:LOADING_VIEW_TAG];
    [myConventionalSignInLoadingView setHidden:YES];
    [myConventionalSignInLoadingView setAlpha:0.0];

    [self.view addSubview:myConventionalSignInLoadingView];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    BOOL b;
    if ([JRUserInterfaceMaestro sharedMaestro].canRotate)
        b = interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown;
    else
        b = interfaceOrientation == UIInterfaceOrientationPortrait;
    DLog(@"%d", b);
    return b;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return NSLocalizedString([customInterface objectForKey:kJRProviderTableSectionHeaderTitleString], @"");
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    if ([customInterface objectForKey:kJRProviderTableSectionHeaderView])
        return ((UIView *) [customInterface objectForKey:kJRProviderTableSectionHeaderView]).frame.size.height;
    else if ([customInterface objectForKey:kJRProviderTableSectionHeaderTitleString])
        return 35;

    return 0;
}

- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section
{
    return [customInterface objectForKey:kJRProviderTableSectionHeaderView];
}

- (NSString *)tableView:(UITableView *)tableView titleForFooterInSection:(NSInteger)section
{
    return NSLocalizedString([customInterface objectForKey:kJRProviderTableSectionFooterTitleString], @"");
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section
{
    CGFloat infoBarHeight = sessionData.hidePoweredBy ? 0.0 : infoBar.frame.size.height;

    if ([customInterface objectForKey:kJRProviderTableSectionFooterView])
        return ((UIView *) [customInterface objectForKey:kJRProviderTableSectionFooterView]).frame.size.height +
                infoBarHeight;
    else if ([customInterface objectForKey:kJRProviderTableSectionFooterTitleString])
        return 35 + infoBarHeight;

    return 0 + infoBarHeight;
}

- (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section
{
    if ([customInterface objectForKey:kJRProviderTableSectionFooterView])
    {
        return [customInterface objectForKey:kJRProviderTableSectionFooterView];
    }
    else if (![customInterface objectForKey:kJRProviderTableSectionFooterTitleString])
    {
        CGRect frame = CGRectMake(0, 0, myTableView.frame.size.width, infoBar.frame.size.height);
        return [[[UIView alloc] initWithFrame:frame] autorelease];
    }
    else
    {
        return nil;
    }
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 50;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [providers count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCellProviders *cell =
            (UITableViewCellProviders *) [tableView dequeueReusableCellWithIdentifier:@"cachedCell"];

    if (cell == nil)
        cell = [[[UITableViewCellProviders alloc]
                initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"cachedCell"] autorelease];

    JRProvider *provider = [sessionData getProviderNamed:[providers objectAtIndex:(NSUInteger) indexPath.row]];

    if (!provider)
        return cell;

    NSString *imagePath = [NSString stringWithFormat:@"icon_%@_30x30.png", provider.name];

    cell.textLabel.text = provider.friendlyName;
    cell.imageView.image = [UIImage imageNamed:imagePath];

    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;

    [cell layoutSubviews];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    DLog(@"");
    [tableView deselectRowAtIndexPath:indexPath animated:NO];

    // Let sessionData know which provider the user selected
    JRProvider *provider = [sessionData getProviderNamed:[providers objectAtIndex:(NSUInteger) indexPath.row]];
    [sessionData setCurrentProvider:provider];

    DLog(@"cell for %@ was selected", provider);

    // TODO: Change me (comment)!
    if (provider.requiresInput || ([sessionData authenticatedUserForProvider:provider]
            && !(provider.forceReauth || sessionData.alwaysForceReauth)))
    {
        // If the selected provider requires input from the user, to the user landing view.
        // Or if the user started on the user landing page, went back to the list of providers, then selected
        // the same provider as their last-used provider, go back to the user landing view.
        [[self navigationController] pushViewController:[JRUserInterfaceMaestro sharedMaestro].myUserLandingController
                                               animated:YES];
    }
    else
    {
        // Otherwise, straight to the web view.
        [[self navigationController] pushViewController:[JRUserInterfaceMaestro sharedMaestro].myWebViewController
                                               animated:YES];
    }

}

- (void)userInterfaceWillClose
{
    [timer invalidate];
}

- (void)userInterfaceDidClose
{
}

- (void)dealloc
{
    DLog(@"");

    [customInterface release];
    [myBackgroundView release];
    [myTableView release];
    [myLoadingLabel release];
    [myActivitySpinner release];
    [infoBar release];
    [providers release];
    [myConventionalSignInLoadingView release];
    [super dealloc];
}
@end
