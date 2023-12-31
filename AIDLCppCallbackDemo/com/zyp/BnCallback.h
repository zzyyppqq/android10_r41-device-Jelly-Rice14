#ifndef AIDL_GENERATED_COM_ZYP_BN_CALLBACK_H_
#define AIDL_GENERATED_COM_ZYP_BN_CALLBACK_H_

#include <binder/IInterface.h>
#include <com/zyp/ICallback.h>

namespace com {

namespace zyp {

class BnCallback : public ::android::BnInterface<ICallback> {
public:
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCallback

}  // namespace zyp

}  // namespace com

#endif  // AIDL_GENERATED_COM_ZYP_BN_CALLBACK_H_
