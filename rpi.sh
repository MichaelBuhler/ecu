#!/bin/sh
dir=$(pwd)
base=$(dirname $0)
cd $base
arm-none-eabi-gcc -O2 -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -nostartfiles -Wl,-T,linker/armelf.x -g src/ecu.c -o bin/kernel.elf
arm-none-eabi-objcopy bin/kernel.elf -O binary bin/kernel.img
cd $dir
