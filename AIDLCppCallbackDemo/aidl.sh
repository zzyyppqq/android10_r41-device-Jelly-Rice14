#!/bin/bash

aidl-cpp com/zyp/ICallback.aidl ./ ./ICallback.cpp
aidl-cpp -I./com/zyp com/zyp/IHello.aidl ./ ./IHello.cpp