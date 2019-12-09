#include <stdio.h>
#include <napi.h>
#include <ApplicationServices/ApplicationServices.h>

Napi::Object getScreenSize(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::Object obj = Napi::Object::New(env);
    CGDirectDisplayID displayID = CGMainDisplayID();
    uint32_t width = CGDisplayPixelsWide(displayID);
    uint32_t height = CGDisplayPixelsHigh(displayID);
    fprintf(stderr, "OSX returned %u x %u\n", width, height);
    obj.Set("width", Napi::Number::New(info.Env(), width));
    obj.Set("height", Napi::Number::New(info.Env(), height));
    return obj;
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return Napi::Function::New(env, getScreenSize);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)
