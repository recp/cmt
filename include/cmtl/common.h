/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmtl_common_h
#define cmtl_common_h


#define CMTL_EXPORT  __attribute__((visibility("default")))
#define CMTL_HIDE    __attribute__((visibility("hidden")))
#define CMTL_INLINE inline __attribute((always_inline))
#define CMTL_ALIGN(X) __attribute((aligned(X)))

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#endif /* cmtl_common_h */
