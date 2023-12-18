PRODUCT_USE_DYNAMIC_PARTITIONS := true

# The system image of aosp_x86_64-userdebug is a GSI for the devices with:
# - x86 64 bits user space
# - 64 bits binder interface
# - system-as-root
# - VNDK enforcement
# - compatible property override enabled

# This is a build configuration for a full-featured build of the
# Open-Source part of the tree. It's geared toward a US-centric
# build quite specifically for the emulator, and might not be
# entirely appropriate to inherit from for on-device configurations.

# GSI for system/product
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/gsi_common.mk)

# Emulator for vendor
$(call inherit-product-if-exists, device/generic/goldfish/x86_64-vendor.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/emulator_vendor.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/board/generic_x86_64/device.mk)

# Enable mainline checking for excat this product name
#ifeq (aosp_x86_64,$(TARGET_PRODUCT))
PRODUCT_ENFORCE_ARTIFACT_PATH_REQUIREMENTS := relaxed
#endif

PRODUCT_ARTIFACT_PATH_REQUIREMENT_WHITELIST += \
    root/init.zygote32_64.rc \
    root/init.zygote64_32.rc \

# Copy different zygote settings for vendor.img to select by setting property
# ro.zygote=zygote64_32 or ro.zygote=zygote32_64:
#   1. 64-bit primary, 32-bit secondary OR
#   2. 32-bit primary, 64-bit secondary
# init.zygote64_32.rc is in the core_64_bit.mk below
PRODUCT_COPY_FILES += \
    system/core/rootdir/init.zygote32_64.rc:root/init.zygote32_64.rc

BOARD_SEPOLICY_DIRS += \
    device/Jelly/Rice14/sepolicy

PRODUCT_PACKAGES += \
    jelly.hardware.hello_hidl@1.0-service \
    hello_hidl_test \
    jelly.hardware.hello_hidl@1.0-impl \
    hello \
    busybox \
    hellojavajar \
    libmymathprebuild \
    FirstSystemApp \
    libmyjnilib \
    JNIApp \
    AsSystemApp \
    initscript \
    helloseandroid \
    binderclient \
    binderserver \
    CppBinderClient \
    CppBinderServer \
    HelloServer \
    HelloClient \


#$(info PRODUCT_PACKAGES = $(PRODUCT_PACKAGES))

#PRODUCT_ARTIFACT_PATH_REQUIREMENT_WHITELIST += \
#    system/bin/hello \


# Overrides
PRODUCT_BRAND := Jelly
PRODUCT_NAME := Rice14
PRODUCT_DEVICE := Rice14
PRODUCT_MODEL := Android SDK built for x86_64 Rice14