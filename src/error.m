#include "impl/common.h"
#include "cmt/common.h"

NSError* mt_current_error = nil;

MT_EXPORT
void
mtErrorRelease(NsError *err) {
    [(NSError *)err release];
}

MT_EXPORT
void
mtClearError() { 
    if (mt_current_error != nil) {
        [mt_current_error release];
        mt_current_error = nil; 
    }
}

MT_EXPORT
NsError*
mtGetError() { 
    NsError* err = mt_current_error; 
    mt_current_error = nil;
    return err;
}

MT_EXPORT
NsInteger
mtErrorCode(NsError *err) { return [(NSError *)err code]; }

MT_EXPORT
const char*
mtErrorDomain(NsError *err) { 
    return Cstring([(NSError *)err domain]);
}

MT_EXPORT
const char*
mtErrorUserInfo(NsError *err) { 
    return CstringFromDict([(NSError*)err userInfo]);
}

MT_EXPORT
const char*
mtErrorLocalizedDescription(NsError *err) {
    return Cstring([(NSError*)err localizedDescription]);
}

MT_EXPORT
const char**
mtErrorLocalizedRecoveryOptions(NsError *err) {
  NSArray<NSString *> *_strings = [(NSError*)err localizedRecoveryOptions];

  int n = [_strings count];
  const char **strs = malloc(sizeof(char*) * (n + 1));
  for (int i=0; i < n; i++) {
    strs[i] = Cstring([_strings objectAtIndex:i]);
  }
  strs[n] = NULL;

  return strs;
}

MT_EXPORT
const char*
mtErrorLocalizedRecoverySuggestion(NsError *err) {
    return Cstring([(NSError*)err localizedRecoverySuggestion]);
}

MT_EXPORT
const char*
mtErrorLocalizedFailureReason(NsError *err) {
    return Cstring([(NSError*)err localizedFailureReason]);
}



