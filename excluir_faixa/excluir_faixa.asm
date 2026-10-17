extern excluir_faixa
extern printf

section .data
    header db "----------------------------------------", 0x0A
           db "          EXCLUINDO FAIXA                ", 0x0A
           db "----------------------------------------", 0x0A, 0x00

section .text
    global excluir_faixa_asm

excluir_faixa_asm:
    push ebp
    mov  ebp, esp

    push header
    call printf
    add  esp, 4

    call excluir_faixa

    mov esp, ebp
    pop ebp
    ret