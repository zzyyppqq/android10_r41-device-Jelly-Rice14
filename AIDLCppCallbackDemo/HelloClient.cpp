//
// Created by aecg on 2023/12/14.
//
#define LOG_TAG "aidl_cpp"
#include <log/log.h>
#include <stdlib.h>
#include <utils/RefBase.h>
#include <utils/Log.h>
#include <binder/TextOutput.h>
#include <binder/IInterface.h>
#include <binder/IBinder.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "com/zyp/IHello.h"
#include "com/zyp/BpHello.h"
#include "com/zyp/ICallback.h"
#include "com/zyp/BnCallback.h"

using namespace android;

class MyCallback : public com::zyp::BnCallback {
public:
    binder::Status onCallback(const String16 &str) override {
        ALOGD("client: onCallback, receive str: %s", String8(str).string());
        return binder::Status();
    }
};

int main(int argc, char const *argv[])
{
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16("IHello"));
    sp<com::zyp::IHello> hello = interface_cast<com::zyp::IHello>(binder);

    hello->hello();
    sp<MyCallback> myCallback = new MyCallback();
    hello->registerCallback(myCallback);
    int ret = 0;
    hello->sum(1, 2, &ret);

    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();

    return 0;
}