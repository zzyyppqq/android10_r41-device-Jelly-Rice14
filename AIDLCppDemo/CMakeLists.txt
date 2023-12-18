cmake_minimum_required(VERSION 3.25)
project(AIDLCppDemo)

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


add_executable(IHelloClient HelloClient.cpp IHello.cpp)

add_executable(IHelloServer HelloServer.cpp IHello.cpp)

#add_executable(thread_specific_data_test test/thread_specific_data_test.cpp)
