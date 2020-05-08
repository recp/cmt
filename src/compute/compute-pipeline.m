#import "impl/common.h"
#import "cmt/common.h"
#import "cmt/compute/compute-pipeline.h"

CF_RETURNS_RETAINED
MT_EXPORT
MtDevice*
mtComputePipelineDevice(MtComputePipelineState *pip) {
	return [(id<MTLComputePipelineState>)pip device];
}

MT_EXPORT
void
mtComputePipelineRelease(MtComputePipelineState *pip) {
	[(id<MTLComputePipelineState>)pip release];
}

MT_EXPORT
const char*
mtComputePipelineLabel(MtComputePipelineState *pip) {
	return Cstring([(id<MTLComputePipelineState>)pip label]);
}

// Properties
MT_EXPORT
NsUInteger
mtComputePipelineMaxTotalThreadsPerThreadgroup(MtComputePipelineState *pip) {
	return [(id<MTLComputePipelineState>)pip maxTotalThreadsPerThreadgroup];
}

MT_EXPORT
NsUInteger
mtComputePipelineThreadExecutionWidth(MtComputePipelineState *pip) {
	return [(id<MTLComputePipelineState>)pip threadExecutionWidth];
}

MT_EXPORT
NsUInteger
mtComputePipelineStaticThreadgroupMemoryLength(MtComputePipelineState *pip) {
	return [(id<MTLComputePipelineState>)pip staticThreadgroupMemoryLength];
}

/*MT_EXPORT
NsUInteger
mtComputePipelineImageblockMemoryLengthForDimensions(MtComputePipelineState *pip, MtSize imageblockDimensions) {
	return [(id<MTLComputePipelineState>)pip imageblockMemoryLengthForDimensions: mtMTLSize(imageblockDimensions)];
} IOS 11*/
