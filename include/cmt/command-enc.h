/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_commandenc_h
#define cmt_commandenc_h
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "types.h"
#include "enums.h"
#include <stdint.h>

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

MT_EXPORT
MtRenderCommandEncoder*
mtRenderCommandEncoder(MtCommandBuffer *cmdb, MtRenderPassDesc *pass);

MT_EXPORT
void
mtFrontFace(MtRenderCommandEncoder *rce, MtWinding winding);

MT_EXPORT
void
mtCullMode(MtRenderCommandEncoder *rce, MtCullMode mode);

MT_EXPORT
void
mtViewport(MtRenderCommandEncoder *rce, MtViewport *viewport);

MT_EXPORT
void
mtSetRenderState(MtRenderCommandEncoder *rce, MtRenderPipeline *pipline);

MT_EXPORT
void
mtSetDepthStencil(MtRenderCommandEncoder *rce, MtDepthStencil *ds);

MT_EXPORT
void
mtVertexBytes(MtRenderCommandEncoder *rce,
              void                   *bytes,
              size_t                  legth,
              uint32_t                atIndex);

MT_EXPORT
void
mtVertexBuffer(MtRenderCommandEncoder *rce,
               MtBuffer                *buf,
               size_t                  off,
               uint32_t                index);

MT_EXPORT
void
mtFragmentBuffer(MtRenderCommandEncoder *rce,
                 MtBuffer               *buf,
                 size_t                  off,
                 uint32_t                index);

MT_EXPORT
void
mtDrawPrims(MtRenderCommandEncoder *rce,
            MtPrimitiveType         type,
            size_t                  start,
            size_t                  count);

MT_EXPORT
void
mtEndEncoding(MtRenderCommandEncoder *rce);

#ifdef __cplusplus
}
#endif
#endif /* cmt_commandenc_h */
