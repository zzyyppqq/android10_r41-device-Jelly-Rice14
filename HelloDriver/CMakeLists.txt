cmake_minimum_required(VERSION 3.25)
project(HelloDriver C)

set(CMAKE_C_STANDARD 99)


#set(Kernel_goldfish /Volumes/APFS_ZYP/Android/AOSP/kernel/goldfish)

include_directories(
    ../../../../../kernel/goldfish/tools/include
    ../../../../../kernel/goldfish/tools/testing/selftests/rcutorture/formal/srcu-cbmc/include
    ../../../../../kernel/goldfish/tools/perf/util/include
    ../../../../../kernel/goldfish/drivers/staging/lustre/include
    ../../../../../kernel/goldfish/drivers/staging/media/atomisp/include
    ../../../../../kernel/goldfish/include
    ../../../../../kernel/goldfish/include/uapi
)

add_library(hello_drv hello_drv.c hello_drv.mod.c)


add_executable(hello_driver_test hello_drv_test.c)

