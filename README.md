An Engine Control Unit/Module that runs on the bare-metal Raspberry Pi.

### Getting Started

1. To build from source, you will need an ARM compiler.
    * If you are compiling on a Raspberry Pi, the native compiler should work.
    * If you are compiling on another machine, you will need a cross compiler. You can [download the latest toolchain](https://launchpad.net/gcc-arm-embedded/+download) from the GCC ARM Embedded Project. Extract the archive to a location of your choosing and add it's `bin` folder to your `PATH`.
2. Fetch the latest code from GitHub.
    * Make a directory to clone to, e.g. `mkdir ~/ecu && cd ~/ecu`
    * Then `git clone https://github.com/MichaelBuhler/ecu.git`
3. Compile the code:
    * `cd ~/ecu`
    * `make`
4. Copy the generated `kernel.img` (or `kernel7.img`) file from the `/bin` folder onto the (micro)SD card.
    * If you have an existing RPi Linux installation you can test this out by replaceing it's `/boot/kernel.img` with your own. The `/boot` path is probably it's own partition on the SD card. (If your card has NOOBS, this should the partition numbered 5.)
    * If you want to run the minimum bare-metal installation, reformat your SD card with one FAT32 partition and copy `kernel.img` to it. You will also need two RPi firmware binaries (`bootcode.bin` and `start.elf`); you can [pull the latest](https://github.com/raspberrypi/firmware/tree/master/boot) from GitHub. Place all files at the root of the partition.
5. Plug in the SD card and boot up your Raspberry Pi.
6. [Attach the Raspberry Pi to your car's engine.]
7. Let me know if it works or if it blows up.
