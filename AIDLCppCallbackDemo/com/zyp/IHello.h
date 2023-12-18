#ifndef AIDL_GENERATED_COM_ZYP_I_HELLO_H_
#define AIDL_GENERATED_COM_ZYP_I_HELLO_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <com/zyp/ICallback.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace com {

namespace zyp {

class IHello : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Hello)
  virtual ::android::binder::Status hello() = 0;
  virtual ::android::binder::Status sum(int32_t x, int32_t y, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status registerCallback(const ::android::sp<::com::zyp::ICallback>& cb) = 0;
};  // class IHello

class IHelloDefault : public IHello {
public:
  ::android::IBinder* onAsBinder() override;
  ::android::binder::Status hello() override;
  ::android::binder::Status sum(int32_t x, int32_t y, int32_t* _aidl_return) override;
  ::android::binder::Status registerCallback(const ::android::sp<::com::zyp::ICallback>& cb) override;

};

}  // namespace zyp

}  // namespace com

#endif  // AIDL_GENERATED_COM_ZYP_I_HELLO_H_
