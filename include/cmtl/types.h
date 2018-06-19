/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmtl_types_h
#define cmtl_types_h

typedef void MtDevice;
typedef void MtRenderPipelineDesc;
typedef void MtRenderPipelineState;
typedef void MtCommandQueue;
typedef void MtLibrary;
typedef void MtFunction;
typedef void MtRenderCommandEncoder;
typedef void MtRenderPassDesc;
typedef void MtTexture;
typedef void MtCommandBuffer;

typedef struct MtViewport {
  double originX, originY, width, height, znear, zfar;
} MtViewport;

typedef enum MtFuncType {
  MT_FUNC_VERT = 1,
  MT_FUNC_FRAG = 2
} MtFuncType;

#endif /* cmtl_types_h */
