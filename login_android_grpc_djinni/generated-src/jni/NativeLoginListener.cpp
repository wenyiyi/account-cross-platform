// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from demo.djinni

#include "NativeLoginListener.hpp"  // my header
#include "NativeActionResult.hpp"

namespace djinni_generated {

NativeLoginListener::NativeLoginListener() : ::djinni::JniInterface<::demo::LoginListener, NativeLoginListener>() {}

NativeLoginListener::~NativeLoginListener() = default;

NativeLoginListener::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

NativeLoginListener::JavaProxy::~JavaProxy() = default;

void NativeLoginListener::JavaProxy::on_login_finish(const ::demo::ActionResult & c_result) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeLoginListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onLoginFinish,
                           ::djinni::get(::djinni_generated::NativeActionResult::fromCpp(jniEnv, c_result)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NativeLoginListener::JavaProxy::on_sign_finish(const ::demo::ActionResult & c_result) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeLoginListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onSignFinish,
                           ::djinni::get(::djinni_generated::NativeActionResult::fromCpp(jniEnv, c_result)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NativeLoginListener::JavaProxy::on_logout_finish(const ::demo::ActionResult & c_result) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeLoginListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onLogoutFinish,
                           ::djinni::get(::djinni_generated::NativeActionResult::fromCpp(jniEnv, c_result)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NativeLoginListener::JavaProxy::on_check_status_finish(const ::demo::ActionResult & c_result) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeLoginListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onCheckStatusFinish,
                           ::djinni::get(::djinni_generated::NativeActionResult::fromCpp(jniEnv, c_result)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NativeLoginListener::JavaProxy::on_disconnect(const ::demo::ActionResult & c_result) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeLoginListener>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onDisconnect,
                           ::djinni::get(::djinni_generated::NativeActionResult::fromCpp(jniEnv, c_result)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated
