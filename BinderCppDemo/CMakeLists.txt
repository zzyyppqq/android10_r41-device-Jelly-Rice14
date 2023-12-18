cmake_minimum_required(VERSION 3.25)
project(BinderCppDemo)

set(CMAKE_CXX_STANDARD 11)

set(Kernel_goldfish /Volumes/APFS_ZYP/Android/AOSP/kernel/goldfish)

include_directories(
        ../../../../frameworks/native/libs/binder/include
        ../../../../system/core/libutils/include
        ../../../../system/core/libcutils/include
        ../../../../system/core/liblog/include #<log/log.h>
        ../../../../bionic/libc/include #<sys/prctl.h>
)


add_executable(BinderClient BinderClient.cpp BpHelloService.cpp)

add_executable(BinderServer BinderServer.cpp BnHelloService.cpp)

#add_executable(thread_specific_data_test test/thread_specific_data_test.cpp)
