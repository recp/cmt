/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_h
#define cmt_h
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "types.h"
#include "pixelformat.h"
#include "enums.h"

#include "device.h"
#include "command-buff.h"
#include "command-queue.h"
#include "command-enc.h"
#include "pass.h"
#include "library.h"
#include "pipeline.h"

MT_EXPORT
void*
mtRetain(void *obj);

MT_EXPORT
void
mtRelease(void *obj);

#ifdef __cplusplus
}
#endif
#endif /* cmt_h */
