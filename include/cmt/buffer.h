/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_buffer_h
#define cmt_buffer_h
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "resource.h"

MT_EXPORT
MtCommandBuffer*
mtBufferCreate(MtDevice *device, size_t len, MtResourceOptions options);

MT_EXPORT
MtCommandBuffer*
mtBufferCreateWithBytes(MtDevice   * __restrict device,
                        const void * __restrict bytes,
                        size_t                  len,
                        MtResourceOptions       options);

#endif /* cmt_buffer_h */
