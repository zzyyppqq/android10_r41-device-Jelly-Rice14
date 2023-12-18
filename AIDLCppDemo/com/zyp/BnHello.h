#ifndef AIDL_GENERATED_COM_ZYP_BN_HELLO_H_
#define AIDL_GENERATED_COM_ZYP_BN_HELLO_H_

#include <binder/IInterface.h>
#include <com/zyp/IHello.h>

namespace com {

namespace zyp {

class BnHello : public ::android::BnInterface<IHello> {
public:
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnHello

}  // namespace zyp

}  // namespace com

#endif  // AIDL_GENERATED_COM_ZYP_BN_HELLO_H_
