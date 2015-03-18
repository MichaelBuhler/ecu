.section ".text.startup"

.global _start
_start:
    ldr sp, =(0x0020000)
    b _cstartup

.global _store
_store:
    str r1, [r0]
    mov pc, lr
        