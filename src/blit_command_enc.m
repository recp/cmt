#import "impl/common.h"
#import "cmt/blit_comm_enc.h"


MT_EXPORT void
mtBlitCommandEncoderCopyFromBufferToBuffer(MtBlitCommandEncoder *bce, 
	MtBuffer *src, NsUInteger src_offset, 
	MtBuffer *dst, NsUInteger dst_offset, 
	NsUInteger size) {
	[(id<MTLBlitCommandEncoder>)bce copyFromBuffer: (id<MTLBuffer>)src
							          sourceOffset: src_offset 
							              toBuffer: (id<MTLBuffer>)dst 
							     destinationOffset: dst_offset 
							                  size: size ];
}

MT_EXPORT
void
MtBlitCommandEncoderFillBuffer(MtBlitCommandEncoder *bce, 
	MtBuffer *buf, NsRange range, uint8_t val) {
	[(id<MTLBlitCommandEncoder>)bce fillBuffer: (id<MTLBuffer>)buf 
										 range: mtNSRange(range)
										 value: val];
}

MT_EXPORT
void
MtBlitCommandEncoderGenerateMipmaps(MtBlitCommandEncoder *bce, 
	MtTexture *texture) {
	[(id<MTLBlitCommandEncoder>)bce generateMipmapsForTexture:(id<MTLTexture>)texture];
}


MT_EXPORT
void
MtBlitCommandEncoderCopyIndirectCommandBuffer(MtBlitCommandEncoder *bce, 
	MtIndirectCommandBuffer *src, NsRange range,
	MtIndirectCommandBuffer *dst, NsUInteger dst_index) {
	[(id<MTLBlitCommandEncoder>)bce copyIndirectCommandBuffer: (id<MTLIndirectCommandBuffer>)src
							                      sourceRange: mtNSRange(range) 
					                       		  destination:(id<MTLIndirectCommandBuffer>)dst 
					                 		 destinationIndex: dst_index ];

}

MT_EXPORT
void
MtBlitCommandEncoderOptimizeIndirectCommandBuffer(MtBlitCommandEncoder *bce, 
	MtIndirectCommandBuffer *buffer, NsRange range) {
	[(id<MTLBlitCommandEncoder>)bce 
			optimizeIndirectCommandBuffer: (id<MTLIndirectCommandBuffer>)buffer 
                            	withRange: mtNSRange(range)];

}

MT_EXPORT
void
MtBlitCommandEncoderResetCommandsInBuffer(MtBlitCommandEncoder *bce, 
	MtIndirectCommandBuffer *buffer, NsRange range) {
		[(id<MTLBlitCommandEncoder>)bce 
			resetCommandsInBuffer: (id<MTLIndirectCommandBuffer>)buffer 
                        withRange: mtNSRange(range)];

}

MT_EXPORT
void
MtBlitCommandEncoderSynchronizeResource(MtBlitCommandEncoder *bce, 
	MtResource *resource) {
	[(id<MTLBlitCommandEncoder>)bce synchronizeResource: (id<MTLResource>)resource];
}

MT_EXPORT
void
MtBlitCommandEncoderSynchronizeTexture(MtBlitCommandEncoder *bce, 
	MtTexture *texture, NsUInteger slice, NsUInteger level){
	[(id<MTLBlitCommandEncoder>)bce synchronizeTexture: (id<MTLTexture>)texture
				slice: slice level:level];
}

MT_EXPORT
void
MtBlitCommandEncoderUpdateFence(MtBlitCommandEncoder *icb, MtFence *fence) {
	[(id<MTLBlitCommandEncoder>)icb updateFence: (id<MTLFence>)fence];
}

MT_EXPORT
void
MtBlitCommandEncoderWaitForFence(MtBlitCommandEncoder *icb, MtFence *fence) {
	[(id<MTLBlitCommandEncoder>)icb waitForFence: (id<MTLFence>)fence];
}

MT_EXPORT
void
MtBlitCommandEncoderOptimizeContentsForGPUAccess(MtIndirectCommandBuffer *icb,
													MtTexture *tex) {
	[(id<MTLBlitCommandEncoder>)icb optimizeContentsForGPUAccess: (id<MTLTexture>)tex];
}

MT_EXPORT
void
MtBlitCommandEncoderOptimizeContentsForGPUAccessSliceLevel(MtIndirectCommandBuffer *icb,
													MtTexture *tex, NsUInteger slice, NsUInteger level) {
	[(id<MTLBlitCommandEncoder>)icb optimizeContentsForGPUAccess: (id<MTLTexture>)tex
		slice:slice level:level];
}

MT_EXPORT
void
MtBlitCommandEncoderOptimizeContentsForCPUAccess(MtIndirectCommandBuffer *icb,
													MtTexture *tex) {
	[(id<MTLBlitCommandEncoder>)icb optimizeContentsForCPUAccess: (id<MTLTexture>)tex];
}

MT_EXPORT
void
MtBlitCommandEncoderOptimizeContentsForCPUAccessSliceLevel(MtIndirectCommandBuffer *icb,
													MtTexture *tex, NsUInteger slice, NsUInteger level) {
	[(id<MTLBlitCommandEncoder>)icb optimizeContentsForCPUAccess: (id<MTLTexture>)tex
		slice:slice level:level];
}

MT_EXPORT
void
MtBlitCommandEncoderSampleCountersInBuffer(MtIndirectCommandBuffer *icb,
											MtCounterSampleBuffer *sbuf,
											NsUInteger sampleindex,
											bool barrier){
	[(id<MTLBlitCommandEncoder>)icb sampleCountersInBuffer: (id<MTLCounterSampleBuffer>) sbuf
		atSampleIndex: sampleindex 
		withBarrier: barrier];
}


MT_EXPORT
void
MtBlitCommandEncoderResolveCounters(MtIndirectCommandBuffer *icb,
									MtCounterSampleBuffer *sbuf,
									NsRange range,
									MtBuffer *dst,
									NsUInteger dst_offset) {
	[(id<MTLBlitCommandEncoder>)icb resolveCounters: (id<MTLCounterSampleBuffer>)sbuf 
							                inRange: mtNSRange(range) 
							      destinationBuffer: (id<MTLBuffer>)dst 
							      destinationOffset: dst_offset];
}
