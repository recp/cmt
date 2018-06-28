/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#import "../include/cmtl/cmtl.h"

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>

CF_RETURNS_RETAINED
MT_EXPORT
MtDevice*
mtDeviceCreat() {
  return MTLCreateSystemDefaultDevice();
}
