all: kernel

kernel: link
	arm-none-eabi-objcopy -O binary bin/kernel.elf bin/kernel.bin
	
link: assemble compile
	mkdir -p bin
	arm-none-eabi-ld -o bin/kernel.elf --script linker_script out/bootstrap.o out/ecu.o out/systimer.o out/gpio.o out/serial.o out/char_buffer.o

compile:
	mkdir -p out
	arm-none-eabi-gcc -c -O2 -mcpu=cortex-a7 -o out/ecu.o src/ecu.c
	arm-none-eabi-gcc -c -O2 -mcpu=cortex-a7 -o out/systimer.o src/systimer.c
	arm-none-eabi-gcc -c -O2 -mcpu=cortex-a7 -o out/gpio.o src/gpio.c
	arm-none-eabi-gcc -c -O2 -mcpu=cortex-a7 -o out/serial.o src/serial.c
	arm-none-eabi-gcc -c -O2 -mcpu=cortex-a7 -o out/char_buffer.o src/char_buffer.c

assemble:
	mkdir -p out
	arm-none-eabi-as -o out/bootstrap.o src/bootstrap.s

clean:
	rm -frv bin
	rm -frv out
