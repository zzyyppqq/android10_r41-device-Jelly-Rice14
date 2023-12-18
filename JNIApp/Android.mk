TOP_LOCAL_PATH:= $(call my-dir)

# Build activity

LOCAL_PATH:= $(TOP_LOCAL_PATH)
include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := $(call all-subdir-java-files)

LOCAL_PACKAGE_NAME := JNIApp

LOCAL_JNI_SHARED_LIBRARIES := libmyjnilib

LOCAL_PROGUARD_ENABLED := disabled

LOCAL_SDK_VERSION := current

LOCAL_DEX_PREOPT := false

LOCAL_PRODUCT_MODULE := true

include $(BUILD_PACKAGE)

# ============================================================

# Also build all of the sub-targets under this one: the shared library.
include $(call all-makefiles-under,$(LOCAL_PATH))
