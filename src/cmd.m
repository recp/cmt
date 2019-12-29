/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#import "common.h"

CF_RETURNS_RETAINED
MT_EXPORT
MtCommandQueue*
mtCommandQueueCreate(MtDevice *device) {
  return [(id<MTLDevice>)device newCommandQueue];
}

MT_EXPORT
MtCommandBuffer*
mtCommandBufferCreate(MtCommandQueue *cmdq) {
  return [(id<MTLCommandQueue>)cmdq commandBuffer];
}

MT_EXPORT
void
mtCommandBufferOnComplete(MtCommandQueue * __restrict cmdb,
                          void           * __restrict sender,
                          MtCommandBufferOnCompleteFn oncomplete) {
  [(id<MTLCommandBuffer>)cmdb addCompletedHandler:^(id<MTLCommandBuffer> buffer) {
    oncomplete(sender, cmdb);
  }];
}

MT_EXPORT
MtCommandBuffer*
mtBufferCreate(MtDevice *device, size_t len, MtResourceOptions options) {
  return [(id<MTLDevice>)device
          newBufferWithLength: len
          options: (MTLResourceOptions)options];
}

MT_EXPORT
MtCommandBuffer*
mtBufferCreateWithBytes(MtDevice   * __restrict device,
                        const void * __restrict bytes,
                        size_t                  len,
                        MtResourceOptions       options) {
  return [(id<MTLDevice>)device
          newBufferWithBytes: bytes
          length:             len
          options:            (MTLResourceOptions)options];
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
