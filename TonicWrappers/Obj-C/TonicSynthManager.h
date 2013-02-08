//
//  TonicSynthManager.h
//  TonicDemo
//
//  Created by Nick Donaldson on 2/8/13.
//  Copyright (c) 2013 Morgan Packard. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Synth.h"

@interface TonicSynthManager : NSObject

+ (TonicSynthManager*)sharedManager;

- (void)startSession;
- (void)endSession;

- (void)addSynthWithName:(NSString*)synthName forKey:(NSString*)key;
- (void)removeSynthForKey:(NSString*)key;

- (Tonic::Synth*)synthForKey:(NSString*)key;


@end
