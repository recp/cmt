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

MtDevice*
mtDeviceCreat(void);

MtCommandQueue*
mtCmdQueue(MtDevice *device);

MtCommandQueue*
mtCmdQueue(MtRenderPipelineState *device);

MtRenderPipelineDescriptor*
mtPipelineDescCreat(MtPixelFormat pixelFormat);

#ifdef __cplusplus
}
#endif
#endif /* cmtl_h */
