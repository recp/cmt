
#ifndef cmt_blit_comm_enc_h
#define cmt_blit_comm_enc_h
#ifdef __cplusplus
extern "C" {
#endif

#include "cmt/common.h"
#include "cmt/types.h"
#include "cmt/enums.h"

MT_EXPORT
void
mtBlitCommandEncoderCopyFromBufferToBuffer(MtBlitCommandEncoder *bce, 
	MtBuffer *src, NsUInteger src_offset, 
	MtBuffer *dst, NsUInteger dst_offset, 
	NsUInteger size);

MT_EXPORT
void
MtBlitCommandEncoderFillBuffer(MtBlitCommandEncoder *bce, 
	MtBuffer *src, NsRange range, uint8_t val);

MT_EXPORT
void
MtBlitCommandEncoderGenerateMipmaps(MtBlitCommandEncoder *bce, 
	MtTexture *texture);

MT_EXPORT
void
MtBlitCommandEncoderCopyIndirectCommandBuffer(MtBlitCommandEncoder *bce, 
	MtIndirectCommandBuffer *src, NsRange range,
	MtIndirectCommandBuffer *dst, NsUInteger dst_index);

MT_EXPORT
void
MtBlitCommandEncoderOptimizeIndirectCommandBuffer(MtBlitCommandEncoder *bce, 
	MtIndirectCommandBuffer *buffer, NsRange range);

MT_EXPORT
void
MtBlitCommandEncoderResetCommandsInBuffer(MtBlitCommandEncoder *bce, 
	MtIndirectCommandBuffer *buffer, NsRange range);

MT_EXPORT
void
MtBlitCommandEncoderSynchronizeResource(MtBlitCommandEncoder *bce, 
	MtResource *resource);

MT_EXPORT
void
MtBlitCommandEncoderSynchronizeTexture(MtBlitCommandEncoder *bce, 
	MtTexture *texture, NsUInteger slice, NsUInteger level);

MT_EXPORT
void
MtBlitCommandEncoderUpdateFence(MtIndirectCommandBuffer *icb, MtFence *fence);

MT_EXPORT
void
MtBlitCommandEncoderWaitForFence(MtIndirectCommandBuffer *icb, MtFence *fence);

MT_EXPORT
void
MtBlitCommandEncoderOptimizeContentsForGPUAccess(MtIndirectCommandBuffer *icb,
													MtTexture *tex);

MT_EXPORT
void
MtBlitCommandEncoderOptimizeContentsForGPUAccessSliceLevel(MtIndirectCommandBuffer *icb,
													MtTexture *tex, NsUInteger slice, NsUInteger level);


MT_EXPORT
void
MtBlitCommandEncoderOptimizeContentsForCPUAccess(MtIndirectCommandBuffer *icb,
													MtTexture *tex);

MT_EXPORT
void
MtBlitCommandEncoderOptimizeContentsForCPUAccessSliceLevel(MtIndirectCommandBuffer *icb,
													MtTexture *tex, NsUInteger slice, NsUInteger level);

// GPU Execution data
MT_EXPORT
void
MtBlitCommandEncoderSampleCountersInBuffer(MtIndirectCommandBuffer *icb,
											MtCounterSampleBuffer *sbuf,
											NsUInteger sampleindex,
											bool barrier);

MT_EXPORT void
MtBlitCommandEncoderResolveCounters(MtIndirectCommandBuffer *icb,
									MtCounterSampleBuffer *sbuf,
									NsRange range,
									MtBuffer *dst,
									NsUInteger dst_offset);


#ifdef __cplusplus
}
#endif
#endif /* cmt_blit_comm_enc_h */
