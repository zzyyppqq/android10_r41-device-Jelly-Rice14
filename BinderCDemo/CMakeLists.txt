cmake_minimum_required(VERSION 3.25)
project(BinderCDemo C)

set(CMAKE_C_STANDARD 99)


include_directories(
        ../../../../frameworks/native/cmds/servicemanager
        ../../../../system/core/liblog/include #<log/log.h>
        ../../../../bionic/libc/kernel/uapi #<linux/android/binder.h>
        ../../../../bionic/libc/include #<sys/ioctl.h>
)

add_executable(binder_client binder_client.c binder.c)

add_executable(binder_server binder_server.c binder.c)

