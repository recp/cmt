/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmtl_enums_h
#define cmtl_enums_h

typedef enum MtLoadAction {
  MtLoadActionDontCare = 0,
  MtLoadActionLoad     = 1,
  MtLoadActionClear    = 2,
} MtLoadAction;

typedef enum MtStoreAction {
  MtStoreActionDontCare                   = 0,
  MtStoreActionStore                      = 1,
  MtStoreActionMultisampleResolve         = 2,
  MtStoreActionStoreAndMultisampleResolve = 3,
  MtStoreActionUnknown                    = 4,
  MtStoreActionCustomSampleDepthStore     = 5,
} MtStoreAction;

#endif /* cmtl_enums_h */
