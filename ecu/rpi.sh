#/bin/sh
dir=$(pwd)
base=$(dirname $0)
cd $base
arm-none-eabi-as src/bootstrap.s -o out/bootstrap.o
arm-none-eabi-gcc -O2 -c src/notmain.c -o out/notmain.o
arm-none-eabi-ld -Ttext 0x00008000 out/bootstrap.o out/notmain.o -o bin/kernel.elf
arm-none-eabi-objcopy bin/kernel.elf -O binary bin/kernel.bin
cd $dir
