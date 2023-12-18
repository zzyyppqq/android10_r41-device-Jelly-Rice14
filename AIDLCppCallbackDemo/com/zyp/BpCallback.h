#ifndef AIDL_GENERATED_COM_ZYP_BP_CALLBACK_H_
#define AIDL_GENERATED_COM_ZYP_BP_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <com/zyp/ICallback.h>

namespace com {

namespace zyp {

class BpCallback : public ::android::BpInterface<ICallback> {
public:
  explicit BpCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCallback() = default;
  ::android::binder::Status onCallback(const ::android::String16& str) override;
};  // class BpCallback

}  // namespace zyp

}  // namespace com

#endif  // AIDL_GENERATED_COM_ZYP_BP_CALLBACK_H_
