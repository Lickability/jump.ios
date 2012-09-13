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
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#import <Foundation/Foundation.h>
#import "JRCaptureObject.h"
#import "JRCaptureTypes.h"
#import "JRNSDate+ISO8601_CaptureDateTimeString.h"
#import "JRBestHand.h"
#import "JRGamesElement.h"
#import "JRObjectLevelOne.h"
#import "JROnipLevelOneElement.h"
#import "JRPhotosElement.h"
#import "JRPinoLevelOne.h"
#import "JRPluralLevelOneElement.h"
#import "JRPrimaryAddress.h"
#import "JRProfilesElement.h"
#import "JRStatusesElement.h"
#import "JRTournamentsPlayedElement.h"
#import "JRCaptureBaseUser.h"

/**
 * @brief A JRCaptureUser object
 **/
@interface JRCaptureUser : JRCaptureBaseUser
@property (nonatomic, readonly) JRObjectId *captureUserId; /**< Simple identifier for this entity @note The \e id of the object should not be set. */ 
@property (nonatomic, readonly) JRUuid *uuid; /**< Globally unique indentifier for this entity @note A ::JRUuid property is a property of type \ref typesTable "uuid" and a typedef of \e NSString */ 
@property (nonatomic, readonly) JRDateTime *created; /**< When this entity was created @note A ::JRDateTime property is a property of type \ref typesTable "dateTime" and a typedef of \e NSDate. The accepted format should be an ISO 8601 dateTime string (e.g., <code>yyyy-MM-dd HH:mm:ss.SSSSSS ZZZ</code>) */ 
@property (nonatomic, readonly) JRDateTime *lastUpdated; /**< When this entity was last updated @note A ::JRDateTime property is a property of type \ref typesTable "dateTime" and a typedef of \e NSDate. The accepted format should be an ISO 8601 dateTime string (e.g., <code>yyyy-MM-dd HH:mm:ss.SSSSSS ZZZ</code>) */ 
@property (nonatomic, copy)     NSString *aboutMe; /**< The object's \e aboutMe property */ 
@property (nonatomic, copy)     NSString *avatar; /**< The name of the avatar which is used to represent the player at tournament tables */ 
@property (nonatomic, copy)     JRDecimal *bankroll; /**< The player’s current in-game bankroll @note A ::JRDecimal property is a property of type \ref typesTable "decimal" and a typedef of \e NSNumber. Accepted values can be, for example, <code>[NSNumber numberWithNumber:<em>myDecimal</em>]</code>, <code>nil</code>, etc. */ 
@property (nonatomic, retain)   JRBestHand *bestHand; /**< The best hand your player has ever had in a tournament */ 
@property (nonatomic, copy)     JRDate *birthday; /**< The object's \e birthday property @note A ::JRDate property is a property of type \ref typesTable "date" and a typedef of \e NSDate. The accepted format should be an ISO 8601 date string (e.g., <code>yyyy-MM-dd</code>) */ 
@property (nonatomic, copy)     NSString *currentLocation; /**< The object's \e currentLocation property */ 
@property (nonatomic, copy)     JRJsonObject *display; /**< The object's \e display property @note A ::JRJsonObject property is a property of type \ref typesTable "json", which can be an \e NSDictionary, \e NSArray, \e NSString, etc., and is therefore is a typedef of \e NSObject */ 
@property (nonatomic, copy)     NSString *displayName; /**< The name of this Contact, suitable for display to end-users. */ 
@property (nonatomic, copy)     NSString *email; /**< The object's \e email property */ 
@property (nonatomic, copy)     JRDateTime *emailVerified; /**< The object's \e emailVerified property @note A ::JRDateTime property is a property of type \ref typesTable "dateTime" and a typedef of \e NSDate. The accepted format should be an ISO 8601 dateTime string (e.g., <code>yyyy-MM-dd HH:mm:ss.SSSSSS ZZZ</code>) */ 
@property (nonatomic, copy)     JRBoolean *exampleBoolean; /**< Example of a basic string property @note A ::JRBoolean property is a property of type \ref typesTable "boolean" and a typedef of \e NSNumber. The accepted values can only be <code>[NSNumber numberWithBool:<em>myBool</em>]</code> or <code>nil</code> */ 
@property (nonatomic, copy)     JRDate *exampleDate; /**< Example of a basic date property @note A ::JRDate property is a property of type \ref typesTable "date" and a typedef of \e NSDate. The accepted format should be an ISO 8601 date string (e.g., <code>yyyy-MM-dd</code>) */ 
@property (nonatomic, copy)     JRDateTime *exampleDateTime; /**< Example of a basic dateTime property @note A ::JRDateTime property is a property of type \ref typesTable "dateTime" and a typedef of \e NSDate. The accepted format should be an ISO 8601 dateTime string (e.g., <code>yyyy-MM-dd HH:mm:ss.SSSSSS ZZZ</code>) */ 
@property (nonatomic, copy)     JRDecimal *exampleDecimal; /**< Example of a basic decimal property @note A ::JRDecimal property is a property of type \ref typesTable "decimal" and a typedef of \e NSNumber. Accepted values can be, for example, <code>[NSNumber numberWithNumber:<em>myDecimal</em>]</code>, <code>nil</code>, etc. */ 
@property (nonatomic, copy)     JRInteger *exampleInteger; /**< Example of a basic integer property @note A ::JRInteger property is a property of type \ref typesTable "integer" and a typedef of \e NSNumber. The accepted values can only be <code>[NSNumber numberWithInteger:<em>myInteger</em>]</code>, <code>[NSNumber numberWithInt:<em>myInt</em>]</code>, or <code>nil</code> */ 
@property (nonatomic, copy)     JRIpAddress *exampleIpAddress; /**< Example of a basic ipAddress property @note A ::JRIpAddress property is a property of type \ref typesTable "ipAddress" and a typedef of \e NSString. */ 
@property (nonatomic, copy)     JRJsonObject *exampleJson; /**< Example of a basic ipAddress property @note A ::JRJsonObject property is a property of type \ref typesTable "json", which can be an \e NSDictionary, \e NSArray, \e NSString, etc., and is therefore is a typedef of \e NSObject */ 
@property (nonatomic, copy)     NSString *exampleString; /**< Example of a basic string property */ 
@property (nonatomic, copy)     JRStringArray *exampleStringPlural; /**< The object's \e exampleStringPlural property @note  A ::JRStringArray property is a plural (array) that holds a list of \e NSStrings. As it is an array, it is therefore a typedef of \e NSArray. This array of \c NSStrings represents a list of \c stringPluralItem */ 
@property (nonatomic, copy)     NSString *exampleUniqueString; /**< The object's \e exampleUniqueString property */ 
@property (nonatomic, copy)     NSString *familyName; /**< The object's \e familyName property */ 
@property (nonatomic, copy)     JRStringArray *favoriteHands; /**< The player’s favorite hands @note  A ::JRStringArray property is a plural (array) that holds a list of \e NSStrings. As it is an array, it is therefore a typedef of \e NSArray. This array of \c NSStrings represents a list of \c hand */ 
@property (nonatomic, copy)     NSArray *games; /**< The object's \e games property @note This is an array of JRGamesElement objects */ 
@property (nonatomic, copy)     NSString *gender; /**< The object's \e gender property */ 
@property (nonatomic, copy)     NSString *givenName; /**< The object's \e givenName property */ 
@property (nonatomic, copy)     JRDateTime *lastLogin; /**< The object's \e lastLogin property @note A ::JRDateTime property is a property of type \ref typesTable "dateTime" and a typedef of \e NSDate. The accepted format should be an ISO 8601 dateTime string (e.g., <code>yyyy-MM-dd HH:mm:ss.SSSSSS ZZZ</code>) */ 
@property (nonatomic, copy)     NSString *middleName; /**< The object's \e middleName property */ 
@property (nonatomic, retain)   JRObjectLevelOne *objectLevelOne; /**< An example of objects nested in objects, level 1 */ 
@property (nonatomic, copy)     NSArray *onipLevelOne; /**< An example of objects nested in plurals, level 1, plural @note This is an array of JROnipLevelOneElement objects */ 
@property (nonatomic, copy)     JRPassword *password; /**< The object's \e password property @note A ::JRPassword property is a property of type \ref typesTable "password", which can be either an \e NSString or \e NSDictionary, and is therefore is a typedef of \e NSObject */ 
@property (nonatomic, copy)     NSArray *photos; /**< The object's \e photos property @note This is an array of JRPhotosElement objects */ 
@property (nonatomic, retain)   JRPinoLevelOne *pinoLevelOne; /**< An example of plurals nested in objects, level 1, object */ 
@property (nonatomic, copy)     NSString *playerName; /**< The name that is displayed below the player’s avatar */ 
@property (nonatomic, copy)     NSArray *pluralLevelOne; /**< An example of plurals nested in plurals, level 1 @note This is an array of JRPluralLevelOneElement objects */ 
@property (nonatomic, retain)   JRPrimaryAddress *primaryAddress; /**< The object's \e primaryAddress property */ 
@property (nonatomic, copy)     NSArray *profiles; /**< The object's \e profiles property @note This is an array of JRProfilesElement objects */ 
@property (nonatomic, copy)     NSArray *statuses; /**< The object's \e statuses property @note This is an array of JRStatusesElement objects */ 
@property (nonatomic, copy)     NSArray *tournamentsPlayed; /**< A list of the tournaments in which the player has competed @note This is an array of JRTournamentsPlayedElement objects */ 

/**
 * @name Constructors
 **/
/*@{*/
/**
 * Default instance constructor. Returns an empty JRCaptureUser object
 *
 * @return
 *   A JRCaptureUser object
 *
 * @note 
 * Method creates a object without the required properties: \e email.
 * These properties are required when updating the object on Capture. That is, you must set them before calling
 * updateOnCaptureForDelegate:context:().
 **/
- (id)init;

/**
 * Default class constructor. Returns an empty JRCaptureUser object
 *
 * @return
 *   A JRCaptureUser object
 *
 * @note 
 * Method creates a object without the required properties: \e email.
 * These properties are required when updating the object on Capture. That is, you must set them before calling
 * updateOnCaptureForDelegate:context:().
 **/
+ (id)captureUser;

/**
 * Returns a JRCaptureUser object initialized with the given required properties: \c newEmail
 *
 * @param newEmail
 *   The object's \e email property
 * 
 * @return
 *   A JRCaptureUser object initialized with the given required properties: \e newEmail.
 *   If the required arguments are \e nil or \e [NSNull null], returns \e nil
 **/
- (id)initWithEmail:(NSString *)newEmail;

/**
 * Returns a JRCaptureUser object initialized with the given required properties: \c email
 *
 * @param email
 *   The object's \e email property
 * 
 * @return
 *   A JRCaptureUser object initialized with the given required properties: \e email.
 *   If the required arguments are \e nil or \e [NSNull null], returns \e nil
 **/
+ (id)captureUserWithEmail:(NSString *)email;

/*@}*/

/**
 * @name Manage Remotely 
 **/
/*@{*/
/**
 * Use this method to replace the JRCaptureUser#exampleStringPlural array on Capture after adding, removing,
 * or reordering elements. You should call this method immediately after you perform any of these actions.
 * This method will replace the entire array on Capture, including all of its elements and their sub-arrays and
 * sub-objects. When successful, the new array will be added to the JRCaptureUser#exampleStringPlural property,
 * replacing the existing NSArray.
 *
 * If the array is replaced successfully, the method JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 * will be called on your delegate. This method will return a pointer to the new array, which is also the same pointer
 * stored in the JRCaptureUser#exampleStringPlural property, and the name of the replaced array: \c "exampleStringPlural".
 *
 * If unsuccessful, the method JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:
 * will be called on your delegate.
 *
 * @param delegate
 *   The JRCaptureObjectDelegate that implements the optional delegate methods JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 *   and JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:.
 *
 * @param context
 *   Any NSObject that you would like to send through the asynchronous network call back to your delegate, or \c nil.
 *   This object will be passed back to your JRCaptureObjectDelegate as is. Contexts are used across most of the
 *   asynchronous Capture methods to facilitate correlation of the response messages with the calling code. Use of the
 *   context is entirely optional and at your discretion.
 *
 * @warning
 * When successful, the new array will be added to the JRCaptureUser#exampleStringPlural property,
 * replacing the existing NSArray. The new array will contain new, but equivalent JRExampleStringPluralElement
 * objects. That is to say, the elements will be the same, but they will have new pointers. You should not hold onto
 * any references to the JRCaptureUser#exampleStringPlural or JRExampleStringPluralElement objects
 * when you are replacing this array on Capture, as the pointers will become invalid.
 * 
 * @note
 * After the array has been replaced on Capture, you can now call JRExampleStringPluralElement#updateOnCaptureForDelegate:context:()
 * on the array's elements. You can check the JRExampleStringPluralElement#canBeUpdatedOnCapture property to determine
 * if an element can be updated or not. If the JRExampleStringPluralElement#canBeUpdatedOnCapture property is equal
 * to \c NO you should replace the JRCaptureUser#exampleStringPlural array on Capture. Replacing the array will also
 * update any local changes to the properties of a JRExampleStringPluralElement, including sub-arrays and sub-objects.
 *
 * @par
 * If you haven't added, removed, or reordered any of the elements of the JRCaptureUser#exampleStringPlural array, but
 * you have locally updated the properties of a JRExampleStringPluralElement, you can just call
 * JRExampleStringPluralElement#updateOnCaptureForDelegate:context:() to update the local changes on the Capture server.
 * The JRExampleStringPluralElement#canBeUpdatedOnCapture property will let you know if you can do this.
 **/
- (void)replaceExampleStringPluralArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * Use this method to replace the JRCaptureUser#favoriteHands array on Capture after adding, removing,
 * or reordering elements. You should call this method immediately after you perform any of these actions.
 * This method will replace the entire array on Capture, including all of its elements and their sub-arrays and
 * sub-objects. When successful, the new array will be added to the JRCaptureUser#favoriteHands property,
 * replacing the existing NSArray.
 *
 * If the array is replaced successfully, the method JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 * will be called on your delegate. This method will return a pointer to the new array, which is also the same pointer
 * stored in the JRCaptureUser#favoriteHands property, and the name of the replaced array: \c "favoriteHands".
 *
 * If unsuccessful, the method JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:
 * will be called on your delegate.
 *
 * @param delegate
 *   The JRCaptureObjectDelegate that implements the optional delegate methods JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 *   and JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:.
 *
 * @param context
 *   Any NSObject that you would like to send through the asynchronous network call back to your delegate, or \c nil.
 *   This object will be passed back to your JRCaptureObjectDelegate as is. Contexts are used across most of the
 *   asynchronous Capture methods to facilitate correlation of the response messages with the calling code. Use of the
 *   context is entirely optional and at your discretion.
 *
 * @warning
 * When successful, the new array will be added to the JRCaptureUser#favoriteHands property,
 * replacing the existing NSArray. The new array will contain new, but equivalent JRFavoriteHandsElement
 * objects. That is to say, the elements will be the same, but they will have new pointers. You should not hold onto
 * any references to the JRCaptureUser#favoriteHands or JRFavoriteHandsElement objects
 * when you are replacing this array on Capture, as the pointers will become invalid.
 * 
 * @note
 * After the array has been replaced on Capture, you can now call JRFavoriteHandsElement#updateOnCaptureForDelegate:context:()
 * on the array's elements. You can check the JRFavoriteHandsElement#canBeUpdatedOnCapture property to determine
 * if an element can be updated or not. If the JRFavoriteHandsElement#canBeUpdatedOnCapture property is equal
 * to \c NO you should replace the JRCaptureUser#favoriteHands array on Capture. Replacing the array will also
 * update any local changes to the properties of a JRFavoriteHandsElement, including sub-arrays and sub-objects.
 *
 * @par
 * If you haven't added, removed, or reordered any of the elements of the JRCaptureUser#favoriteHands array, but
 * you have locally updated the properties of a JRFavoriteHandsElement, you can just call
 * JRFavoriteHandsElement#updateOnCaptureForDelegate:context:() to update the local changes on the Capture server.
 * The JRFavoriteHandsElement#canBeUpdatedOnCapture property will let you know if you can do this.
 **/
- (void)replaceFavoriteHandsArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * Use this method to replace the JRCaptureUser#games array on Capture after adding, removing,
 * or reordering elements. You should call this method immediately after you perform any of these actions.
 * This method will replace the entire array on Capture, including all of its elements and their sub-arrays and
 * sub-objects. When successful, the new array will be added to the JRCaptureUser#games property,
 * replacing the existing NSArray.
 *
 * If the array is replaced successfully, the method JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 * will be called on your delegate. This method will return a pointer to the new array, which is also the same pointer
 * stored in the JRCaptureUser#games property, and the name of the replaced array: \c "games".
 *
 * If unsuccessful, the method JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:
 * will be called on your delegate.
 *
 * @param delegate
 *   The JRCaptureObjectDelegate that implements the optional delegate methods JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 *   and JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:.
 *
 * @param context
 *   Any NSObject that you would like to send through the asynchronous network call back to your delegate, or \c nil.
 *   This object will be passed back to your JRCaptureObjectDelegate as is. Contexts are used across most of the
 *   asynchronous Capture methods to facilitate correlation of the response messages with the calling code. Use of the
 *   context is entirely optional and at your discretion.
 *
 * @warning
 * When successful, the new array will be added to the JRCaptureUser#games property,
 * replacing the existing NSArray. The new array will contain new, but equivalent JRGamesElement
 * objects. That is to say, the elements will be the same, but they will have new pointers. You should not hold onto
 * any references to the JRCaptureUser#games or JRGamesElement objects
 * when you are replacing this array on Capture, as the pointers will become invalid.
 * 
 * @note
 * After the array has been replaced on Capture, you can now call JRGamesElement#updateOnCaptureForDelegate:context:()
 * on the array's elements. You can check the JRGamesElement#canBeUpdatedOnCapture property to determine
 * if an element can be updated or not. If the JRGamesElement#canBeUpdatedOnCapture property is equal
 * to \c NO you should replace the JRCaptureUser#games array on Capture. Replacing the array will also
 * update any local changes to the properties of a JRGamesElement, including sub-arrays and sub-objects.
 *
 * @par
 * If you haven't added, removed, or reordered any of the elements of the JRCaptureUser#games array, but
 * you have locally updated the properties of a JRGamesElement, you can just call
 * JRGamesElement#updateOnCaptureForDelegate:context:() to update the local changes on the Capture server.
 * The JRGamesElement#canBeUpdatedOnCapture property will let you know if you can do this.
 **/
- (void)replaceGamesArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * Use this method to replace the JRCaptureUser#onipLevelOne array on Capture after adding, removing,
 * or reordering elements. You should call this method immediately after you perform any of these actions.
 * This method will replace the entire array on Capture, including all of its elements and their sub-arrays and
 * sub-objects. When successful, the new array will be added to the JRCaptureUser#onipLevelOne property,
 * replacing the existing NSArray.
 *
 * If the array is replaced successfully, the method JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 * will be called on your delegate. This method will return a pointer to the new array, which is also the same pointer
 * stored in the JRCaptureUser#onipLevelOne property, and the name of the replaced array: \c "onipLevelOne".
 *
 * If unsuccessful, the method JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:
 * will be called on your delegate.
 *
 * @param delegate
 *   The JRCaptureObjectDelegate that implements the optional delegate methods JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 *   and JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:.
 *
 * @param context
 *   Any NSObject that you would like to send through the asynchronous network call back to your delegate, or \c nil.
 *   This object will be passed back to your JRCaptureObjectDelegate as is. Contexts are used across most of the
 *   asynchronous Capture methods to facilitate correlation of the response messages with the calling code. Use of the
 *   context is entirely optional and at your discretion.
 *
 * @warning
 * When successful, the new array will be added to the JRCaptureUser#onipLevelOne property,
 * replacing the existing NSArray. The new array will contain new, but equivalent JROnipLevelOneElement
 * objects. That is to say, the elements will be the same, but they will have new pointers. You should not hold onto
 * any references to the JRCaptureUser#onipLevelOne or JROnipLevelOneElement objects
 * when you are replacing this array on Capture, as the pointers will become invalid.
 * 
 * @note
 * After the array has been replaced on Capture, you can now call JROnipLevelOneElement#updateOnCaptureForDelegate:context:()
 * on the array's elements. You can check the JROnipLevelOneElement#canBeUpdatedOnCapture property to determine
 * if an element can be updated or not. If the JROnipLevelOneElement#canBeUpdatedOnCapture property is equal
 * to \c NO you should replace the JRCaptureUser#onipLevelOne array on Capture. Replacing the array will also
 * update any local changes to the properties of a JROnipLevelOneElement, including sub-arrays and sub-objects.
 *
 * @par
 * If you haven't added, removed, or reordered any of the elements of the JRCaptureUser#onipLevelOne array, but
 * you have locally updated the properties of a JROnipLevelOneElement, you can just call
 * JROnipLevelOneElement#updateOnCaptureForDelegate:context:() to update the local changes on the Capture server.
 * The JROnipLevelOneElement#canBeUpdatedOnCapture property will let you know if you can do this.
 **/
- (void)replaceOnipLevelOneArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * Use this method to replace the JRCaptureUser#photos array on Capture after adding, removing,
 * or reordering elements. You should call this method immediately after you perform any of these actions.
 * This method will replace the entire array on Capture, including all of its elements and their sub-arrays and
 * sub-objects. When successful, the new array will be added to the JRCaptureUser#photos property,
 * replacing the existing NSArray.
 *
 * If the array is replaced successfully, the method JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 * will be called on your delegate. This method will return a pointer to the new array, which is also the same pointer
 * stored in the JRCaptureUser#photos property, and the name of the replaced array: \c "photos".
 *
 * If unsuccessful, the method JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:
 * will be called on your delegate.
 *
 * @param delegate
 *   The JRCaptureObjectDelegate that implements the optional delegate methods JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 *   and JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:.
 *
 * @param context
 *   Any NSObject that you would like to send through the asynchronous network call back to your delegate, or \c nil.
 *   This object will be passed back to your JRCaptureObjectDelegate as is. Contexts are used across most of the
 *   asynchronous Capture methods to facilitate correlation of the response messages with the calling code. Use of the
 *   context is entirely optional and at your discretion.
 *
 * @warning
 * When successful, the new array will be added to the JRCaptureUser#photos property,
 * replacing the existing NSArray. The new array will contain new, but equivalent JRPhotosElement
 * objects. That is to say, the elements will be the same, but they will have new pointers. You should not hold onto
 * any references to the JRCaptureUser#photos or JRPhotosElement objects
 * when you are replacing this array on Capture, as the pointers will become invalid.
 * 
 * @note
 * After the array has been replaced on Capture, you can now call JRPhotosElement#updateOnCaptureForDelegate:context:()
 * on the array's elements. You can check the JRPhotosElement#canBeUpdatedOnCapture property to determine
 * if an element can be updated or not. If the JRPhotosElement#canBeUpdatedOnCapture property is equal
 * to \c NO you should replace the JRCaptureUser#photos array on Capture. Replacing the array will also
 * update any local changes to the properties of a JRPhotosElement, including sub-arrays and sub-objects.
 *
 * @par
 * If you haven't added, removed, or reordered any of the elements of the JRCaptureUser#photos array, but
 * you have locally updated the properties of a JRPhotosElement, you can just call
 * JRPhotosElement#updateOnCaptureForDelegate:context:() to update the local changes on the Capture server.
 * The JRPhotosElement#canBeUpdatedOnCapture property will let you know if you can do this.
 **/
- (void)replacePhotosArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * Use this method to replace the JRCaptureUser#pluralLevelOne array on Capture after adding, removing,
 * or reordering elements. You should call this method immediately after you perform any of these actions.
 * This method will replace the entire array on Capture, including all of its elements and their sub-arrays and
 * sub-objects. When successful, the new array will be added to the JRCaptureUser#pluralLevelOne property,
 * replacing the existing NSArray.
 *
 * If the array is replaced successfully, the method JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 * will be called on your delegate. This method will return a pointer to the new array, which is also the same pointer
 * stored in the JRCaptureUser#pluralLevelOne property, and the name of the replaced array: \c "pluralLevelOne".
 *
 * If unsuccessful, the method JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:
 * will be called on your delegate.
 *
 * @param delegate
 *   The JRCaptureObjectDelegate that implements the optional delegate methods JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 *   and JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:.
 *
 * @param context
 *   Any NSObject that you would like to send through the asynchronous network call back to your delegate, or \c nil.
 *   This object will be passed back to your JRCaptureObjectDelegate as is. Contexts are used across most of the
 *   asynchronous Capture methods to facilitate correlation of the response messages with the calling code. Use of the
 *   context is entirely optional and at your discretion.
 *
 * @warning
 * When successful, the new array will be added to the JRCaptureUser#pluralLevelOne property,
 * replacing the existing NSArray. The new array will contain new, but equivalent JRPluralLevelOneElement
 * objects. That is to say, the elements will be the same, but they will have new pointers. You should not hold onto
 * any references to the JRCaptureUser#pluralLevelOne or JRPluralLevelOneElement objects
 * when you are replacing this array on Capture, as the pointers will become invalid.
 * 
 * @note
 * After the array has been replaced on Capture, you can now call JRPluralLevelOneElement#updateOnCaptureForDelegate:context:()
 * on the array's elements. You can check the JRPluralLevelOneElement#canBeUpdatedOnCapture property to determine
 * if an element can be updated or not. If the JRPluralLevelOneElement#canBeUpdatedOnCapture property is equal
 * to \c NO you should replace the JRCaptureUser#pluralLevelOne array on Capture. Replacing the array will also
 * update any local changes to the properties of a JRPluralLevelOneElement, including sub-arrays and sub-objects.
 *
 * @par
 * If you haven't added, removed, or reordered any of the elements of the JRCaptureUser#pluralLevelOne array, but
 * you have locally updated the properties of a JRPluralLevelOneElement, you can just call
 * JRPluralLevelOneElement#updateOnCaptureForDelegate:context:() to update the local changes on the Capture server.
 * The JRPluralLevelOneElement#canBeUpdatedOnCapture property will let you know if you can do this.
 **/
- (void)replacePluralLevelOneArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * Use this method to replace the JRCaptureUser#profiles array on Capture after adding, removing,
 * or reordering elements. You should call this method immediately after you perform any of these actions.
 * This method will replace the entire array on Capture, including all of its elements and their sub-arrays and
 * sub-objects. When successful, the new array will be added to the JRCaptureUser#profiles property,
 * replacing the existing NSArray.
 *
 * If the array is replaced successfully, the method JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 * will be called on your delegate. This method will return a pointer to the new array, which is also the same pointer
 * stored in the JRCaptureUser#profiles property, and the name of the replaced array: \c "profiles".
 *
 * If unsuccessful, the method JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:
 * will be called on your delegate.
 *
 * @param delegate
 *   The JRCaptureObjectDelegate that implements the optional delegate methods JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 *   and JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:.
 *
 * @param context
 *   Any NSObject that you would like to send through the asynchronous network call back to your delegate, or \c nil.
 *   This object will be passed back to your JRCaptureObjectDelegate as is. Contexts are used across most of the
 *   asynchronous Capture methods to facilitate correlation of the response messages with the calling code. Use of the
 *   context is entirely optional and at your discretion.
 *
 * @warning
 * When successful, the new array will be added to the JRCaptureUser#profiles property,
 * replacing the existing NSArray. The new array will contain new, but equivalent JRProfilesElement
 * objects. That is to say, the elements will be the same, but they will have new pointers. You should not hold onto
 * any references to the JRCaptureUser#profiles or JRProfilesElement objects
 * when you are replacing this array on Capture, as the pointers will become invalid.
 * 
 * @note
 * After the array has been replaced on Capture, you can now call JRProfilesElement#updateOnCaptureForDelegate:context:()
 * on the array's elements. You can check the JRProfilesElement#canBeUpdatedOnCapture property to determine
 * if an element can be updated or not. If the JRProfilesElement#canBeUpdatedOnCapture property is equal
 * to \c NO you should replace the JRCaptureUser#profiles array on Capture. Replacing the array will also
 * update any local changes to the properties of a JRProfilesElement, including sub-arrays and sub-objects.
 *
 * @par
 * If you haven't added, removed, or reordered any of the elements of the JRCaptureUser#profiles array, but
 * you have locally updated the properties of a JRProfilesElement, you can just call
 * JRProfilesElement#updateOnCaptureForDelegate:context:() to update the local changes on the Capture server.
 * The JRProfilesElement#canBeUpdatedOnCapture property will let you know if you can do this.
 **/
- (void)replaceProfilesArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * Use this method to replace the JRCaptureUser#statuses array on Capture after adding, removing,
 * or reordering elements. You should call this method immediately after you perform any of these actions.
 * This method will replace the entire array on Capture, including all of its elements and their sub-arrays and
 * sub-objects. When successful, the new array will be added to the JRCaptureUser#statuses property,
 * replacing the existing NSArray.
 *
 * If the array is replaced successfully, the method JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 * will be called on your delegate. This method will return a pointer to the new array, which is also the same pointer
 * stored in the JRCaptureUser#statuses property, and the name of the replaced array: \c "statuses".
 *
 * If unsuccessful, the method JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:
 * will be called on your delegate.
 *
 * @param delegate
 *   The JRCaptureObjectDelegate that implements the optional delegate methods JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 *   and JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:.
 *
 * @param context
 *   Any NSObject that you would like to send through the asynchronous network call back to your delegate, or \c nil.
 *   This object will be passed back to your JRCaptureObjectDelegate as is. Contexts are used across most of the
 *   asynchronous Capture methods to facilitate correlation of the response messages with the calling code. Use of the
 *   context is entirely optional and at your discretion.
 *
 * @warning
 * When successful, the new array will be added to the JRCaptureUser#statuses property,
 * replacing the existing NSArray. The new array will contain new, but equivalent JRStatusesElement
 * objects. That is to say, the elements will be the same, but they will have new pointers. You should not hold onto
 * any references to the JRCaptureUser#statuses or JRStatusesElement objects
 * when you are replacing this array on Capture, as the pointers will become invalid.
 * 
 * @note
 * After the array has been replaced on Capture, you can now call JRStatusesElement#updateOnCaptureForDelegate:context:()
 * on the array's elements. You can check the JRStatusesElement#canBeUpdatedOnCapture property to determine
 * if an element can be updated or not. If the JRStatusesElement#canBeUpdatedOnCapture property is equal
 * to \c NO you should replace the JRCaptureUser#statuses array on Capture. Replacing the array will also
 * update any local changes to the properties of a JRStatusesElement, including sub-arrays and sub-objects.
 *
 * @par
 * If you haven't added, removed, or reordered any of the elements of the JRCaptureUser#statuses array, but
 * you have locally updated the properties of a JRStatusesElement, you can just call
 * JRStatusesElement#updateOnCaptureForDelegate:context:() to update the local changes on the Capture server.
 * The JRStatusesElement#canBeUpdatedOnCapture property will let you know if you can do this.
 **/
- (void)replaceStatusesArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * Use this method to replace the JRCaptureUser#tournamentsPlayed array on Capture after adding, removing,
 * or reordering elements. You should call this method immediately after you perform any of these actions.
 * This method will replace the entire array on Capture, including all of its elements and their sub-arrays and
 * sub-objects. When successful, the new array will be added to the JRCaptureUser#tournamentsPlayed property,
 * replacing the existing NSArray.
 *
 * If the array is replaced successfully, the method JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 * will be called on your delegate. This method will return a pointer to the new array, which is also the same pointer
 * stored in the JRCaptureUser#tournamentsPlayed property, and the name of the replaced array: \c "tournamentsPlayed".
 *
 * If unsuccessful, the method JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:
 * will be called on your delegate.
 *
 * @param delegate
 *   The JRCaptureObjectDelegate that implements the optional delegate methods JRCaptureObjectDelegate#replaceArrayDidSucceedForObject:newArray:named:context:
 *   and JRCaptureObjectDelegate#replaceArrayDidFailForObject:arrayNamed:withError:context:.
 *
 * @param context
 *   Any NSObject that you would like to send through the asynchronous network call back to your delegate, or \c nil.
 *   This object will be passed back to your JRCaptureObjectDelegate as is. Contexts are used across most of the
 *   asynchronous Capture methods to facilitate correlation of the response messages with the calling code. Use of the
 *   context is entirely optional and at your discretion.
 *
 * @warning
 * When successful, the new array will be added to the JRCaptureUser#tournamentsPlayed property,
 * replacing the existing NSArray. The new array will contain new, but equivalent JRTournamentsPlayedElement
 * objects. That is to say, the elements will be the same, but they will have new pointers. You should not hold onto
 * any references to the JRCaptureUser#tournamentsPlayed or JRTournamentsPlayedElement objects
 * when you are replacing this array on Capture, as the pointers will become invalid.
 * 
 * @note
 * After the array has been replaced on Capture, you can now call JRTournamentsPlayedElement#updateOnCaptureForDelegate:context:()
 * on the array's elements. You can check the JRTournamentsPlayedElement#canBeUpdatedOnCapture property to determine
 * if an element can be updated or not. If the JRTournamentsPlayedElement#canBeUpdatedOnCapture property is equal
 * to \c NO you should replace the JRCaptureUser#tournamentsPlayed array on Capture. Replacing the array will also
 * update any local changes to the properties of a JRTournamentsPlayedElement, including sub-arrays and sub-objects.
 *
 * @par
 * If you haven't added, removed, or reordered any of the elements of the JRCaptureUser#tournamentsPlayed array, but
 * you have locally updated the properties of a JRTournamentsPlayedElement, you can just call
 * JRTournamentsPlayedElement#updateOnCaptureForDelegate:context:() to update the local changes on the Capture server.
 * The JRTournamentsPlayedElement#canBeUpdatedOnCapture property will let you know if you can do this.
 **/
- (void)replaceTournamentsPlayedArrayOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;

/**
 * Use this method to determine if the object or element needs to be updated remotely.
 * That is, if there are local changes to any of the object/elements's properties or 
 * sub-objects, then this object will need to be updated on Capture. You can update
 * an object on Capture by using the method updateOnCaptureForDelegate:context:().
 *
 * @return
 * \c YES if this object or any of it's sub-objects have any properties that have changed
 * locally. This does not include properties that are arrays, if any, or the elements contained 
 * within the arrays. \c NO if no non-array properties or sub-objects have changed locally.
 *
 * @note
 * This method recursively checks all of the sub-objects of JRCaptureUser:
 *   - JRCaptureUser#bestHand
 *   - JRCaptureUser#objectLevelOne
 *   - JRCaptureUser#pinoLevelOne
 *   - JRCaptureUser#primaryAddress
 * .
 * @par
 * If any of these objects are new, or if they need to be updated, this method returns \c YES.
 *
 * @warning
 * This method recursively checks all of the sub-objects of JRCaptureUser
 * but does not check any of the arrays of the JRCaptureUser or the arrays' elements:
 *   - JRCaptureUser#exampleStringPlural, JRExampleStringPluralElement
 *   - JRCaptureUser#favoriteHands, JRFavoriteHandsElement
 *   - JRCaptureUser#games, JRGamesElement
 *   - JRCaptureUser#onipLevelOne, JROnipLevelOneElement
 *   - JRCaptureUser#photos, JRPhotosElement
 *   - JRCaptureUser#pluralLevelOne, JRPluralLevelOneElement
 *   - JRCaptureUser#profiles, JRProfilesElement
 *   - JRCaptureUser#statuses, JRStatusesElement
 *   - JRCaptureUser#tournamentsPlayed, JRTournamentsPlayedElement
 * .
 * @par
 * If you have added or removed any elements from the arrays, you must call the following methods
 * to update the array on Capture: replaceExampleStringPluralArrayOnCaptureForDelegate:context:(),
 *   replaceFavoriteHandsArrayOnCaptureForDelegate:context:(),
 *   replaceGamesArrayOnCaptureForDelegate:context:(),
 *   replaceOnipLevelOneArrayOnCaptureForDelegate:context:(),
 *   replacePhotosArrayOnCaptureForDelegate:context:(),
 *   replacePluralLevelOneArrayOnCaptureForDelegate:context:(),
 *   replaceProfilesArrayOnCaptureForDelegate:context:(),
 *   replaceStatusesArrayOnCaptureForDelegate:context:(),
 *   replaceTournamentsPlayedArrayOnCaptureForDelegate:context:()
 *
 * @par
 * Otherwise, if the array elements' JRCaptureObject#canBeUpdatedOnCapture and JRCaptureObject#needsUpdate returns \c YES, you can update
 * the elements by calling updateOnCaptureForDelegate:context:().
 **/
- (BOOL)needsUpdate;

/**
 * TODO: Doxygen doc
 **/
- (void)updateOnCaptureForDelegate:(id<JRCaptureObjectDelegate>)delegate context:(NSObject *)context;
/*@}*/

/**
 * @name Primitive Getters/Setters 
 **/
/*@{*/
/**
 * Returns the primitive boolean value stored in the exampleBoolean property. Will return \c NO if the
 * exampleBoolean is  nil. **/
- (BOOL)getExampleBooleanBoolValue;

/**
 * Sets the exampleBoolean property to a the primitive boolean value.
 **/
- (void)setExampleBooleanWithBool:(BOOL)boolVal;

/**
 * Returns the primitive integer value stored in the exampleInteger property. Will return \c 0 if the
 * exampleInteger is  nil. **/
- (NSInteger)getExampleIntegerIntegerValue;

/**
 * Sets the exampleInteger property to a the primitive integer value.
 **/
- (void)setExampleIntegerWithInteger:(NSInteger)integerVal;
/*@}*/

@end
