/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmtl_pass_h
#define cmtl_pass_h
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "types.h"
#include "enums.h"

CMTL_EXPORT
MtRenderPassDesc*
mtPassCreat(void);

CMTL_EXPORT
void
mtPassTexture(MtRenderPassDesc *pass,
              int               colorAttch,
              MtTexture        *tex);

CMTL_EXPORT
void
mtPassLoadAction(MtRenderPassDesc *pass,
                 int               colorAttch,
                 MtLoadAction      action);
#ifdef __cplusplus
}
#endif
#endif /* cmtl_pass_h */
