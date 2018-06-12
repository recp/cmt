/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmtl_pixelformat_h
#define cmtl_pixelformat_h

typedef enum MkPixelFormat {
  MkPixelFormatInvalid                = 0,

  /* Normal 8 bit formats */
  MkPixelFormatA8Unorm                = 1,
  MkPixelFormatR8Unorm                = 10,
  MkPixelFormatR8Unorm_sRGB           = 11,
  MkPixelFormatR8Snorm                = 12,
  MkPixelFormatR8Uint                 = 13,
  MkPixelFormatR8Sint                 = 14,

  /* Normal 16 bit formats */
  MkPixelFormatR16Unorm               = 20,
  MkPixelFormatR16Snorm               = 22,
  MkPixelFormatR16Uint                = 23,
  MkPixelFormatR16Sint                = 24,
  MkPixelFormatR16Float               = 25,

  MkPixelFormatRG8Unorm               = 30,
  MkPixelFormatRG8Unorm_sRGB          = 31,
  MkPixelFormatRG8Snorm               = 32,
  MkPixelFormatRG8Uint                = 33,
  MkPixelFormatRG8Sint                = 34,

  /* Packed 16 bit formats */
  MkPixelFormatB5G6R5Unorm            = 40,
  MkPixelFormatA1BGR5Unorm            = 41,
  MkPixelFormatABGR4Unorm             = 42,
  MkPixelFormatBGR5A1Unorm            = 43,

  /* Normal 32 bit formats */
  MkPixelFormatR32Uint                = 53,
  MkPixelFormatR32Sint                = 54,
  MkPixelFormatR32Float               = 55,
  MkPixelFormatRG16Unorm              = 60,
  MkPixelFormatRG16Snorm              = 62,
  MkPixelFormatRG16Uint               = 63,
  MkPixelFormatRG16Sint               = 64,
  MkPixelFormatRG16Float              = 65,
  MkPixelFormatRGBA8Unorm             = 70,
  MkPixelFormatRGBA8Unorm_sRGB        = 71,
  MkPixelFormatRGBA8Snorm             = 72,
  MkPixelFormatRGBA8Uint              = 73,
  MkPixelFormatRGBA8Sint              = 74,
  MkPixelFormatBGRX8Unorm             = 75,
  MkPixelFormatBGRA8Unorm             = 80,
  MkPixelFormatBGRA8Unorm_sRGB        = 81,

  /* Packed 32 bit formats */
  MkPixelFormatRGB10A2Unorm           = 90,
  MkPixelFormatRGB10A2Uint            = 91,
  MkPixelFormatRG11B10Float           = 92,
  MkPixelFormatRGB9E5Float            = 93,
  MkPixelFormatBGR10A2Unorm           = 94,
  MkPixelFormatBGR10_XR               = 554,
  MkPixelFormatBGR10_XR_sRGB          = 555,

  /* Normal 64 bit formats */

  MkPixelFormatRG32Uint               = 103,
  MkPixelFormatRG32Sint               = 104,
  MkPixelFormatRG32Float              = 105,
  MkPixelFormatRGBA16Unorm            = 110,
  MkPixelFormatRGBA16Snorm            = 112,
  MkPixelFormatRGBA16Uint             = 113,
  MkPixelFormatRGBA16Sint             = 114,
  MkPixelFormatRGBA16Float            = 115,
  MkPixelFormatBGRA10_XR              = 552,
  MkPixelFormatBGRA10_XR_sRGB         = 553,

  /* Normal 128 bit formats */

  MkPixelFormatRGBA32Uint             = 123,
  MkPixelFormatRGBA32Sint             = 124,
  MkPixelFormatRGBA32Float            = 125,

  /* Compressed formats. */

  /* S3TC/DXT */
  MkPixelFormatBC1_RGBA               = 130,
  MkPixelFormatBC1_RGBA_sRGB          = 131,
  MkPixelFormatBC2_RGBA               = 132,
  MkPixelFormatBC2_RGBA_sRGB          = 133,
  MkPixelFormatBC3_RGBA               = 134,
  MkPixelFormatBC3_RGBA_sRGB          = 135,

  /* RGTC */
  MkPixelFormatBC4_RUnorm             = 140,
  MkPixelFormatBC4_RSnorm             = 141,
  MkPixelFormatBC5_RGUnorm            = 142,
  MkPixelFormatBC5_RGSnorm            = 143,

  /* BPTC */
  MkPixelFormatBC6H_RGBFloat          = 150,
  MkPixelFormatBC6H_RGBUfloat         = 151,
  MkPixelFormatBC7_RGBAUnorm          = 152,
  MkPixelFormatBC7_RGBAUnorm_sRGB     = 153,

  /* PVRTC */
  MkPixelFormatPVRTC_RGB_2BPP         = 160,
  MkPixelFormatPVRTC_RGB_2BPP_sRGB    = 161,
  MkPixelFormatPVRTC_RGB_4BPP         = 162,
  MkPixelFormatPVRTC_RGB_4BPP_sRGB    = 163,
  MkPixelFormatPVRTC_RGBA_2BPP        = 164,
  MkPixelFormatPVRTC_RGBA_2BPP_sRGB   = 165,
  MkPixelFormatPVRTC_RGBA_4BPP        = 166,
  MkPixelFormatPVRTC_RGBA_4BPP_sRGB   = 167,

  /* ETC2 */
  MkPixelFormatEAC_R11Unorm           = 170,
  MkPixelFormatEAC_R11Snorm           = 172,
  MkPixelFormatEAC_RG11Unorm          = 174,
  MkPixelFormatEAC_RG11Snorm          = 176,
  MkPixelFormatEAC_RGBA8              = 178,
  MkPixelFormatEAC_RGBA8_sRGB         = 179,

  MkPixelFormatETC2_RGB8              = 180,
  MkPixelFormatETC2_RGB8_sRGB         = 181,
  MkPixelFormatETC2_RGB8A1            = 182,
  MkPixelFormatETC2_RGB8A1_sRGB       = 183,

  /* ASTC */
  MkPixelFormatASTC_4x4_sRGB          = 186,
  MkPixelFormatASTC_5x4_sRGB          = 187,
  MkPixelFormatASTC_5x5_sRGB          = 188,
  MkPixelFormatASTC_6x5_sRGB          = 189,
  MkPixelFormatASTC_6x6_sRGB          = 190,
  MkPixelFormatASTC_8x5_sRGB          = 192,
  MkPixelFormatASTC_8x6_sRGB          = 193,
  MkPixelFormatASTC_8x8_sRGB          = 194,
  MkPixelFormatASTC_10x5_sRGB         = 195,
  MkPixelFormatASTC_10x6_sRGB         = 196,
  MkPixelFormatASTC_10x8_sRGB         = 197,
  MkPixelFormatASTC_10x10_sRGB        = 198,
  MkPixelFormatASTC_12x10_sRGB        = 199,
  MkPixelFormatASTC_12x12_sRGB        = 200,

  MkPixelFormatASTC_4x4_LDR           = 204,
  MkPixelFormatASTC_5x4_LDR           = 205,
  MkPixelFormatASTC_5x5_LDR           = 206,
  MkPixelFormatASTC_6x5_LDR           = 207,
  MkPixelFormatASTC_6x6_LDR           = 208,
  MkPixelFormatASTC_8x5_LDR           = 210,
  MkPixelFormatASTC_8x6_LDR           = 211,
  MkPixelFormatASTC_8x8_LDR           = 212,
  MkPixelFormatASTC_10x5_LDR          = 213,
  MkPixelFormatASTC_10x6_LDR          = 214,
  MkPixelFormatASTC_10x8_LDR          = 215,
  MkPixelFormatASTC_10x10_LDR         = 216,
  MkPixelFormatASTC_12x10_LDR         = 217,
  MkPixelFormatASTC_12x12_LDR         = 218,
  MkPixelFormatGBGR422                = 240,
  MkPixelFormatBGRG422                = 241,

  /* Depth */
  MkPixelFormatDepth16Unorm           = 250,
  MkPixelFormatDepth32Float           = 252,

  /* Stencil */
  MkPixelFormatStencil8               = 253,

  /* Depth Stencil */
  MkPixelFormatDepth24Unorm_Stencil8  = 255,
  MkPixelFormatDepth32Float_Stencil8  = 260,
  MkPixelFormatX32_Stencil8           = 261,
  MkPixelFormatX24_Stencil8           = 262
} MkPixelFormat;

#endif /* cmtl_pixelformat_h */
