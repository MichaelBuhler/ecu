all: kernel kernel7

kernel: linker
	arm-none-eabi-objcopy -O binary bin/kernel.elf bin/kernel.bin

kernel7: linker7
	arm-none-eabi-objcopy -O binary bin/kernel7.elf bin/kernel7.bin

linker: assemble compile
	arm-none-eabi-ld -o bin/kernel.elf --script linker_script out/bootstrap.o out/ecu.o out/systimer.o out/gpio.o

linker7: assemble compile7
	arm-none-eabi-ld -o bin/kernel7.elf --script linker_script out/bootstrap.o out/ecu.o out/systimer.o out/gpio.o

compile:
	arm-none-eabi-gcc -o out/ecu.o -O2 -c src/ecu.c
	arm-none-eabi-gcc -o out/systimer.o -O2 -c src/systimer.c
	arm-none-eabi-gcc -o out/gpio.o -O2 -c src/gpio.c
	arm-none-eabi-gcc -o out/serial.o -O2 -c src/serial.c

compile7:
	arm-none-eabi-gcc -o out/ecu.o -O2 -DRPI2 -c src/ecu.c
	arm-none-eabi-gcc -o out/systimer.o -O2 -DRPI2 -c src/systimer.c
	arm-none-eabi-gcc -o out/gpio.o -O2 -DRPI2 -c src/gpio.c
	arm-none-eabi-gcc -o out/serial.o -O2 -DRPI2 -c src/serial.c

assemble:
	arm-none-eabi-as -o out/bootstrap.o src/bootstrap.s

clean:
	rm -frv out/*
