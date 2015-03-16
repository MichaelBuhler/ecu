#!/bin/sh
dir=$(pwd)
base=$(dirname $0)
cd $base/src
arm-none-eabi-gcc -O2 -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -nostartfiles -g ecu.c -o kernel.elf
mv kernel.elf ../bin/
cd ../bin/
arm-none-eabi-objcopy kernel.elf -O binary kernel.img
cd $dir
