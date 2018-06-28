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
  id<MTLDevice>       mdevice;
  id<MTLCommandQueue> mcmdQueue;

  mdevice   = device;
  mcmdQueue = [mdevice newCommandQueue];

  return mcmdQueue;
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
  id<MTLDevice>  mdevice;
  id<MTLLibrary> mlib;

  mdevice = device;
  mlib    = [mdevice newDefaultLibrary];

  return mlib;
}

MtFunction*
mtFuncByName(MtLibrary *lib, const char *name) {
  id<MTLFunction> mfunc;
  id<MTLLibrary>  mlib;

  mlib  = lib;
  mfunc = [mlib newFunctionWithName: mtNSString(name)];

  if (mfunc == nil)
    return NULL;

  return mfunc;
}

void
mtSetFunc(MtRenderPipDesc *pipDesc,
          MtFunction      *func,
          MtFuncType       functype) {
  MTLRenderPipelineDescriptor *mpip;
  id<MTLFunction>              mfunc;

  mpip  = pipDesc;
  mfunc = func;

  switch (functype) {
    case MT_FUNC_VERT:
      mpip.vertexFunction   = mfunc;
      break;
    case MT_FUNC_FRAG:
      mpip.fragmentFunction = mfunc;
      break;
    default: break;
  }
}

MtRenderPipState*
mtPipStateCreat(MtDevice *device, MtRenderPipDesc *pipDesc) {
  NSError                     *error;
  MTLRenderPipelineDescriptor *mpip;
  id <MTLRenderPipelineState>  mpipState;
  id<MTLDevice>                mdevice;

  mdevice   = device;
  mpip      = pipDesc;
  mpipState = [mdevice newRenderPipelineStateWithDescriptor: mpip
                                                      error: &error];

  return mpipState;
}

MtRenderPassDesc*
mtPassCreat() {
  MTLRenderPassDescriptor *mrenderPassDesc;
  mrenderPassDesc = [MTLRenderPassDescriptor new];
  return mrenderPassDesc;
}

void
mtPassTexture(MtRenderPassDesc *pass,
              int               colorAttch,
              MtTexture        *tex) {
  MTLRenderPassDescriptor *mpass;
  id<MTLTexture>           mtex;

  mpass = pass;
  mtex  = tex;

  mpass.colorAttachments[colorAttch].texture = mtex;
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
  id<MTLCommandQueue>  mcmdQueue;
  id<MTLCommandBuffer> mcmdBuff;

  mcmdQueue = cmdq;
  mcmdBuff  = [mcmdQueue commandBuffer];

  return mcmdBuff;
}

void
mtPresent(MtCommandBuffer *cmdb, MtDrawable *drawable) {
  id<MTLCommandBuffer> mcmdBuff;
  id<MTLDrawable>      mdrawable;

  mcmdBuff  = cmdb;
  mdrawable = drawable;

  [mcmdBuff presentDrawable: mdrawable];
}

void
mtCommit(MtCommandBuffer *cmdb) {
  id<MTLCommandBuffer> mcmdBuff;

  mcmdBuff = cmdb;

  [mcmdBuff commit];
}

MtRenderCommandEncoder*
mtRenderCommandEncoder(MtCommandBuffer *cmdb, MtRenderPassDesc *passDesc) {
  MTLRenderPassDescriptor    *mpass;
  id<MTLRenderCommandEncoder> mrenderEncoder;
  id<MTLCommandBuffer>        mcmdBuff;

  mcmdBuff       = cmdb;
  mpass          = passDesc;
  mrenderEncoder = [mcmdBuff renderCommandEncoderWithDescriptor: mpass];

  return mrenderEncoder;
}

void
mtViewport(MtRenderCommandEncoder *enc, MtViewport *viewport) {
  id<MTLRenderCommandEncoder> mrenderEncoder;

  mrenderEncoder = enc;

  [mrenderEncoder setViewport: *(MTLViewport *)viewport];
}

void
mtRCEPipState(MtRenderCommandEncoder *enc, MtRenderPipState *pipState) {
  id<MTLRenderCommandEncoder> mrenderEncoder;
  id<MTLRenderPipelineState>  mpipState;

  mrenderEncoder = enc;
  mpipState      = pipState;

  [mrenderEncoder setRenderPipelineState: mpipState];
}

void
mtVertexBytes(MtRenderCommandEncoder *enc,
                 void                   *bytes,
                 size_t                  legth,
                 uint32_t                atIndex) {
  id<MTLRenderCommandEncoder> mrenderEncoder;

  mrenderEncoder = enc;

  [mrenderEncoder setVertexBytes: bytes
                          length: legth
                         atIndex: atIndex];
}

void
mtRCEDrawPrimitives(MtRenderCommandEncoder *enc,
                    MtPrimitiveType         primType,
                    size_t                  vertStart,
                    size_t                  vertCount) {
  id<MTLRenderCommandEncoder> mrenderEncoder;

  mrenderEncoder = enc;

  [mrenderEncoder drawPrimitives: (MTLPrimitiveType)primType
                     vertexStart: vertStart
                     vertexCount: vertCount];
}

void
mtEndEncoding(MtRenderCommandEncoder *enc) {
  id<MTLRenderCommandEncoder> mrenderEncoder;

  mrenderEncoder = enc;

  [mrenderEncoder endEncoding];
}
