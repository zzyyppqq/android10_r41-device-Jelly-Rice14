# BinderCppDemo
Binder C++ 示例程序

### 传输可执行文件到模拟器：

```bash

#有符号（可用于debug）
adb push out/target/product/Rice14/symbols/system/bin/CppBinderServer /data/local/tmp
adb push out/target/product/Rice14/symbols/system/bin/CppBinderClient /data/local/tmp

# 无符号
adb push out/target/product/Rice14/system/bin/CppBinderServer /data/local/tmp
adb push out/target/product/Rice14/system/bin/CppBinderClient /data/local/tmp

```

### 接下来 `adb shell` 进入模拟器 `shell` 环境：

```bash
adb shell
cd /data/local/tmp
./CppBinderServer
# 从新开一个终端进入 adb shell
cd /data/local/tmp
./CppBinderClient