/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Copyright (c) 2012, Janrain, Inc.

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

 File:   CaptureNewUserViewController.h
 Author: Lilli Szafranski - lilli@janrain.com, lillialexis@gmail.com
 Date:   Thursday, January 26, 2012
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#import <UIKit/UIKit.h>
#import "JRCaptureUser+Extras.h"

@interface CaptureNewUserViewController : UIViewController <UITextViewDelegate, UIAlertViewDelegate,
                                                            JRCaptureUserDelegate, UITextFieldDelegate>
{
    UIScrollView *myScrollView;

    NSDate       *myBirthdate;
    UIButton     *myBirthdayButton;

    UIDatePicker *myBirthdayPicker;
    UIToolbar    *myPickerToolbar;
    UIView       *myPickerView;
}
@property (nonatomic, retain) IBOutlet UITextField        *myEmailTextField;
@property (nonatomic, retain) IBOutlet UISegmentedControl *myGenderIdentitySegControl;
@property (nonatomic, retain) IBOutlet UIButton           *myBirthdayButton;
@property (nonatomic, retain) IBOutlet UIDatePicker       *myBirthdayPicker;
@property (nonatomic, retain) IBOutlet UIToolbar          *myPickerToolbar;
@property (nonatomic, retain) IBOutlet UITextView         *myAboutMeTextView;
@property (nonatomic, retain) IBOutlet UIView             *myPickerView;
@property (nonatomic, retain) IBOutlet UIScrollView       *myScrollView;
@property (nonatomic, retain) IBOutlet UIToolbar          *myKeyboardToolbar;
- (IBAction)emailTextFieldClicked:(id)sender;
- (IBAction)birthdayButtonClicked:(id)sender;
- (IBAction)birthdayPickerChanged:(id)sender;
- (IBAction)hidePickerButtonPressed:(id)sender;
- (IBAction)doneButtonPressed:(id)sender;
- (IBAction)doneEditingButtonPressed:(id)sender;
@end
