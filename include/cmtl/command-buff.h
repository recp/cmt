/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmtl_commandbuff_h
#define cmtl_commandbuff_h
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "types.h"
#include "enums.h"

CMTL_EXPORT
MtCommandBuffer*
mtCommandBuff(MtCommandQueue *cmdq);

CMTL_EXPORT
void
mtPresent(MtCommandBuffer *cmdb, MtDrawable *drawable);

CMTL_EXPORT
void
mtCommit(MtCommandBuffer *cmdb);

#ifdef __cplusplus
}
#endif
#endif /* cmtl_commandbuff_h */
