extern criar_playlist
extern printf

section .data
    header db "----------------------------------------", 0x0A
           db "         CRIANDO PLAYLIST               ", 0x0A
           db "----------------------------------------", 0x0A, 0x00

section .text
    global criar_playlist_asm

criar_playlist_asm:
    push ebp
    mov  ebp, esp

    push header
    call printf
    add  esp, 4

    call criar_playlist

    mov esp, ebp
    pop ebp
    ret
