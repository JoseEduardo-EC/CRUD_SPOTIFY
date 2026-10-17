extern adicionar_faixa
extern printf

section .data
    header db "----------------------------------------", 0x0A
           db "         ADICIONANDO FAIXA               ", 0x0A
           db "----------------------------------------", 0x0A, 0x00

section .text
    global adicionar_faixa_asm

adicionar_faixa_asm:
    push ebp
    mov  ebp, esp

    push header
    call printf
    add  esp, 4

    call adicionar_faixa

    mov esp, ebp
    pop ebp
    ret