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

int main(int argc, char const *argv[])
{
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16("MyHelloService"));
    sp<com::zyp::IHello> hello = interface_cast<com::zyp::IHello>(binder);

    hello->hello();
    int ret = 0;
    hello->sum(1, 2, &ret);

    return 0;
}
