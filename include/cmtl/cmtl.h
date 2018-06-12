/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmtl_h
#define cmtl_h
#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"
#include "pixelformat.h"

MkDevice*
mtlDeviceCreat(void);

MkCommandQueue*
mtlCmdQueue(MkDevice *device);

MkCommandQueue*
mtlCmdQueue(MkRenderPipelineState *device);

MkRenderPipelineDescriptor*
mtlPipelineDescCreat(MkPixelFormat pixelFormat);

#ifdef __cplusplus
}
#endif
#endif /* cmtl_h */
