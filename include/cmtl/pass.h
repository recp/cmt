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
#include "enums.h"

MtRenderPassDesc*
mtPassCreat(void);

void
mtPassSetTexture(MtRenderPassDesc *pass,
                 int               colorAttch,
                 MtTexture        *tex);

void
mtPassSetLoadAction(MtRenderPassDesc *pass,
                    int               colorAttch,
                    MtLoadAction      action);
#ifdef __cplusplus
}
#endif
#endif /* cmtl_h */
