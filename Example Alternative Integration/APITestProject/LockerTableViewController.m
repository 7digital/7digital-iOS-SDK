//
//  LockerTableViewController.m
//  APITestProject
//
//  Created by Daniel Too on 7/04/14.
//  Copyright (c) 2014 7digital. All rights reserved.
//

#import "LockerTableViewController.h"
#import "ReleaseTableViewController.h"

@interface LockerTableViewController ()

@property (strong, nonatomic) NSMutableArray *releases;

@end

@implementation LockerTableViewController

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    UIBarButtonItem *logout = [[UIBarButtonItem alloc] initWithTitle:@"Logout" style:UIBarButtonItemStylePlain target:self action:@selector(logoutUser)];
    self.navigationItem.rightBarButtonItem = logout;
    
    self.title = @"Albums";
}

- (void)viewDidAppear:(BOOL)animated {
    
    if (![SevenDigital sharedInstance].isCurrentUserAuthenticated){

// 2-legged oauth option for authorized partners
//        [self performSegueWithIdentifier:@"LoginSegue" sender:self];

// 3-legged oauth option (default)
        [[SevenDigital sharedInstance] presentLoginWebViewFromView:self];
        
    } else {
        [self refreshLocker];
    }
    
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (void)refreshLocker {
    
    if ([SevenDigital sharedInstance].isCurrentUserAuthenticated){
        [SDLockerHelper requestLockerForCurrentUserWithParams:@{@"page":@"1",
                                                           @"pageSize":@"10"}
                                             completion:^(SDAPIResponse *response, NSArray *releasesArray, NSError *error) {
           
            self.releases = [NSMutableArray arrayWithArray:releasesArray];
            
            [self.tableView reloadData];
            
        }];
    } else {
        
        self.releases = nil;
        [self.tableView reloadData];
        
        [[SevenDigital sharedInstance] presentLoginWebViewFromView:self];
        
    }
    
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.releases.count;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Cell" forIndexPath:indexPath];
    
    SDRelease *release = [self.releases objectAtIndex:indexPath.row];
    
    cell.textLabel.text = release.releaseTitle;
    cell.detailTextLabel.text = release.artist.artistName;
    
    // setting the image asynchronously
    __block UITableViewCell *weakcell = cell;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        NSData * imageData = [NSData dataWithContentsOfURL:[NSURL URLWithString:release.imageURL]];
        UIImage * image = [UIImage imageWithData:imageData];
        dispatch_async(dispatch_get_main_queue(), ^{
            weakcell.imageView.image = image;
            [weakcell setNeedsLayout];
        });
    });
    
    return cell;
}

- (void)logoutUser {
    
    [[SevenDigital sharedInstance] logout];
    [self refreshLocker];
    
}

#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{

    if ([segue.identifier isEqualToString:@"releaseSegue"]){
        
        ReleaseTableViewController *releaseTableViewController = (ReleaseTableViewController*)[segue destinationViewController];
        
        SDRelease *aRelease = self.releases[[self.tableView indexPathForSelectedRow].row];
        releaseTableViewController.sdRelease = aRelease;

        releaseTableViewController.title = aRelease.releaseTitle;
    }
    
}

@end
