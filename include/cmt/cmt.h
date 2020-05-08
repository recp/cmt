/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_h
#define cmt_h
#ifdef __cplusplus
extern "C" {
#endif

#include "macros.h"
#include "common.h"

#include "types.h"
#include "enums.h"
#include "error.h"
#include "pixelformat.h"

#include "event.h"
#include "resource.h"
#include "device.h"

#include "compute/compute-pipeline.h"

#include "kernels/compile-opts.h"
#include "kernels/function.h"
#include "kernels/library.h"

#include "memory/buffer.h"
#include "memory/heap-descriptor.h"
#include "memory/heap.h"
#include "memory/vertex.h"

#include "rendering/depthstencil.h"
#include "rendering/pass.h"
#include "rendering/pipeline.h"

#include "command-buff.h"
#include "command-enc.h"
#include "command-queue.h"
#include "compute-comm-enc.h"


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
