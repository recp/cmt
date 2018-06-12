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

MtDevice*
mtDeviceCreat() {
  id<MTLDevice> mdevice;
  mdevice = MTLCreateSystemDefaultDevice();
  return (void *)CFBridgingRetain(mdevice);
}

MtCommandQueue*
mtCmdQueue(MtDevice *device) {
  id<MTLDevice>       mdevice;
  id<MTLCommandQueue> mcmdQueue;

  mdevice   = (__bridge id<MTLDevice>)device;
  mcmdQueue = [mdevice newCommandQueue];

  return (void *)CFBridgingRetain(mcmdQueue);
}

MtRenderPipelineDescriptor*
mtPipelineDescCreat(MtPixelFormat pixelFormat) {
  MTLRenderPipelineDescriptor *mpipDesc;
  mpipDesc = [MTLRenderPipelineDescriptor new];
  mpipDesc.colorAttachments[0].pixelFormat = (MTLPixelFormat)pixelFormat;
  return (void *)CFBridgingRetain(mpipDesc);
}

MtLibrary*
mtDefaultLib(MtDevice *device) {
  id<MTLDevice>  mdevice;
  id<MTLLibrary> mlib;

  mdevice = (__bridge id<MTLDevice>)device;
  mlib    = [mdevice newDefaultLibrary];

  return (void *)CFBridgingRetain(mlib);
}

MtFunction*
mtFuncByName(MtLibrary *lib, const char *name) {
  id<MTLFunction> mfunc;
  id<MTLLibrary>  mlib;

  mlib  = (__bridge id<MTLLibrary>)lib;
  mfunc = [mlib newFunctionWithName: mtNSString(name)];

  if (mfunc == nil)
    return NULL;

  return (void *)CFBridgingRetain(mfunc);
}

void
mtPipelineSetFunc(MtRenderPipelineDescriptor *pipDesc,
                  MtFunction                 *func,
                  MtFuncType                  functype) {
  MTLRenderPipelineDescriptor *mpip;
  id<MTLFunction>              mfunc;

  mpip  = (__bridge MTLRenderPipelineDescriptor*)pipDesc;
  mfunc = (__bridge id<MTLFunction>)func;

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

MtRenderPipelineState*
mtPiplineStateCreat(MtDevice *device, MtRenderPipelineDescriptor *pipDesc) {
  NSError                     *error;
  MTLRenderPipelineDescriptor *mpip;
  id <MTLRenderPipelineState>  mpipState;
  id<MTLDevice>                mdevice;

  mdevice   = (__bridge id<MTLDevice>)device;
  mpip      = (__bridge MTLRenderPipelineDescriptor*)pipDesc;
  mpipState = [mdevice newRenderPipelineStateWithDescriptor: mpip
                                                      error: &error];

  return (void *)CFBridgingRetain(mpipState);
}
