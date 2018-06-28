/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmtl_pipeline_h
#define cmtl_pipeline_h
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "types.h"
#include "enums.h"
#include "pixelformat.h"

MT_EXPORT
MtRenderPipDesc*
mtPipDescCreat(MtPixelFormat pixelFormat);

MT_EXPORT
void
mtSetFunc(MtRenderPipDesc *pipDesc,
          MtFunction      *func,
          MtFuncType       functype);

MT_EXPORT
MtRenderPipState*
mtPipStateCreat(MtDevice *device, MtRenderPipDesc *pipDesc);

#ifdef __cplusplus
}
#endif
#endif /* cmtl_pipeline_h */
