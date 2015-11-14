.global _start
_start:
    mov sp, #0x8000
    bl notmain
    hang: b hang

.global noop
noop:
    bx lr

.global get32
get32:
    ldr r0, [r0]
    bx lr

.global put32
put32:
    str r1, [r0]
    bx lr
