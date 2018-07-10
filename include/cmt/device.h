/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_device_h
#define cmt_device_h
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "types.h"
#include "enums.h"

MT_EXPORT
MtDevice*
mtCreateDevice(void);

#ifdef __cplusplus
}
#endif
#endif /* cmt_device_h */
