/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#import "impl/common.h"
#import "cmt/common.h"
#import "cmt/kernels/library.h"

CF_RETURNS_RETAINED
MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
MtLibrary*
mtNewDefaultLibrary(MtDevice *device) {
  return [(id<MTLDevice>)device newDefaultLibrary];
}

CF_RETURNS_RETAINED
MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
MtLibrary*
mtNewLibraryWithFile(MtDevice *device, char *filepath, NsError *error) {
  return [(id<MTLDevice>)device newLibraryWithFile: mtNSString(filepath) error:(NSError**)&error];
}

CF_RETURNS_RETAINED
MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
MtLibrary*
mtNewLibraryWithSource(MtDevice *device, char *source, MtCompileOptions *Opts, NsError **
  error) {
  NSError *_err;
  MtLibrary* lib = [(id<MTLDevice>)device newLibraryWithSource: mtNSString(source)
                                                       options: (MTLCompileOptions*)Opts
                                                         error: &_err];
  *error = _err;
  return lib;
}

/*CF_RETURNS_RETAINED
MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
MtLibrary*
mtLibraryWithData(MtDevice *device, char *filepath, NsError *error) {
  return [(id<MTLDevice>)device newLibraryWithFile: mtNSString(filepath) error:(NSError**)&error];
}*/

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
MtDevice*
mtLibraryDevice(MtLibrary *lib) {
	return [(id<MTLLibrary>)lib device];
}

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
const char*
mtLibraryLabel(MtLibrary *lib) {
	return Cstring([(id<MTLLibrary>)lib label]);
}

MT_EXPORT
MT_API_AVAILABLE(mt_macos(10.11), mt_ios(8.0))
const char**
mtLibraryFunctionNames(MtLibrary *lib) {
  NSArray<NSString*> *_names;
  const char         **names;
  NSInteger           n;
  
  _names = [(id<MTLLibrary>)lib functionNames];
  n      = [_names count];
  names  = malloc(sizeof(char*) * (n + 1));

  for (int i=0; i < n; i++)
  	names[i] = Cstring([_names objectAtIndex:i]);

  names[n] = NULL;

  return names;
}
