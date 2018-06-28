/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#import "common.h"

MT_HIDE
NSString*
mtNSString(const char *str) {
  return [NSString stringWithCString: str
                            encoding: NSUTF8StringEncoding];
}

MT_EXPORT
void
mtRelease(void * CF_RELEASES_ARGUMENT obj) {
  [(id)obj release];
}
