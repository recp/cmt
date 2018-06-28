/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmtl_commandqueue_h
#define cmtl_commandqueue_h
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "types.h"
#include "enums.h"

CMTL_EXPORT
MtCommandQueue*
mtCommandQueue(MtDevice *device);

#ifdef __cplusplus
}
#endif
#endif /* cmtl_commandqueue_h */
