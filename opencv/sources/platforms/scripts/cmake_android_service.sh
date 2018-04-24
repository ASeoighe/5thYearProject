#!/bin/sh
cd `dirname $0`/..

mkdir -p build_android_service
cd build_android_service

<<<<<<< HEAD
cmake -DCMAKE_TOOLCHAIN_FILE=../android/android.toolchain.cmake -DANDROID_TOOLCHAIN_NAME="arm-linux-androideabi-4.4.3" -DANDROID_STL=stlport_static -DANDROID_STL_FORCE_FEATURES=OFF -DBUILD_ANDROID_SERVICE=ON -DANDROID_SOURCE_TREE=~/Projects/AndroidSource/ServiceStub/ $@ ../..
=======
cmake -DCMAKE_TOOLCHAIN_FILE=../android/android.toolchain.cmake -DANDROID_TOOLCHAIN_NAME="arm-linux-androideabi-4.6" -DANDROID_STL=stlport_static -DANDROID_STL_FORCE_FEATURES=OFF -DBUILD_ANDROID_SERVICE=ON -DANDROID_SOURCE_TREE=~/Projects/AndroidSource/ServiceStub/ $@ ../..
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
