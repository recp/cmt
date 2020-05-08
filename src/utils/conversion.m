#include "impl/conversion.h"

MT_HIDE
NSString*
mtNSString(const char *str) {
  return [NSString stringWithCString: str
                            encoding: NSUTF8StringEncoding];
}

MT_HIDE
const char*
Cstring(NSString* str) {
  return [str cStringUsingEncoding:NSUTF8StringEncoding];
}

MT_HIDE
MTLSize
mtMTLSize(MtSize size) {
	return MTLSizeMake(size.width, size.height, size.depth);
}

MT_HIDE
MtSize
mtSize(MTLSize size) {
	MtSize sz = {size.width, size.height, size.depth};
	return sz;
}

MT_HIDE
NSRange
mtNSRange(NsRange range) {
	return NSMakeRange(range.location, range.length);
}

MT_HIDE
NsRange
mtRange(NSRange range) {
	NsRange r = {range.location, range.length};
	return r;
}

MT_HIDE
const char*
CstringFromDict(NSDictionary<NSErrorUserInfoKey, id> *dict) {
	return Cstring([NSString stringWithFormat:@"Dictionary: %@", dict]);
}
