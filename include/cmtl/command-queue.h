/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmtl_commandqueue_h
#define cmtl_commandqueue_h
#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"
#include "enums.h"

MtCommandQueue*
mtCmdQueue(MtDevice *device);

MtCommandQueue*
mtCommandQueue(MtRenderPipState *device);


#ifdef __cplusplus
}
#endif
#endif /* cmtl_commandqueue_h */
