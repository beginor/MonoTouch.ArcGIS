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

#import "AGSSBJsonTokeniser.h"
#import "AGSSBJsonStreamParser.h"

@interface AGSSBJsonStreamParserState : NSObject
+ (id)sharedInstance;
- (BOOL)parser:(AGSSBJsonStreamParser*)parser shouldAcceptToken:(agssbjson_token_t)token;
- (AGSSBJsonStreamParserStatus)parserShouldReturn:(AGSSBJsonStreamParser*)parser;
- (void)parser:(AGSSBJsonStreamParser*)parser shouldTransitionTo:(agssbjson_token_t)tok;
- (BOOL)needKey;

- (NSString*)name;

@end

@interface AGSSBJsonStreamParserStateStart : AGSSBJsonStreamParserState
@end

@interface AGSSBJsonStreamParserStateComplete : AGSSBJsonStreamParserState
@end

@interface AGSSBJsonStreamParserStateError : AGSSBJsonStreamParserState
@end


@interface AGSSBJsonStreamParserStateObjectStart : AGSSBJsonStreamParserState
@end

@interface AGSSBJsonStreamParserStateObjectGotKey : AGSSBJsonStreamParserState
@end

@interface AGSSBJsonStreamParserStateObjectSeparator : AGSSBJsonStreamParserState
@end

@interface AGSSBJsonStreamParserStateObjectGotValue : AGSSBJsonStreamParserState
@end

@interface AGSSBJsonStreamParserStateObjectNeedKey : AGSSBJsonStreamParserState
@end

@interface AGSSBJsonStreamParserStateArrayStart : AGSSBJsonStreamParserState
@end

@interface AGSSBJsonStreamParserStateArrayGotValue : AGSSBJsonStreamParserState
@end

@interface AGSSBJsonStreamParserStateArrayNeedValue : AGSSBJsonStreamParserState
@end
