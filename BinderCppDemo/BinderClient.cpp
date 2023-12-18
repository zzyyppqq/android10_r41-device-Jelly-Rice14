#include <fcntl.h>
#include <sys/prctl.h>
#include <sys/wait.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <cutils/properties.h>
#include <utils/Log.h>
#include <unistd.h>

#include "IHelloService.h"

using namespace android;

int main(int argc, char const *argv[])
{
    //使用 ProcessState 类完成 binder 驱动的初始化
    sp<ProcessState> proc(ProcessState::self());
    //获取 hello 服务
    sp<IServiceManager> sm = defaultServiceManager();
    //返回的是 BpBinder 指针
    sp<IBinder> binder = sm->getService(String16("hello"));
    //获取的binder是BnHelloService实现了IHelloService接口
    sp<IHelloService> service = interface_cast<IHelloService>(binder);
    // 等价
    sp<IHelloService> service2 = IHelloService::asInterface(binder);

    if (binder == 0)
	{
		ALOGI("can't get hello service\n");
		return -1;
	}
    //发起远程调用
    service->sayHello();
    int cnt = service->sayHelloTo("nihao");
	ALOGI("client call sayhello_to, cnt = %d", cnt);


    return 0;
}
