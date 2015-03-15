An Engine Control Unit/Module that runs on the bare-metal Raspberry Pi.

### Getting Started

1. You will need an ARM compiler. [Download the latest toolchain](https://launchpad.net/gcc-arm-embedded/+download) from the GCC ARM Embedded Project. Extract the archive and add it's `/bin` folder to your `PATH`.
    * `mkdir ~/gcc-arm && cd ~/gcc-arm`
    * `wget gcc-arm-none-eabi-4_9-2014q4-20141203-ARCH.tar.bz2` *(Substitute ARCH for your platform)*
    * `tar -jxf gcc-arm-none-eabi-4_9-2014q4-20141203-ARCH.tar.bz2` *(Substitute ARCH for your platform)*
2. Fetch the latest code from GitHub.
    * `mkdir ~/ecu && cd ~/ecu`
    * `git clone https://github.com/MichaelBuhler/ecu.git`
3. Compile the code:
    * `cd ~/ecu && ./compile`
4. Copy the generated `kernel.img` file onto the (micro)SD card.
    * If you have an existing RPi Linux installation you can test this out by replaceing it's `/boot/kernel.img` with your own. The `/boot` path is probably it's own partition on the SD card.
    * If you want to run the minimum bare-metal installation, reformat your SD card with one FAT32 partition and copy `kernel.img` to it. You will also need two RPi firmware binaries (`bootcode.bin` and `start.elf`); you can [pull the latest](https://github.com/raspberrypi/firmware/tree/master/boot) from GitHub. Place all files at the root of the partition.
5. Plug in the SD card and boot up your Raspberry Pi.
6. [Automagically attach the Raspberry Pi to your car's engine.]
7. Let me know if it works or blows up.
