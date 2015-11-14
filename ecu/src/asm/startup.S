.section ".text.startup"

.global _start
_start:
    ldr pc, _reset_vector
    ldr pc, _undefined_instruction_vector
    ldr pc, _software_interrupt_vector
    ldr pc, _prefetch_abort_vector
    ldr pc, _data_abort_vector
    ldr pc, _unused_vector
    ldr pc, _interrupt_vector
    ldr pc, _fast_interrupt_vector

_reset_vector:                 .word _reset
_undefined_instruction_vector: .word _reset
_software_interrupt_vector:    .word _reset
_prefetch_abort_vector:        .word _reset
_data_abort_vector:            .word _reset
_unused_vector:                .word _reset
_interrupt_vector:             .word interrupt_handler
_fast_interrupt_vector:        .word _reset

_reset:
    cpsid   i
    mov     sp, #0x1000000
    mov     r0, #0x8000
    mov     r1, #0x0000
    ldmia   r0!,{r2, r3, r4, r5, r6, r7, r8, r9}
    stmia   r1!,{r2, r3, r4, r5, r6, r7, r8, r9}
    ldmia   r0!,{r2, r3, r4, r5, r6, r7, r8, r9}
    stmia   r1!,{r2, r3, r4, r5, r6, r7, r8, r9}
    b _cstartup

.global _sei
_sei:
    cpsie i
    mov pc, lr

.global _cli 
_cli:
    cpsid i
    mov pc, lr

_irq:
    push {r0,r1,r2,r3,lr}
    
    mov r0, #24
    mov r1, #0
    bl gpio_write
    /*
    mov  r0, #0x0028
    movt r0, #0x3F20
    mov  r1, #0x0000
    movt r1, #0x0100
    str r1, [r0]
    */
    mov  r0, #0x0040
    movt r0, #0x3F20
    mov  r1, #0x0000
    movt r1, #0x0400
    str r1, [r0]
    
    pop {r0,r1,r2,r3,lr}
    subs pc, lr, #4
