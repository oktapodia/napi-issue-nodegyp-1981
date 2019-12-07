#include <napi.h>
#include <ApplicationServices/ApplicationServices.h>

Napi::Object getScreenSize(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::Object obj = Napi::Object::New(env);
    CGDirectDisplayID displayID = CGMainDisplayID();
    obj.Set("width", CGDisplayPixelsWide(displayID));
    obj.Set("height", CGDisplayPixelsHigh(displayID));
    fflush(stdout);
    return obj;
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return Napi::Function::New(env, getScreenSize);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)
