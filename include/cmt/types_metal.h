/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_types_metal_h
#define cmt_types_metal_h

#include "common.h"
#include "types_foundation.h"

typedef struct {
    NsUInteger width, height, depth;
} MtSize;

typedef void MtDevice;
typedef void MtRenderDesc;
typedef void MtRenderPipeline;
typedef void MtCommandQueue;
typedef void MtCommandEncoder;
typedef void MtBlitCommandEncoder;
typedef void MtLibrary;
typedef void MtFunction;
typedef void MtRenderPassDesc;
typedef void MtTexture;
typedef void MtCommandBuffer;
typedef void MtDrawable;
typedef void MtVertexDescriptor;
typedef void MtTextureDescriptor;
typedef void MtIndirectCommandBufferDescriptor;
typedef void MtIndirectCommandBuffer;
typedef void MtIndirectComputeCommand;
typedef void MtIndirectRenderCommand;
typedef void MtDepthStencil;
typedef void MtBuffer;
typedef void MtCompileOptions;

typedef void MtEvent;
typedef void MtSharedEvent;
typedef void MtSharedEventHandle;
typedef void MtFence;
typedef void (^MtSharedEventNotificationBlock)(MtSharedEvent *ev, uint64_t value);
typedef void (*MtCommandBufferHandlerFun)(MtCommandBuffer * buf);
typedef void MtSharedEventListener;

typedef void MtResource;
typedef void MtHeap;
typedef void MtHeapDescriptor;

typedef void MtComputePipelineState;
typedef void MtSamplerState;

typedef void MtRenderCommandEncoder;
typedef void MtComputeCommandEncoder;
typedef void MtBlitCommandEncoder;
typedef void MtResourceStateCommandEncoder;

typedef void MtCounterSampleBuffer;
#endif /* cmt_types_metal_h */
