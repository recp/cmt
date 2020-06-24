# Apple's Metal for `C`

C Wrapper for Apple's METAL framework. This library is C bindings of Metal API (MetalGL). Since **OpenGL** is deprecated, this library may build OpenGL api on this library. This could save old games and apps on macOS platform.

Also since this is C bindings for Metal API, it also can help other languages to use Metal with this library. 

Currently this library does not alloc memory for its types. It retains ObjC objects and work on them. This also makes the library very very thin layer on ObjC. 

This is NOT generic rendering library. If you need to that, check this one: [Graphics Kernel](https://github.com/recp/gk), it is also written in C and provides common rendering techniques. It will be cross platform. Since [Graphics Kernel](https://github.com/recp/gk) needs to run on macOS, this library will be macOS backend for that purpose.

### Design

```C
MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))  /* API AVAILABILITY */
[returnType]
mt[FunctionName]([Params]);

```

functions are marked with `MT_API_AVAILABLE` which helps to identify which api available on which platform. The first parameter is minimum **macOS** version and the second one is the minimum **iOS** version.

### Building and linking

A CMake project is included that builds a shared library. The headers for that library are contained in `include/cmt`, and are bare-C.


### Sample usage:

```C

MtDevice                   *device;
MtCommandQueue             *cmdQueue;
MtRenderPipelineDescriptor *pipDesc;
MtLibrary                  *lib;
MtFunction                 *vertFunc, *fragFunc;
MtRenderPipelineState      *pip;

device   = mtCreateDevice();
lib      = mtDefaultLibrary(device);
cmdQueue = mtCommandQueueCreate(device);
pipDesc  = mtRenderDescCreate(MtPixelFormatBGRA8Unorm);

vertFunc = mtCreateFunc(lib, "vertexShader");
fragFunc = mtCreateFunc(lib, "fragmentShader");

mtSetFunc(pipDesc, vertFunc, MT_FUNC_VERT);
mtSetFunc(pipDesc, fragFunc, MT_FUNC_FRAG);

pip = mtRenderStateCreate(device, pipDesc);
  
```

### Trademarks

Apple name/logo and Metal are trademarks of Apple Inc. This software only provides C bindings for Metal, it is not alternative to Metal.
