/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#import "../include/cmtl/cmtl.h"

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>

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
