#!/bin/sh
dir=$(pwd)
base=$(dirname $0)
cd $base
arm-none-eabi-gcc -g -O2 -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -nostartfiles -Wl,-T,ld/armelf.x -o bin/kernel.elf src/ecu.c src/cstartup.c asm/startup.S
arm-none-eabi-objcopy bin/kernel.elf -O binary bin/kernel.img
cd $dir
