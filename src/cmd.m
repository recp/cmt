/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#import "common.h"

CF_RETURNS_RETAINED
MT_EXPORT
MtCommandQueue*
mtCommandQueueCreat(MtDevice *device) {
  return [(id<MTLDevice>)device newCommandQueue];
}

MT_EXPORT
MtCommandBuffer*
mtCommandBuff(MtCommandQueue *cmdq) {
  return [(id<MTLCommandQueue>)cmdq commandBuffer];
}

MT_EXPORT
void
mtPresent(MtCommandBuffer *cmdb, MtDrawable *drawable) {
  [(id<MTLCommandBuffer>)cmdb presentDrawable: drawable];
}

MT_EXPORT
void
mtCommit(MtCommandBuffer *cmdb) {
  [(id<MTLCommandBuffer>)cmdb commit];
}
