#!/bin/bash
export ARCH=x86_64
export SUBARCH=x86_64
export CROSS_COMPILE=x86_64-linux-android-
export PATH=/media/psf/APFS_ZYP/Android/AOSP/android-10.0.0_r41/prebuilts/gcc/linux-x86/x86/x86_64-linux-android-4.9/bin:$PATH
make
