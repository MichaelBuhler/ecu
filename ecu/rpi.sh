#/bin/sh
dir=$(pwd)
base=$(dirname $0)
cd $base
arm-none-eabi-as src/bootstrap.s -o out/bootstrap.o
arm-none-eabi-gcc -O2 -c src/ecu.c -o out/ecu.o
arm-none-eabi-ld -T linker_script out/bootstrap.o out/ecu.o -o bin/kernel.elf
arm-none-eabi-objcopy bin/kernel.elf -O binary bin/kernel.bin
cd $dir
