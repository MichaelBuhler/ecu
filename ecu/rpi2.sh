#/bin/sh
dir=$(pwd)
base=$(dirname $0)
cd $base
arm-none-eabi-as src/bootstrap.s -o out/bootstrap.o
arm-none-eabi-gcc -DRPI2 -O2 -c src/ecu.c -o out/ecu.o
arm-none-eabi-ld -T linker_script out/bootstrap.o out/ecu.o -o bin/kernel7.elf
arm-none-eabi-objcopy bin/kernel7.elf -O binary bin/kernel7.bin
cd $dir
