#!/bin/sh
dir=$(pwd)
base=$(dirname $0)
cd $base
arm-none-eabi-gcc -DRPI2 -g -mfpu=neon-vfpv4 -mfloat-abi=hard -mcpu=cortex-a7 -nostartfiles -Wl,-T,src/ld/armelf.x -o bin/kernel7.elf src/asm/startup.S src/cstartup.c src/ecu.c
arm-none-eabi-objcopy bin/kernel7.elf -O binary bin/kernel7.img
cd $dir
