/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmtl_pipeline_h
#define cmtl_pipeline_h
#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"
#include "enums.h"
#include "pixelformat.h"

MtRenderPipDesc*
mtPipelineDescCreat(MtPixelFormat pixelFormat);

void
mtPipelineSetFunc(MtRenderPipDesc *pipDesc,
                  MtFunction      *func,
                  MtFuncType       functype);

MtRenderPipState*
mtPiplineStateCreat(MtDevice *device, MtRenderPipDesc *pipDesc);

#ifdef __cplusplus
}
#endif
#endif /* cmtl_pipeline_h */
