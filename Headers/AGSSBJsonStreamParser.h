/*
 Copyright (c) 2010, Stig Brautaset.
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are
 met:
 
   Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
  
   Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
 
   Neither the name of the the author nor the names of its contributors
   may be used to endorse or promote products derived from this software
   without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>

@class AGSSBStateStack;
@class AGSSBJsonTokeniser;
@class AGSSBJsonStreamParser;
@class AGSSBJsonStreamParserState;

typedef enum {
	AGSSBJsonStreamParserComplete,
	AGSSBJsonStreamParserWaitingForData,
	AGSSBJsonStreamParserError,
} AGSSBJsonStreamParserStatus;


/**
 @brief Delegate for interacting directly with the stream parser
 
 You will most likely find it much more convenient to implement the
 SBJsonStreamParserAdapterDelegate protocol instead.
 */
@protocol AGSSBJsonStreamParserDelegate

/// Called when object start is found
- (void)parserFoundObjectStart:(AGSSBJsonStreamParser*)parser;

/// Called when object key is found
- (void)parser:(AGSSBJsonStreamParser*)parser foundObjectKey:(NSString*)key;

/// Called when object end is found
- (void)parserFoundObjectEnd:(AGSSBJsonStreamParser*)parser;

/// Called when array start is found
- (void)parserFoundArrayStart:(AGSSBJsonStreamParser*)parser;

/// Called when array end is found
- (void)parserFoundArrayEnd:(AGSSBJsonStreamParser*)parser;

/// Called when a boolean value is found
- (void)parser:(AGSSBJsonStreamParser*)parser foundBoolean:(BOOL)x;

/// Called when a null value is found
- (void)parserFoundNull:(AGSSBJsonStreamParser*)parser;

/// Called when a number is found
- (void)parser:(AGSSBJsonStreamParser*)parser foundNumber:(NSNumber*)num;

/// Called when a string is found
- (void)parser:(AGSSBJsonStreamParser*)parser foundString:(NSString*)string;

@end


/**
 @brief JSON Stream-parser class
 
 */
@interface AGSSBJsonStreamParser : NSObject {
	BOOL multi;
	id<AGSSBJsonStreamParserDelegate> delegate;
	AGSSBJsonTokeniser *tokeniser;
    AGSSBStateStack *stateStack;
    AGSSBJsonStreamParserState *state;
	NSUInteger maxDepth;
	NSString *error;
}

@property (nonatomic, assign) AGSSBJsonStreamParserState *state; /// Private
@property (nonatomic, readonly, retain) AGSSBStateStack *stateStack; /// Private

/**
 @brief Expect multiple documents separated by whitespace

 If you set this property to true the parser will never return AGSSBJsonStreamParserComplete.
 Once an object is completed it will expect another object to follow, separated only by whitespace.

 @see The TwitterStream example project.
 */
@property BOOL multi;

/// Set this to the object you want to receive messages
@property (assign) id<AGSSBJsonStreamParserDelegate> delegate;

/// The max depth to allow the parser to reach
@property NSUInteger maxDepth;

/// Holds the error after AGSSBJsonStreamParserError was returned
@property (copy) NSString *error;

/**
 @brief Parse some JSON
 
 The JSON is assumed to be UTF8 encoded. This can be a full JSON document, or a part of one.
 
 @return 
 @li AGSSBJsonStreamParserComplete if a full document was found
 @li AGSSBJsonStreamParserWaitingForData if a partial document was found and more data is required to complete it
 @li AGSSBJsonStreamParserError if an error occured. (See the error property for details in this case.)
 
 */
- (AGSSBJsonStreamParserStatus)parse:(NSData*)data;

@end
