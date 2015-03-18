#!/bin/sh
dir=$(pwd)
base=$(dirname $0)
cd $base
arm-none-eabi-gcc -DRPI2 -g -O2 -mfpu=neon-vfpv4 -mfloat-abi=hard -mcpu=cortex-a7 -nostartfiles -Wl,-T,ld/armelf.x -o bin/kernel7.elf src/cstartup.c src/ecu.c asm/startup.S
arm-none-eabi-objcopy bin/kernel7.elf -O binary bin/kernel7.img
cd $dir
