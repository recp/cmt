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

void
mtPipelineSetFunc(MtRenderPipelineDescriptor *pipDesc,
                  MtFunction                 *func,
                  MtFuncType                  functype);

MtLibrary*
mtDefaultLib(MtDevice *device);

MtFunction*
mtFuncByName(MtLibrary *lib, const char *name);

MtRenderPipelineState*
mtPiplineStateCreat(MtDevice *device, MtRenderPipelineDescriptor *pipDesc);

#ifdef __cplusplus
}
#endif
#endif /* cmtl_h */
