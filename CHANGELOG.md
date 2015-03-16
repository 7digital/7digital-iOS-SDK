# SevenDigital CHANGELOG

## 1.1.4

Moved SDK network calls off of the main run loop

## 1.1.3

### Removed logging
 - the default track statements have been suppressed.
 - you can re-enable these traces for debugging purposes by adding the following code to your project

		#define SDDEBUG

###Prevents a crash on empty data
- Some servers calls were resulting in a crash, so we've added some measures to prevent this from happening

###Adds previewURLs
- If your account has permission, you can do the following to get a preview for a track.
- Updated readme file to include instructions for this.

###Adds downloads remaining to the SDTrack class.

## 1.1.1

Fixed an oauth bug for JSON requests

## 1.1.0

Added support for sending JSON as part of a request

## 1.0.0

Initial release.
