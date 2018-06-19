/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmtl_commandenc_h
#define cmtl_commandenc_h
#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"
#include "enums.h"
#include <stdint.h>

MtRenderCommandEncoder*
mtRenderCommandEncoder(MtCommandBuffer *cmdb, MtRenderPassDesc *passDesc);

void
mtRCESetViewport(MtRenderCommandEncoder *enc, MtViewport *viewport);

void
mtRCESetPipState(MtRenderCommandEncoder *enc, MtRenderPipState *pipState);

void
mtRCESetVertexBytes(MtRenderCommandEncoder *enc,
                    void                   *bytes,
                    size_t                  legth,
                    uint32_t                atIndex);

void
mtRCEDrawPrimitives(MtRenderCommandEncoder *enc,
                    MtPrimitiveType         primType,
                    size_t                  vertStart,
                    size_t                  vertCount);

void
mtRCEEndEncoding(MtRenderCommandEncoder *enc);

#ifdef __cplusplus
}
#endif
#endif /* cmtl_commandenc_h */
