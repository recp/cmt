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

MtLibrary*
mtDefaultLib(MtDevice *device);

MtFunction*
mtFuncByName(MtLibrary *lib, const char *name);

#ifdef __cplusplus
}
#endif
#endif /* cmtl_commandbuff_h */
