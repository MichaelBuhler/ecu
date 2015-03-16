#!/bin/sh
dir=$(pwd)
base=$(dirname $0)
cd $base/src
arm-none-eabi-gcc -O2 -mfpu=neon-vfpv4 -mfloat-abi=hard -mcpu=cortex-a7 -nostartfiles -g ecu.c -o kernel.elf
mv kernel.elf ../bin/
cd ../bin/
arm-none-eabi-objcopy kernel.elf -O binary kernel.img
cd $dir
