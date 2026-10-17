extern listar_faixas
extern printf

section .data
    header db "----------------------------------------", 0x0A
           db "          LISTANDO FAIXAS                ", 0x0A
           db "----------------------------------------", 0x0A, 0x00

section .text
    global listar_faixas_asm

listar_faixas_asm:
    push ebp
    mov  ebp, esp

    push header
    call printf
    add  esp, 4

    call listar_faixas

    mov esp, ebp
    pop ebp
    ret