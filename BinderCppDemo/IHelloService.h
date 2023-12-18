#ifndef IHELLOSERVICE_H
#define IHELLOSERVICE_H

#include <utils/Errors.h>  // for status_t
#include <utils/KeyedVector.h>
#include <utils/RefBase.h>
#include <utils/String8.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/Binder.h>

#define HELLO_SVR_CMD_SAYHELLO     1
#define HELLO_SVR_CMD_SAYHELLO_TO  2

namespace android {

/**
 * 通信协议接口 IHelloService
 * Bn：Binder Server，表示服务端的 Binder 实体。
 * Bp：Binder Proxy，表示客户端的 Binder 引用。
 */
class IHelloService: public IInterface {

public:
    //DECLARE_META_INTERFACE 是一个宏，声明了一些变量和函数
    //DECLARE_META_INTERFACE(HelloService);

    public:
    static const ::android::String16 descriptor;
    static ::android::sp<IHelloService> asInterface(const ::android::sp<::android::IBinder> &obj);
    virtual const ::android::String16 &getInterfaceDescriptor() const;
    IHelloService();
    virtual~
    IHelloService();
    static bool setDefaultImpl(std::unique_ptr<IHelloService> impl);
    static const std::unique_ptr<IHelloService> &getDefaultImpl();
    private:
    static std::unique_ptr<IHelloService> default_impl;
    public:


    // Binder 服务对外提供的功能
	virtual void sayHello() = 0;
	virtual int sayHelloTo(const char *name) = 0;
	
};

//通信协议服务端实现
// BnHelloService -> BnInterface -> BBinder -> IBinder -> RefBase
class BnHelloService: public BnInterface<IHelloService> {

public:
    status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
    void sayHello();
    int sayHelloTo(const char *name);
};

//客户端
// BpHelloService -> BpInterface -> BpRefBase -> RefBase
class BpHelloService: public BpInterface<IHelloService> {
public:
    BpHelloService(const sp<IBinder>& impl);
    void sayHello();
    int sayHelloTo(const char *name);
};

}

#endif