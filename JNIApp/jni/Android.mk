LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

# This is the target being built.
LOCAL_MODULE:= libmyjnilib


# All of the source files that we will compile.
LOCAL_SRC_FILES:= \
    native.cpp

# All of the shared libraries we link against.
LOCAL_LDLIBS := -llog

# No static libraries.
LOCAL_STATIC_LIBRARIES :=

#LOCAL_SHARED_LIBRARIES := libmymath
LOCAL_SHARED_LIBRARIES := libmymathprebuild

LOCAL_CFLAGS := -Wall -Werror

LOCAL_NDK_STL_VARIANT := none

#LOCAL_SDK_VERSION := current

LOCAL_PRODUCT_MODULE := true

include $(BUILD_SHARED_LIBRARY)

