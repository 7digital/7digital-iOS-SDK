# 7digital SDK for iOS

## Introduction
The 7digital iOS SDK helps you to add music features to your app. 
By integrating the SDK you can download and stream 7digital music within your own app. 


## Requirements
The 7digital SDK requires iOS 7.0 or above, and the libxml2 library to run.


##Getting Started

1. SevenDigital is available through [CocoaPods](http://cocoapods.org), to install
it simply add the following line to your Podfile:

    pod "SevenDigital"

2. Register as a developer to get a key and secret at https://api-signup.7digital.com

 Clone the repository, which includes a sample app

3. To run the example project, clone the repo, and run `pod install` from the Example directory.

4. Replace [Your Consumer Key] and [Your Secret] with your own key and secret.  
 
## Alternative Integration

1. Add the files to your project
	1. Download all of the project files
	2. Drag the files in the Classes/ folder to your project
	3. Drag the libSevenDigital.a file to your project

2. Verify that the libSevenDigital.a has been added to the Link Binary with Libraries Build Phase for your target
	1. Go to your Project->Targets->Build Phases->Link Binary With Libraries
	2. If it isn't on the list here, Press the + symbol to add a new framework
	3. Find libSevenDigital.a and click 'Add'

3. Add libxml2.dylib to your Link Binaries With Libraries Build Phase using the same process as in step 2

4. Get your App Credentials at https://api-signup.7digital.com

5. In your Application Delegate:
	1. Import SevenDigital: 
		
			#import "SevenDigital.h"
		
	2. Launch the SevenDigital library with your App Credentials
		In your application:didFinishLaunchingWithOptions: call
		
			[SevenDigital initializeWithConsumerKey:@"[Your Consumer Key]" andSecret:@"[Your Secret]"];
		
6. Many of the 7digital API methods require the user to be logged in. Create your own 7digital account at www.7digital.com


##About the 7digital API
The 7digital API gives developers access to 7digital services and licensed catalogue of over 25m tracks allowing creation of new music applications ranging from simple music discovery websites to fully integrated download stores or full-length streaming services.

Most of the 7digital API is open to everyone and free for non-commercial use (with usage limits in place). Commercial/business use of the API requires a contract with 7digital.

Read more here: http://developer.7digital.com/resources/api-docs/introduction


##About 7digital
7digital is the world’s leading open music platform, and provides open access to the broadest catalogue of fully licensed, high quality digital music. We power comprehensive digital music services for consumers, developers and a wide range of partners around the world. [More about 7digital](http://www.7digital.com/about)

## Support

Visit the [7digital API Google group](https://groups.google.com/forum/?fromgroups#!forum/7digital-api) for tips, questions and comments from other developers.

## License

7digital is available under the Apache license. See the LICENSE file for more info.

