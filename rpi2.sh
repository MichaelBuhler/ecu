#!/bin/sh
dir=$(pwd)
base=$(dirname $0)
cd $base/src
arm-none-eabi-gcc -O2 -DRPI2 -mfpu=neon-vfpv4 -mfloat-abi=hard -mcpu=cortex-a7 -nostartfiles -g ecu.c -o kernel7.elf
mv kernel7.elf ../bin/
cd ../bin/
arm-none-eabi-objcopy kernel7.elf -O binary kernel7.img
cd $dir
