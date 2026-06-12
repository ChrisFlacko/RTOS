.syntax unified
.cpu cortex-m4
.thumb

.global Reset_Handler
.global _stack_top

/* Stack location */
_stack_top = 0x20000000 + 64 * 1024

.section .text
.thumb_func
Reset_Handler:
    /* Initialize stack pointer */
    ldr sp, =_stack_top
    
    /* Call main */
    bl main
    
    /* Hang */
    b .

.size Reset_Handler, .-Reset_Handler
