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
mtCommandQueue(MtRenderPipelineState *device);

MtRenderPipelineDesc*
mtPipelineDescCreat(MtPixelFormat pixelFormat);

void
mtPipelineSetFunc(MtRenderPipelineDesc *pipDesc,
                  MtFunction                 *func,
                  MtFuncType                  functype);

MtLibrary*
mtDefaultLib(MtDevice *device);

MtFunction*
mtFuncByName(MtLibrary *lib, const char *name);

MtRenderPipelineState*
mtPiplineStateCreat(MtDevice *device, MtRenderPipelineDesc *pipDesc);

MtRenderPassDesc*
mtRenderPassDescCreat(void);

void
mtPassSetTexture(MtRenderPassDesc *pass,
                 int                     colorAttch,
                 MtTexture              *tex);

void
mtPassSetLoadAction(MtRenderPassDesc *pass,
                    int                     colorAttch,
                    MtLoadAction            action);

MtCommandBuffer*
mtCommandBuffer(MtCommandQueue *cmdq);

MtRenderCommandEncoder*
mtRenderCommandEncoder(MtCommandBuffer *cmdb, MtRenderPassDesc *passDesc);

#ifdef __cplusplus
}
#endif
#endif /* cmtl_h */
