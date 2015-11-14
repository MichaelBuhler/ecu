.section ".text.startup"

.global _start
_start:
    ldr sp, =(0x0020000)
    b _cstartup
        