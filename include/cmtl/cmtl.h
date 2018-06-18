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
#include "enums.h"

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

MtRenderPassDescriptor*
mtRenderPassDescCreat(void);

void
mtPassSetTexture(MtRenderPassDescriptor *pass,
                 int                     colorAttch,
                 MtTexture              *tex);

void
mtPassSetLoadAction(MtRenderPassDescriptor *pass,
                    int                     colorAttch,
                    MtLoadAction            action);

#ifdef __cplusplus
}
#endif
#endif /* cmtl_h */
