/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#import "common.h"

MT_EXPORT
MtRenderCommandEncoder*
mtRenderCommandEncoder(MtCommandBuffer  *cmdb,
                       MtRenderPassDesc *passDesc) {
  return [(id<MTLCommandBuffer>)cmdb
          renderCommandEncoderWithDescriptor: passDesc];
}

MT_EXPORT
void
mtViewport(MtRenderCommandEncoder *enc,
           MtViewport             *viewport) {
  [(id<MTLRenderCommandEncoder>)enc setViewport: *(MTLViewport *)viewport];
}

MT_EXPORT
void
mtSetRenderState(MtRenderCommandEncoder *enc,
                 MtRenderState          *pipState) {
  [(id<MTLRenderCommandEncoder>)enc setRenderPipelineState: pipState];
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
