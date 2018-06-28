/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#import "common.h"

CF_RETURNS_RETAINED
MT_EXPORT
MtLibrary*
mtDefaultLibrary(MtDevice *device) {
  return [(id<MTLDevice>)device newDefaultLibrary];
}

CF_RETURNS_RETAINED
MT_EXPORT
MtFunction*
mtCreateFunc(MtLibrary *lib, const char *name) {
  return [(id<MTLLibrary>)lib newFunctionWithName: mtNSString(name)];
}
