//
//  DZNPhotoDisplayController.h
//  DZNPhotoPickerController
//  https://github.com/dzenbot/DZNPhotoPickerController
//
//  Created by Ignacio Romero Zurbuchen on 10/5/13.
//  Copyright (c) 2014 DZN Labs. All rights reserved.
//  Licence: MIT-Licence
//

#import <UIKit/UIKit.h>

@class DZNPhotoPickerController;

/**
 The collection view controller in charge of displaying the resulting thumb images.
 */
@interface DZNPhotoDisplayViewController : UICollectionViewController

/** The nearest ancestor in the view controller hierarchy that is a photo picker controller. */
@property (nonatomic, readonly) DZNPhotoPickerController *navigationController;
/** The count number of columns of thumbs to be displayed. */
@property (nonatomic, readonly) NSInteger columnCount;
/** The count number of rows of thumbs to be diplayed. */
@property (nonatomic, readonly) NSInteger rowCount;
/** YES if the controller started a request and loading content. */
@property (nonatomic, readonly, getter = isLoading) BOOL loading;

@property (nonatomic, strong, readonly) UISearchBar *searchBar;

@property (nonatomic, copy) UISearchBar * (^customSearchBar)(DZNPhotoDisplayViewController *,CGRect);
@property (nonatomic, copy) UISearchDisplayController * (^customSearchController)(DZNPhotoDisplayViewController *);
@property (nonatomic, copy) void (^loadingCompleted)(DZNPhotoDisplayViewController *);
@property (nonatomic, copy) void (^loadingStarted)(DZNPhotoDisplayViewController *);
@property (nonatomic, copy) UIActivityIndicatorView * (^customActivitySpinner)(DZNPhotoDisplayViewController *);
@property (nonatomic, copy) NSAttributedString * (^descriptionTextForEmptyState)(DZNPhotoDisplayViewController *);
@property (nonatomic, copy) NSAttributedString * (^titleForEmptyDataState)(DZNPhotoDisplayViewController *);

/**
 Stops any loading HTTP request.
 */
- (void)stopLoadingRequest;
- (void)resetPhotos;
- (void)shouldSearchPhotos:(NSString *)keyword;

@end
