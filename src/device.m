/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#import "common.h"

CF_RETURNS_RETAINED
MT_EXPORT
MtDevice*
mtDeviceCreat() {
  return MTLCreateSystemDefaultDevice();
}
