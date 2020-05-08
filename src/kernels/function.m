/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#import "impl/common.h"
#import "cmt/common.h"
#include "cmt/kernels/function.h"

MT_EXPORT
void
mtFunctionRelease(MtFunction* fun) {
	[(id<MTLFunction>)fun release];
}

CF_RETURNS_RETAINED
MT_EXPORT
MtDevice*
mtFunctionDevice(MtFunction* fun) {
	return [(id<MTLFunction>)fun device];
}

MT_EXPORT
const char*
mtFunctionLabel(MtFunction* fun) {
	return Cstring([(id<MTLFunction>)fun label]);
}

MT_EXPORT
MtFunctionType
mtFunctionType(MtFunction* fun) {
	return [(id<MTLFunction>)fun functionType];
}

MT_EXPORT
const char*
mtFunctionName(MtFunction* fun) {
	return Cstring([(id<MTLFunction>)fun name]);
}
