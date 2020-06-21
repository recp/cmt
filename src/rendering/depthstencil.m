/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#import "impl/common.h"
#import "cmt/rendering/depthstencil.h"

MT_EXPORT
MT_API_AVAILABLE(10.11, 8.0)
MtDepthStencil*
mtDepthStencil(MtCompareFunction depthCompareFunc, bool depthWriteEnabled) {
  MTLDepthStencilDescriptor *depthStateDesc;
  
  depthStateDesc                      = [MTLDepthStencilDescriptor new];
  depthStateDesc.depthCompareFunction = MTLCompareFunctionLess;
  depthStateDesc.depthWriteEnabled    = YES;
  
  return depthStateDesc;
}
