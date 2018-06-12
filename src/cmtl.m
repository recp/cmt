/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#import "../include/cmtl/cmtl.h"

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>

MkDevice*
mtlDeviceCreat() {
  id<MTLDevice> mdevice;
  mdevice = MTLCreateSystemDefaultDevice();
  return (void *)CFBridgingRetain(mdevice);
}

MkCommandQueue*
mtlCmdQueue(MkDevice *device) {
  id<MTLDevice>       mdevice;
  id<MTLCommandQueue> mcmdQueue;

  mdevice   = (__bridge id<MTLDevice>)device;
  mcmdQueue = [mdevice newCommandQueue];

  return (void *)CFBridgingRetain(mcmdQueue);
}

MkRenderPipelineDescriptor*
mtlPipelineDescCreat(MkPixelFormat pixelFormat) {
  MTLRenderPipelineDescriptor *mpipDesc;
  mpipDesc = [MTLRenderPipelineDescriptor new];
  mpipDesc.colorAttachments[0].pixelFormat = (MTLPixelFormat)pixelFormat;
  return (void *)CFBridgingRetain(mpipDesc);
}
