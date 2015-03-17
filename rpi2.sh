#!/bin/sh
dir=$(pwd)
base=$(dirname $0)
cd $base
arm-none-eabi-gcc -O2 -DRPI2 -mfpu=neon-vfpv4 -mfloat-abi=hard -mcpu=cortex-a7 -nostartfiles -Wl,-T,linker/armelf.x -g src/ecu.c -o bin/kernel7.elf
arm-none-eabi-objcopy bin/kernel7.elf -O binary bin/kernel7.img
cd $dir
