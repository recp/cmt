/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_enums_h
#define cmt_enums_h

#include "common.h"

typedef enum MtPrimitiveType {
  MtPrimitiveTypePoint         = 0,
  MtPrimitiveTypeLine          = 1,
  MtPrimitiveTypeLineStrip     = 2,
  MtPrimitiveTypeTriangle      = 3,
  MtPrimitiveTypeTriangleStrip = 4
} MtPrimitiveType;

typedef enum MtVisibilityResultMode {
  MtVisibilityResultModeDisabled = 0,
  MtVisibilityResultModeBoolean  = 1,
  MtVisibilityResultModeCounting = 2
} MtVisibilityResultMode;

typedef struct MtScissorRect {
  uint32_t x, y, width, height;
} MtScissorRect;

typedef struct MtViewport {
  double originX, originY, width, height, znear, zfar;
} MtViewport;

typedef enum MtCullMode {
  MtCullModeNone  = 0,
  MtCullModeFront = 1,
  MtCullModeBack  = 2
} MtCullMode;

typedef enum MtWinding {
  MtWindingClockwise        = 0,
  MtWindingCounterClockwise = 1
} MtWinding;

typedef enum MtDepthClipMode {
  MtDepthClipModeClip  = 0,
  MtDepthClipModeClamp = 1
} MtDepthClipMode;

typedef enum MtTriangleFillMode {
  MtTriangleFillModeFill  = 0,
  MtTriangleFillModeLines = 1
} MtTriangleFillMode;

typedef struct MtDrawPrimitivesIndirectArguments {
    uint32_t vertexCount;
    uint32_t instanceCount;
    uint32_t vertexStart;
    uint32_t baseInstance;
} MtDrawPrimitivesIndirectArguments;

typedef struct MtDrawIndexedPrimitivesIndirectArguments {
    uint32_t indexCount;
    uint32_t instanceCount;
    uint32_t indexStart;
    int32_t  baseVertex;
    uint32_t baseInstance;
} MtDrawIndexedPrimitivesIndirectArguments;

typedef struct MtDrawPatchIndirectArguments {
    uint32_t patchCount;
    uint32_t instanceCount;
    uint32_t patchStart;
    uint32_t baseInstance;
} MtDrawPatchIndirectArguments;

typedef struct MtQuadTessellationFactorsHalf {
    uint16_t edgeTessellationFactor[4];
    uint16_t insideTessellationFactor[2];
} MtQuadTessellationFactorsHalf;

typedef struct MtTriangleTessellationFactorsHalf {
  uint16_t edgeTessellationFactor[3];
  uint16_t insideTessellationFactor;
} MtTriangleTessellationFactorsHalf;

typedef enum MtRenderStages {
  MtRenderStageVertex   = (1UL << 0),
  MtRenderStageFragment = (1UL << 1)
} MtRenderStages;

typedef enum MtLoadAction {
  MtLoadActionDontCare = 0,
  MtLoadActionLoad     = 1,
  MtLoadActionClear    = 2,
} MtLoadAction;

typedef enum MtIndexType {
  MtIndexTypeUInt16 = 0,
  MtIndexTypeUInt32 = 1,
} MtIndexType;

typedef enum MtStoreAction {
  MtStoreActionDontCare                   = 0,
  MtStoreActionStore                      = 1,
  MtStoreActionMultisampleResolve         = 2,
  MtStoreActionStoreAndMultisampleResolve = 3,
  MtStoreActionUnknown                    = 4,
  MtStoreActionCustomSampleDepthStore     = 5,
} MtStoreAction;

typedef enum MtDeviceLocation {
	MtDeviceLocationBuiltIn = 0,
    MtDeviceLocationSlot = 1,
    MtDeviceLocationExternal = 2,
    MtDeviceLocationUnspecified = 100,
} MtDeviceLocation;

typedef enum MtLanguageVersion {
    MtLanguageVersion1_0  = (1 << 16),
    MtLanguageVersion1_1  = (1 << 16) + 1,
    MtLanguageVersion1_2  = (1 << 16) + 2,
    MtLanguageVersion2_0  = (2 << 16),
    MtLanguageVersion2_1  = (2 << 16) + 1,
    MtLanguageVersion2_2  = (2 << 16) + 2,
} MtLanguageVersion;

typedef enum MtFunctionType {
  MtFunctionTypeVertex = 1,
  MtFunctionTypeFragment = 2,
  MtFunctionTypeKernel = 3,
} MtFunctionType;

typedef enum MtDispatchType {
    MtDispatchTypeSerial,
    MtDispatchTypeConcurrent,
} MtDispatchType;

typedef enum MtCommandBufferStatus {
    MtCommandBufferStatusNotEnqueued = 0,
    MtCommandBufferStatusEnqueued = 1,
    MtCommandBufferStatusCommitted = 2,
    MtCommandBufferStatusScheduled = 3,
    MtCommandBufferStatusCompleted = 4,
    MtCommandBufferStatusError = 5,
} MtCommandBufferStatus;

typedef enum MtResourceUsage {
  MtResourceUsageRead   = 1 << 0,
  MtResourceUsageWrite  = 1 << 1,
  MtResourceUsageSample = 1 << 2
} MtResourceUsage;

typedef enum MtGPUFamily {
    MtGPUFamilyApple1 = 1001,
    MtGPUFamilyApple2 = 1002,
    MtGPUFamilyApple3 = 1003,
    MtGPUFamilyApple4 = 1004,
    MtGPUFamilyApple5 = 1005,
    
    MtGPUFamilyMac1 = 2001,
    MtGPUFamilyMac2 = 2002,
    
    MtGPUFamilyCommon1 = 3001,
    MtGPUFamilyCommon2 = 3002,
    MtGPUFamilyCommon3 = 3003,
    
    MtGPUFamilyMacCatalyst1 = 4001,
    MtGPUFamilyMacCatalyst2 = 4002,
} MtGPUFamily;

typedef enum MtFeatureSet {
    MtFeatureSet_macOS_GPUFamily1_v1 = 10000,
    MtFeatureSet_OSX_GPUFamily1_v1 = MtFeatureSet_macOS_GPUFamily1_v1, // deprecated

    MtFeatureSet_macOS_GPUFamily1_v2 = 10001,
    MtFeatureSet_OSX_GPUFamily1_v2 = MtFeatureSet_macOS_GPUFamily1_v2, // deprecated
    MtFeatureSet_macOS_ReadWriteTextureTier2 = 10002,
    MtFeatureSet_OSX_ReadWriteTextureTier2 = MtFeatureSet_macOS_ReadWriteTextureTier2, // deprecated

    MtFeatureSet_macOS_GPUFamily1_v3 = 10003,
    
    MtFeatureSet_macOS_GPUFamily1_v4 = 10004,
    MtFeatureSet_macOS_GPUFamily2_v1 = 10005,
} MtFeatureSet;

typedef enum MtPurgeableState {
    MtPurgeableStateKeepCurrent = 1,
    
    MtPurgeableStateNonVolatile = 2,
    MtPurgeableStateVolatile = 3,
    MtPurgeableStateEmpty = 4,
} MtPurgeableState;

typedef enum MtCommandBufferError {
    MtCommandBufferErrorNone = 0,
    MtCommandBufferErrorInternal = 1,
    MtCommandBufferErrorTimeout = 2,
    MtCommandBufferErrorPageFault = 3,
    MtCommandBufferErrorBlacklisted = 4,
    MtCommandBufferErrorNotPermitted = 7,
    MtCommandBufferErrorOutOfMemory = 8,
    MtCommandBufferErrorInvalidResource = 9,
    MtCommandBufferErrorMemoryless = 10,
    MtCommandBufferErrorDeviceRemoved = 11,
} MtCommandBufferError;

/*!
 @enum MTLHeapType
 @abstract Describes the mode of operation for an MTLHeap.
 @constant MTLHeapTypeAutomatic
 In this mode, resources are placed in the heap automatically.
 Automatically placed resources have optimal GPU-specific layout, and may perform better than MTLHeapTypePlacement.
 This heap type is recommended when the heap primarily contains temporary write-often resources.
 @constant MTLHeapTypePlacement
 In this mode, the app places resources in the heap.
 Manually placed resources allow the app to control memory usage and heap fragmentation directly.
 This heap type is recommended when the heap primarily contains persistent write-rarely resources.
 */
typedef enum MtHeapType {
  MtHeapTypeAutomatic = 0,
    MtHeapTypePlacement = 1,
} MtHeapType;


typedef enum MtBlitOption {
  MtBlitOptionNone                       = 0,
  MtBlitOptionDepthFromDepthStencil      = 1 << 0,
  MtBlitOptionStencilFromDepthStencil    = 1 << 1,
  } MtBlitOption;

#endif /* cmt_enums_h */
