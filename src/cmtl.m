/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#import "../include/cmtl/cmtl.h"

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>

NSString*
mtNSString(const char *str) {
  return [NSString stringWithCString: str
                            encoding: NSUTF8StringEncoding];
}

CMTL_EXPORT
void
mtRelease(void * CF_RELEASES_ARGUMENT obj) {
  [(id)obj release];
}

CF_RETURNS_RETAINED
CMTL_EXPORT
MtDevice*
mtDeviceCreat() {
  return MTLCreateSystemDefaultDevice();
}

CF_RETURNS_RETAINED
CMTL_EXPORT
MtCommandQueue*
mtCommandQueueCreat(MtDevice *device) {
  return [(id<MTLDevice>)device newCommandQueue];
}

CF_RETURNS_RETAINED
CMTL_EXPORT
MtRenderPipDesc*
mtPipDescCreat(MtPixelFormat pixelFormat) {
  MTLRenderPipelineDescriptor *mpipDesc;
  mpipDesc = [MTLRenderPipelineDescriptor new];
  mpipDesc.colorAttachments[0].pixelFormat = (MTLPixelFormat)pixelFormat;
  return mpipDesc;
}

CF_RETURNS_RETAINED
CMTL_EXPORT
MtLibrary*
mtDefaultLibrary(MtDevice *device) {
  return [(id<MTLDevice>)device newDefaultLibrary];
}

CF_RETURNS_RETAINED
CMTL_EXPORT
MtFunction*
mtFuncByName(MtLibrary *lib, const char *name) {
  id<MTLFunction> mfunc;

  mfunc = [(id<MTLLibrary>)lib newFunctionWithName: mtNSString(name)];

  if (mfunc == nil)
    return NULL;

  return mfunc;
}

CMTL_EXPORT
void
mtSetFunc(MtRenderPipDesc *pipDesc,
          MtFunction      *func,
          MtFuncType       functype) {
  MTLRenderPipelineDescriptor *mpip;

  mpip = pipDesc;

  switch (functype) {
    case MT_FUNC_VERT:
      mpip.vertexFunction   = func;
      break;
    case MT_FUNC_FRAG:
      mpip.fragmentFunction = func;
      break;
    default: break;
  }
}

CF_RETURNS_RETAINED
CMTL_EXPORT
MtRenderPipState*
mtPipStateCreat(MtDevice *device, MtRenderPipDesc *pipDesc) {
  NSError *error;
  return [(id<MTLDevice>)device
          newRenderPipelineStateWithDescriptor: (MTLRenderPipelineDescriptor *)pipDesc
                                         error: &error];
}

CF_RETURNS_RETAINED
CMTL_EXPORT
MtRenderPassDesc*
mtPassCreat() {
  return [MTLRenderPassDescriptor new];
}

CMTL_EXPORT
void
mtPassTexture(MtRenderPassDesc *pass,
              int               colorAttch,
              MtTexture        *tex) {
  MTLRenderPassDescriptor *mpass;

  mpass = pass;

  mpass.colorAttachments[colorAttch].texture = tex;
}

CMTL_EXPORT
void
mtPassLoadAction(MtRenderPassDesc *pass,
                 int               colorAttch,
                 MtLoadAction      action) {
  MTLRenderPassDescriptor *mpass;

  mpass = pass;

  mpass.colorAttachments[colorAttch].loadAction = (MTLLoadAction)action;
}

CMTL_EXPORT
MtCommandBuffer*
mtCommandBuff(MtCommandQueue *cmdq) {
  return [(id<MTLCommandQueue>)cmdq commandBuffer];
}

CMTL_EXPORT
void
mtPresent(MtCommandBuffer *cmdb, MtDrawable *drawable) {
  [(id<MTLCommandBuffer>)cmdb presentDrawable: drawable];
}

CMTL_EXPORT
void
mtCommit(MtCommandBuffer *cmdb) {
  [(id<MTLCommandBuffer>)cmdb commit];
}

CMTL_EXPORT
MtRenderCommandEncoder*
mtRenderCommandEncoder(MtCommandBuffer *cmdb, MtRenderPassDesc *passDesc) {
  return [(id<MTLCommandBuffer>)cmdb
          renderCommandEncoderWithDescriptor: passDesc];
}

CMTL_EXPORT
void
mtViewport(MtRenderCommandEncoder *enc, MtViewport *viewport) {
  [(id<MTLRenderCommandEncoder>)enc setViewport: *(MTLViewport *)viewport];
}

CMTL_EXPORT
void
mtRCEPipState(MtRenderCommandEncoder *enc, MtRenderPipState *pipState) {
  [(id<MTLRenderCommandEncoder>)enc setRenderPipelineState: pipState];
}

CMTL_EXPORT
void
mtVertexBytes(MtRenderCommandEncoder *enc,
              void                   *bytes,
              size_t                  legth,
              uint32_t                atIndex) {
  [(id<MTLRenderCommandEncoder>)enc setVertexBytes: bytes
                                            length: legth
                                           atIndex: atIndex];
}

CMTL_EXPORT
void
mtRCEDrawPrimitives(MtRenderCommandEncoder *enc,
                    MtPrimitiveType         primType,
                    size_t                  vertStart,
                    size_t                  vertCount) {
  [(id<MTLRenderCommandEncoder>)enc drawPrimitives: (MTLPrimitiveType)primType
                                       vertexStart: vertStart
                                       vertexCount: vertCount];
}

CMTL_EXPORT
void
mtEndEncoding(MtRenderCommandEncoder *enc) {
  [(id<MTLRenderCommandEncoder>)enc endEncoding];
}
