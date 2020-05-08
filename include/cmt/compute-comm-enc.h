/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_compute_comm_enc_h
#define cmt_compute_comm_enc_h
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "types.h"
#include "enums.h"

MT_EXPORT
void
mtComputeCommandEncoderRelease(MtComputeCommandEncoder *cce);

// Specifying the Compute Pipeline State

MT_EXPORT
void
mtComputeCommandEncoderSetComputePipelineState(MtComputeCommandEncoder *cce, MtComputePipelineState *state);

// end
MT_EXPORT
void
mtComputeCommandEncoderEndEncoding(MtComputeCommandEncoder *cce);

// Specifying Arguments for a Compute Function

MT_EXPORT
void
mtComputeCommandEncoderSetBufferOffsetAtIndex(MtComputeCommandEncoder *cce, MtBuffer *buf, NsUInteger offset, NsUInteger indx);

MT_EXPORT
void
mtComputeCommandEncoderSetBuffersOffsetsWithRange(MtComputeCommandEncoder **cce, MtBuffer **buf, const NsUInteger *offsets, NsRange range);

MT_EXPORT
void
mtComputeCommandEncoderBufferSetOffsetAtIndex(MtComputeCommandEncoder *cce, NsUInteger offset, NsUInteger indx);

MT_EXPORT
void
mtComputeCommandEncoderSetBytesLengthAtIndex(MtComputeCommandEncoder *cce, const void* ptr, NsUInteger length, NsUInteger indx);

MT_EXPORT
void
mtComputeCommandEncoderSetSamplerStateAtIndex(MtComputeCommandEncoder *cce,  MtSamplerState *sampler, NsUInteger indx);

MT_EXPORT
void
mtComputeCommandEncoderSetSamplerStatesWithRange(MtComputeCommandEncoder *cce,  MtSamplerState **samplers, NsRange range);

MT_EXPORT
void
mtComputeCommandEncoderSetSamplerStateLodMinClampLodMaxClampAtIndex(MtComputeCommandEncoder *cce,  MtSamplerState *sampler, float lodMinClamp, float lodMaxClamp, NsUInteger indx);

MT_EXPORT
void
mtComputeCommandEncoderSetTextureAtIndex(MtComputeCommandEncoder *cce,  MtTexture *tex, NsUInteger indx);

MT_EXPORT
void
mtComputeCommandEncoderSetTexturesWithRange(MtComputeCommandEncoder *cce,  MtTexture **textures, NsRange range);

MT_EXPORT
void
mtComputeCommandEncoderSetThreadgroupMemoryLengthAtIndex(MtComputeCommandEncoder *cce,  NsUInteger length, NsUInteger indx);

// Executing a Compute Function Directly

MT_EXPORT
void
mtComputeCommandEncoderDispatchThreadgroups_threadsPerThreadgroup(MtComputeCommandEncoder *cce, MtSize threadgroupsPerGrid, MtSize threadsPerThreadgroup);

MT_EXPORT
void
mtComputeCommandEncoderDispatchThread_threadsPerThreadgroup(MtComputeCommandEncoder *cce, MtSize threadsPerGrid, MtSize threadsPerThreadgroup);

// Executing a Compute Function Indirectly
MT_EXPORT
void
mtComputeCommandEncoderDispatchThreadgroupsWithIndirectBuffer_IndirectBufferOffset_threadsPerThreadgroup(MtComputeCommandEncoder *cce, MtBuffer *indirectBuffer, NsUInteger indirectBufferOffset, MtSize threadsPerThreadgroup);

// Specifying Resource Usage for Argument Buffers
MT_EXPORT
void
mtComputeCommandEncoderUseResourceUsage(MtComputeCommandEncoder *cce, MtResource *res, MtResourceUsage usage);

MT_EXPORT
void
mtComputeCommandEncoderUseResourcesCountUsage(MtComputeCommandEncoder *cce, MtResource **res, NsUInteger count, MtResourceUsage usage);

MT_EXPORT
void
mtComputeCommandEncoderUseHeap(MtComputeCommandEncoder *cce, MtHeap *heap);

MT_EXPORT
void
mtComputeCommandEncoderUseHeaps(MtComputeCommandEncoder *cce, MtHeap **heaps, NsUInteger count);

#ifdef __cplusplus
}
#endif
#endif /* cmt_compute_comm_enc_h */
