/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmt_types_h
#define cmt_types_h

#include "common.h"

typedef void MtDevice;
typedef void MtRenderDesc;
typedef void MtRenderPipeline;
typedef void MtCommandQueue;
typedef void MtLibrary;
typedef void MtFunction;
typedef void MtRenderCommandEncoder;
typedef void MtRenderPassDesc;
typedef void MtTexture;
typedef void MtCommandBuffer;
typedef void MtDrawable;

typedef struct {
  double originX, originY, width, height, znear, zfar;
} MtViewport;

typedef enum MtFuncType {
  MT_FUNC_VERT = 1,
  MT_FUNC_FRAG = 2
} MtFuncType;

#endif /* cmt_types_h */
