/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_function_h
#define cmt_function_h
#ifdef __cplusplus
extern "C" {
#endif

#include "cmt/common.h"
#include "cmt/types.h"
#include "cmt/enums.h"

MT_EXPORT
void
mtFunctionRelease(MtFunction* fun);

MT_EXPORT
MtDevice*
mtFunctionDevice(MtFunction* fun);

MT_EXPORT
const char*
mtFunctionLabel(MtFunction* fun);

MT_EXPORT
MtFunctionType
mtFunctionType(MtFunction* fun);

MT_EXPORT
const char*
mtFunctionName(MtFunction* fun);



#ifdef __cplusplus
}
#endif
#endif /* cmt_function_h */
