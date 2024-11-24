section .data
    float255 dd 255.0    ; Constant for normalizing pixel values (255.0)

section .text
    bits 64
    default rel
    global imgCvtGrayIntoFloat

imgCvtGrayIntoFloat:
    mov r10, rcx      
    imul r10, rdx       ; high * width = total pixels

    movss xmm1, [float255]
    xor r11, r11 ; initialize loop

    L1:
        cmp r11, r10      
        je done             
        movzx rax, byte [r8 + r11]
        cvtsi2ss xmm0, rax 
        divss xmm0, xmm1    
        movss [r9 + r11 * 4], xmm0 
        inc r11             
        jmp L1

    done:
        ret             
