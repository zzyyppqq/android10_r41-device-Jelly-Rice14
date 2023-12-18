#include "IHelloService.h"

namespace android {

BpHelloService::BpHelloService(const sp<IBinder>& impl):BpInterface<IHelloService>(impl) {

}

void BpHelloService::sayHello() {
    Parcel data, reply;
    data.writeInt32(0);
    data.writeString16(String16("IHelloService"));
    // transact()调用的是IPCThreadState::self()->transact(mHandle, code, data, reply, flags);
    remote()->transact(HELLO_SVR_CMD_SAYHELLO, data, &reply);
}

int BpHelloService::sayHelloTo(const char *name) {
    Parcel data, reply;
    int exception;

    data.writeInt32(0);
    data.writeString16(String16("IHelloService"));
    data.writeString16(String16(name));
    remote()->transact(HELLO_SVR_CMD_SAYHELLO_TO, data, &reply);
    exception = reply.readInt32();
	if (exception)
		return -1;
	else
		return reply.readInt32();
}

//IMPLEMENT_META_INTERFACE(HelloService, "android.media.IHelloService");

const ::android::String16 IHelloService::descriptor("android.media.IHelloService");
const ::android::String16 &IHelloService::getInterfaceDescriptor() const { return IHelloService::descriptor; }
::android::sp<IHelloService> IHelloService::asInterface(const ::android::sp<::android::IBinder> &obj) {
    ::android::sp<IHelloService> intr;
    if (obj != nullptr) {
        intr = static_cast<IHelloService *>(
                // BpBinder 未实现 queryLocalInterface 函数
                // 继承了 IBinder 的 queryLocalInterface 函数实现（实现在 frameworks/native/libs/binder/Binder.cpp 中），直接返回 nullptr
                obj->queryLocalInterface(IHelloService::descriptor).get());
        if (intr == nullptr) {
            intr = new BpHelloService(obj);
        }
    }
    return intr;
}
std::unique_ptr<IHelloService>IHelloService::default_impl;
bool IHelloService::setDefaultImpl(std::unique_ptr<IHelloService> impl) {
    if (!IHelloService::default_impl && impl) {
        IHelloService::default_impl = std::move(impl);
        return true;
    }
    return false;
}
const std::unique_ptr<IHelloService> &IHelloService::getDefaultImpl() { return IHelloService::default_impl; }
IHelloService::IHelloService() {}
IHelloService::~IHelloService() {}

}