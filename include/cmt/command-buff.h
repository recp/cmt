/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_commandbuff_h
#define cmt_commandbuff_h
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "types.h"
#include "enums.h"

MT_EXPORT
MtCommandBuffer*
mtCommandBufferCreate(MtCommandQueue *cmdq);

MT_EXPORT
void
mtPresent(MtCommandBuffer *cmdb,
          MtDrawable      *drawable);

MT_EXPORT
void
mtCommit(MtCommandBuffer *cmdb);

#ifdef __cplusplus
}
#endif
#endif /* cmt_commandbuff_h */
