/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_commandqueue_h
#define cmt_commandqueue_h
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "types.h"
#include "enums.h"

MT_EXPORT
MtCommandQueue*
mtCommandQueueCreate(MtDevice *device);

#ifdef __cplusplus
}
#endif
#endif /* cmt_commandqueue_h */
