#define LOG_TAG "helloserver"

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
#include "com/zyp/BnHello.h"

using namespace android;

class MyHelloService : public com::zyp::BnHello
{
public:
    binder::Status hello()
    {
        ALOGI("server hello function is running");
        return binder::Status();
    }

    binder::Status sum(int32_t v1, int32_t v2, int32_t *_aidl_return) override
    {
        ALOGI("server sum function is running");
        ALOGI("server: sum: %d + %d", v1, v2);
        *_aidl_return = v1 + v2;
        return binder::Status();
    }
};

int main(int argc, char const *argv[])
{
    ALOGD("Hello Server is runing");
    defaultServiceManager()->addService(String16("MyHelloService"), new MyHelloService());
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    return 0;
}
