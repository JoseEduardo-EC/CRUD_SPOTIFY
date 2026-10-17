extern listar_playlist
extern printf

section .data
    header db "----------------------------------------", 0x0A
           db "         LISTANDO PLAYLISTS              ", 0x0A
           db "----------------------------------------", 0x0A, 0x00

section .text
    global listar_playlist_asm

listar_playlist_asm:
    push ebp
    mov  ebp, esp

    push header
    call printf
    add  esp, 4

    call listar_playlist

    mov esp, ebp
    pop ebp
    ret