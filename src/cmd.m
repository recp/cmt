/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#import "impl/common.h"
#import "cmt/common.h"
#import "cmt/command-enc.h"
#import "cmt/command-buff.h"

CF_RETURNS_RETAINED
MT_EXPORT
MtCommandQueue*
mtNewCommandQueue(MtDevice *device) {
  return [(id<MTLDevice>)device newCommandQueue];
}

CF_RETURNS_RETAINED
MT_EXPORT
MtCommandQueue*
mtNewCommandQueueWithMaxCommandBufferCount(MtDevice *device, NsUInteger count) {
  return [(id<MTLDevice>)device newCommandQueueWithMaxCommandBufferCount: count];
}

MT_EXPORT
void
mtCommandQueueRelease(MtCommandQueue *queue) {
  [(id<MTLCommandQueue>)queue release];
}

MT_EXPORT
MtCommandBuffer*
mtNewCommandBuffer(MtCommandQueue *cmdq) {
  return [(id<MTLCommandQueue>)cmdq commandBuffer];
}

MT_EXPORT
MtCommandBuffer*
mtNewCommandBufferWithUnretainedReferences(MtCommandQueue *cmdq) {
  return [(id<MTLCommandQueue>)cmdq commandBufferWithUnretainedReferences];
}

MT_EXPORT
void
mtCommandBufferRelease(MtCommandBuffer *cmdbuf) {
  [(id<MTLCommandBuffer>)cmdbuf release];
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
void
mtPresentDrawable(MtCommandBuffer *cmdb, MtDrawable *drawable) {
  [(id<MTLCommandBuffer>)cmdb presentDrawable: drawable];
}

MT_EXPORT
void
mtCommandBufferEqueue(MtCommandBuffer *cmdb) {
  [(id<MTLCommandBuffer>)cmdb enqueue];
}

MT_EXPORT
void
mtCommandBufferCommit(MtCommandBuffer *cmdb) {
  [(id<MTLCommandBuffer>)cmdb commit];
}

MT_EXPORT
void
mtCommandBufferAddScheduledHandler(MtCommandBuffer *cmdb, MtCommandBufferHandler handler) {
  [(id<MTLCommandBuffer>)cmdb addScheduledHandler:(MTLCommandBufferHandler)handler];
}

MT_EXPORT
void
mtCommandBufferAddCompletedHandler(MtCommandBuffer *cmdb, MtCommandBufferHandler handler) {
  [(id<MTLCommandBuffer>)cmdb addCompletedHandler:(MTLCommandBufferHandler)handler];
}

MT_EXPORT
void
mtCommandBufferWaitUntilScheduled(MtCommandBuffer *cmdb) {
  [(id<MTLCommandBuffer>)cmdb waitUntilScheduled];
}

MT_EXPORT
void
mtCommandBufferWaitUntilCompleted(MtCommandBuffer *cmdb) {
  [(id<MTLCommandBuffer>)cmdb waitUntilCompleted];
}

MT_EXPORT
MtCommandBufferStatus
mtCommandBufferStatus(MtCommandBuffer *cmdb) {
  return [(id<MTLCommandBuffer>)cmdb status];
}

MT_EXPORT
NsError*
mtCommandBufferError(MtCommandBuffer *cmdb) {
  return [(id<MTLCommandBuffer>)cmdb error];
}


MT_EXPORT
CfTimeInterval
mtCommandBufferKernelStartTime(MtCommandBuffer *cmdb) {
  return [(id<MTLCommandBuffer>)cmdb kernelStartTime];
}

MT_EXPORT
CfTimeInterval
mtCommandBufferKernelEndTime(MtCommandBuffer *cmdb) {
  return [(id<MTLCommandBuffer>)cmdb kernelEndTime];
}

MT_EXPORT
CfTimeInterval
mtCommandBufferGPUStartTime(MtCommandBuffer *cmdb){
  return [(id<MTLCommandBuffer>)cmdb GPUStartTime];
}

MT_EXPORT
CfTimeInterval
mtCommandBufferGPUEndTime(MtCommandBuffer *cmdb) {
  return [(id<MTLCommandBuffer>)cmdb GPUEndTime];
}

// Events
MT_EXPORT
void
mtCommandBufferEncodeSignalEvent(MtCommandBuffer *cmdb, MtEvent *event, uint64_t val) {
  [(id<MTLCommandBuffer>)cmdb encodeSignalEvent:(id<MTLEvent>)event value: val];
}

MT_EXPORT
void
mtCommandBufferEncodeWaitForEvent(MtCommandBuffer *cmdb,  MtEvent *event, uint64_t val) {
  [(id<MTLCommandBuffer>)cmdb encodeWaitForEvent:(id<MTLEvent>)event value: val];
}

// retained references ?
MT_EXPORT
bool
mtCommandBufferRetainedReferences(MtCommandBuffer *cmdb) {
  return [(id<MTLCommandBuffer>)cmdb retainedReferences];
}

// identifying
MT_EXPORT
MtDevice*
mtCommandBufferDevice(MtCommandBuffer *cmdb) {
  return [(id<MTLCommandBuffer>)cmdb device];
}

MT_EXPORT
MtCommandQueue*
mtCommandBufferCommandQueue(MtCommandBuffer *cmdb) {
  return [(id<MTLCommandBuffer>)cmdb commandQueue];
}

MT_EXPORT
const char*
mtCommandBufferLabel(MtCommandBuffer *cmdb) {
  return Cstring([(id<MTLCommandBuffer>)cmdb label]);
}

MT_EXPORT
void
mtCommandBufferPushDebugGroup(MtCommandBuffer *cmdb, char* str) {
  return [(id<MTLCommandBuffer>)cmdb pushDebugGroup: mtNSString(str)];  
}

MT_EXPORT
void
mtCommandBufferPopDebugGroup(MtCommandBuffer *cmdb) {
  [(id<MTLCommandBuffer>)cmdb popDebugGroup];
}


