/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_pipeline_h
#define cmt_pipeline_h
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "types.h"
#include "enums.h"
#include "pixelformat.h"

MT_EXPORT
MtRenderDesc*
mtRenderDescCreate(MtPixelFormat pixelFormat);

MT_EXPORT
void
mtSetFunc(MtRenderDesc *pipDesc,
          MtFunction   *func,
          MtFuncType    functype);

MT_EXPORT
MtRenderState*
mtRenderStateCreate(MtDevice     *device,
                    MtRenderDesc *pipDesc);

#ifdef __cplusplus
}
#endif
#endif /* cmt_pipeline_h */
