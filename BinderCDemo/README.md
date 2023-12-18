# BinderCDemo
Binder C 程序示例


传输可执行文件到模拟器：
```
adb push out/target/product/Rice14/symbols/vendor/bin/binderserver /data/local/tmp

adb push out/target/product/Rice14/symbols/vendor/bin/binderclient /data/local/tmp
```

接下来 adb shell 进入模拟器 shell 环境：

```
adb shell
cd /data/local/tmp
./binderserver
```

从新开一个终端进入 adb shell

```
cd /data/local/tmp
./binderclient
```

最后通过 logcat 查看执行结果：

```
logcat | grep "BinderServer"

11-22 17:08:39.133  6594  6594 W BinderServer: say hello : 1
```