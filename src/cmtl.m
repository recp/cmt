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

void
mtRelease(void *obj) {
  [(id)obj release];
}

MtDevice*
mtDeviceCreat() {
  return MTLCreateSystemDefaultDevice();
}

MtCommandQueue*
mtCommandQueue(MtDevice *device) {
  return [(id<MTLDevice>)device newCommandQueue];
}

MtRenderPipDesc*
mtPipDescCreat(MtPixelFormat pixelFormat) {
  MTLRenderPipelineDescriptor *mpipDesc;
  mpipDesc = [MTLRenderPipelineDescriptor new];
  mpipDesc.colorAttachments[0].pixelFormat = (MTLPixelFormat)pixelFormat;
  return mpipDesc;
}

MtLibrary*
mtDefaultLibrary(MtDevice *device) {
  return [(id<MTLDevice>)device newDefaultLibrary];
}

MtFunction*
mtFuncByName(MtLibrary *lib, const char *name) {
  id<MTLFunction> mfunc;

  mfunc = [(id<MTLLibrary>)lib newFunctionWithName: mtNSString(name)];

  if (mfunc == nil)
    return NULL;

  return mfunc;
}

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

MtRenderPipState*
mtPipStateCreat(MtDevice *device, MtRenderPipDesc *pipDesc) {
  NSError *error;
  return [(id<MTLDevice>)device
          newRenderPipelineStateWithDescriptor: (MTLRenderPipelineDescriptor *)pipDesc
                                         error: &error];
}

MtRenderPassDesc*
mtPassCreat() {
  return [MTLRenderPassDescriptor new];
}

void
mtPassTexture(MtRenderPassDesc *pass,
              int               colorAttch,
              MtTexture        *tex) {
  MTLRenderPassDescriptor *mpass;

  mpass = pass;

  mpass.colorAttachments[colorAttch].texture = tex;
}

void
mtPassLoadAction(MtRenderPassDesc *pass,
                 int               colorAttch,
                 MtLoadAction      action) {
  MTLRenderPassDescriptor *mpass;

  mpass = pass;

  mpass.colorAttachments[colorAttch].loadAction = (MTLLoadAction)action;
}

MtCommandBuffer*
mtCommandBuff(MtCommandQueue *cmdq) {
  return [(id<MTLCommandQueue>)cmdq commandBuffer];
}

void
mtPresent(MtCommandBuffer *cmdb, MtDrawable *drawable) {
  [(id<MTLCommandBuffer>)cmdb presentDrawable: drawable];
}

void
mtCommit(MtCommandBuffer *cmdb) {
  [(id<MTLCommandBuffer>)cmdb commit];
}

MtRenderCommandEncoder*
mtRenderCommandEncoder(MtCommandBuffer *cmdb, MtRenderPassDesc *passDesc) {
  return [(id<MTLCommandBuffer>)cmdb
          renderCommandEncoderWithDescriptor: passDesc];
}

void
mtViewport(MtRenderCommandEncoder *enc, MtViewport *viewport) {
  [(id<MTLRenderCommandEncoder>)enc setViewport: *(MTLViewport *)viewport];
}

void
mtRCEPipState(MtRenderCommandEncoder *enc, MtRenderPipState *pipState) {
  [(id<MTLRenderCommandEncoder>)enc setRenderPipelineState: pipState];
}

void
mtVertexBytes(MtRenderCommandEncoder *enc,
                 void                   *bytes,
                 size_t                  legth,
                 uint32_t                atIndex) {
  [(id<MTLRenderCommandEncoder>)enc setVertexBytes: bytes
                                            length: legth
                                           atIndex: atIndex];
}

void
mtRCEDrawPrimitives(MtRenderCommandEncoder *enc,
                    MtPrimitiveType         primType,
                    size_t                  vertStart,
                    size_t                  vertCount) {
  [(id<MTLRenderCommandEncoder>)enc drawPrimitives: (MTLPrimitiveType)primType
                                       vertexStart: vertStart
                                       vertexCount: vertCount];
}

void
mtEndEncoding(MtRenderCommandEncoder *enc) {
  [(id<MTLRenderCommandEncoder>)enc endEncoding];
}
