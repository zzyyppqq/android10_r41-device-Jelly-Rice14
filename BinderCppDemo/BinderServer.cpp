#include <fcntl.h>
#include <sys/prctl.h>
#include <sys/wait.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <cutils/properties.h>
#include <utils/Log.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <log/log.h>


#include "IHelloService.h"


using namespace android;

int main(int argc, char const *argv[])
{
    //使用 ProcessState 类完成 binder 驱动的初始化
    sp<ProcessState> proc(ProcessState::self());
    //sp<ProcessState> proc = ProcessState::self();
    //注册服务
    sp<IServiceManager> sm = defaultServiceManager();
    sm->addService(String16("hello"), new BnHelloService());

    //开启 binder 线程池
	ProcessState::self()->startThreadPool();
    //加入线程池
	IPCThreadState::self()->joinThreadPool();
    
    return 0;
}
