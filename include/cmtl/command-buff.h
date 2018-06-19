/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmtl_commandbuff_h
#define cmtl_commandbuff_h
#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"
#include "enums.h"

MtCommandBuffer*
mtCommandBuff(MtCommandQueue *cmdq);

void
mtCommandBuffPresentDrawable(MtCommandBuffer *cmdb, MtDrawable *drawable);

void
mtCommandBuffCommit(MtCommandBuffer *cmdb);

#ifdef __cplusplus
}
#endif
#endif /* cmtl_commandbuff_h */
