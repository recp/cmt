/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#import "common.h"

MT_EXPORT
MtRenderCommandEncoder*
mtRenderCommandEncoder(MtCommandBuffer *cmdb, MtRenderPassDesc *pass) {
  return [(id<MTLCommandBuffer>)cmdb renderCommandEncoderWithDescriptor: pass];
}

MT_EXPORT
void
mtFrontFace(MtRenderCommandEncoder *rce, MtWinding winding) {
  [(id<MTLRenderCommandEncoder>)rce setFrontFacingWinding:(MTLWinding)winding];
}

MT_EXPORT
void
mtCullMode(MtRenderCommandEncoder *rce, MtCullMode mode) {
  [(id<MTLRenderCommandEncoder>)rce setCullMode:(MTLCullMode)mode];
}

MT_EXPORT
void
mtViewport(MtRenderCommandEncoder *enc, MtViewport *viewport) {
  [(id<MTLRenderCommandEncoder>)enc setViewport: *(MTLViewport *)viewport];
}

MT_EXPORT
void
mtSetRenderState(MtRenderCommandEncoder *enc, MtRenderPipeline *pipline) {
  [(id<MTLRenderCommandEncoder>)enc setRenderPipelineState: pipline];
}

MT_EXPORT
void
mtSetDepthStencil(MtRenderCommandEncoder *rce, MtDepthStencil *ds) {
  [(id<MTLRenderCommandEncoder>)rce setDepthStencilState: ds];
}

MT_EXPORT
void
mtVertexBytes(MtRenderCommandEncoder *enc,
              void                   *bytes,
              size_t                  legth,
              uint32_t                atIndex) {
  [(id<MTLRenderCommandEncoder>)enc setVertexBytes: bytes
                                            length: legth
                                           atIndex: atIndex];
}

MT_EXPORT
void
mtVertexBuffer(MtRenderCommandEncoder *enc,
               MtBuffer                *buf,
               size_t                  off,
               uint32_t                index) {
  [(id<MTLRenderCommandEncoder>)enc setVertexBuffer: buf
                                             offset: off
                                            atIndex: index];
}

MT_EXPORT
void
mtFragmentBuffer(MtRenderCommandEncoder *enc,
                 MtBuffer                *buf,
                 size_t                  off,
                 uint32_t                index) {
  [(id<MTLRenderCommandEncoder>)enc setFragmentBuffer: buf
                                               offset: off
                                              atIndex: index];
}

MT_EXPORT
void
mtDrawPrimitives(MtRenderCommandEncoder *enc,
                 MtPrimitiveType         primType,
                 size_t                  vertStart,
                 size_t                  vertCount) {
  [(id<MTLRenderCommandEncoder>)enc drawPrimitives: (MTLPrimitiveType)primType
                                       vertexStart: vertStart
                                       vertexCount: vertCount];
}

MT_EXPORT
void
mtEndEncoding(MtRenderCommandEncoder *enc) {
  [(id<MTLRenderCommandEncoder>)enc endEncoding];
}
