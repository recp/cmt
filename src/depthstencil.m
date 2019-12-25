/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#import "common.h"

MT_EXPORT
MtDepthStencil*
mtDepthStencil() {
  return [MTLDepthStencilDescriptor new];
}
