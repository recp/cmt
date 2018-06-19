/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmtl_library_h
#define cmtl_library_h
#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"
#include "enums.h"

MtLibrary*
mtDefaultLibrary(MtDevice *device);

MtFunction*
mtFuncByName(MtLibrary *lib, const char *name);

#ifdef __cplusplus
}
#endif
#endif /* cmtl_library_h */
