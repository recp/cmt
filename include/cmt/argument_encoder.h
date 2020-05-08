/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_argument_encoder_h
#define cmt_argument_encoder_h
#ifdef __cplusplus
extern "C" {
#endif

#include "cmt/common.h"
#include "cmt/types.h"
#include "cmt/enums.h"
#include "cmt/resource.h"

MT_EXPORT
MtArgumentEncoder*
mtNewArgumentEncoder(MtDevice *device, MtIndirectCommandBufferDescriptor *desc,
	MtArgumentDescriptor **arguments, uint count); 


#ifdef __cplusplus
}
#endif
#endif /* cmt_argument_encoder_h */
