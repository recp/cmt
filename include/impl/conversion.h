#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#import "cmt/types.h"

MT_HIDE
NSString*
mtNSString(const char *str);

MT_HIDE
const char*
Cstring(NSString* str);

MT_HIDE
MTLSize
mtMTLSize(MtSize size);

MT_HIDE
MtSize
mtSize(MTLSize size);

MT_HIDE
NSRange
mtNSRange(NsRange range);

MT_HIDE
NsRange
mtRange(NSRange range);

/*MT_HIDE
NsDictionaryStringString
mtNsDictionaryStringString(NSDictionary *dict)*/

MT_HIDE
const char*
CstringFromDict(NSDictionary<NSErrorUserInfoKey, id> *dict);