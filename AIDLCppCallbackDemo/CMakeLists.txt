cmake_minimum_required(VERSION 3.25)
project(AIDLCppCallbackDemo)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        ../../../../frameworks/native/libs/binder/include
        ../../../../system/core/base/include
        ../../../../system/core/libutils/include
        ../../../../system/core/libcutils/include
        ../../../../system/core/liblog/include #<log/log.h>
        ../../../../bionic/libc/include #<sys/prctl.h>
        ./
)


add_executable(BinderCallbackClient HelloClient.cpp IHello.cpp ICallback.cpp)

add_executable(BinderCallbackServer HelloServer.cpp IHello.cpp ICallback.cpp)
