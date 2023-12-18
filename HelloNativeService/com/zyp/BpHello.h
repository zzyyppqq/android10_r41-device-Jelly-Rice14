#ifndef AIDL_GENERATED_COM_ZYP_BP_HELLO_H_
#define AIDL_GENERATED_COM_ZYP_BP_HELLO_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <com/zyp/IHello.h>

namespace com {

namespace zyp {

class BpHello : public ::android::BpInterface<IHello> {
public:
  explicit BpHello(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpHello() = default;
  ::android::binder::Status hello() override;
  ::android::binder::Status sum(int32_t x, int32_t y, int32_t* _aidl_return) override;
};  // class BpHello

}  // namespace zyp

}  // namespace com

#endif  // AIDL_GENERATED_COM_ZYP_BP_HELLO_H_
