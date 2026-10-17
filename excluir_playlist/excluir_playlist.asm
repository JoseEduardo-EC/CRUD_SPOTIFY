extern excluir_playlist
extern printf

section .data
    header db "----------------------------------------", 0x0A
           db "         EXCLUINDO PLAYLIST              ", 0x0A
           db "----------------------------------------", 0x0A, 0x00

section .text
    global excluir_playlist_asm

excluir_playlist_asm:
    push ebp
    mov  ebp, esp

    push header
    call printf
    add  esp, 4

    call excluir_playlist

    mov esp, ebp
    pop ebp
    ret