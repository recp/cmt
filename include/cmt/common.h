/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_common_h
#define cmt_common_h

#define MT_EXPORT  __attribute__((visibility("default")))
#define MT_HIDE    __attribute__((visibility("hidden")))
#define MT_INLINE inline __attribute((always_inline))
#define MT_ALIGN(X) __attribute((aligned(X)))

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/*
   MT_API_AVAILABLE usage:
   MT_API_AVAILABLE(minimum_macos_version, minimum_ios_version)
 */

#ifdef __APPLE__
#  include <os/availability.h>
#  define MT_API_AVAILABLE(M, I) API_AVAILABLE(macos(M), ios(I))
#else
#  define MT_API_AVAILABLE(M, I)
#endif

#endif /* cmt_common_h */
