extern printf
extern scanf
extern criar_playlist_asm
extern listar_playlist_asm
extern excluir_playlist_asm
extern adicionar_faixa_asm
extern listar_faixas_asm
extern excluir_faixa_asm

section .bss
    opcao resd 1

section .data
    menu db "===========BODESFY====================", 0x0A
         db "0 - Sair", 0x0A
         db "1 - Criar playlist", 0x0A
         db "2 - Listar playlists", 0x0A
         db "3 - Excluir playlist", 0x0A
         db "4 - Adicionar faixa", 0x0A
         db "5 - Listar faixas", 0x0A
         db "6 - Excluir faixa", 0x0A
         db "========================================", 0x0A, 0x00

    fmt          db "%d", 0x00
    msg_fim      db "ENCERRANDO............", 0x0A, 0x00
    msg_invalido db "Escolha invalida, tente novamente", 0x0A, 0x00

section .text
global main
main:
    ;Inicia o menu principal
    call loop_menu

    ;Retorna 0 para o sistema operacional
    xor eax, eax
    ret


;========================================================
;       NAME: loop_menu
; PARAMETROS: void
;    RETORNO: void
;DESCRIPTION: Exibe o menu principal, lê a opção escolhida
;             pelo usuário e direciona a execução para a
;             funcionalidade correspondente.
;========================================================

loop_menu:
    push ebp
    mov  ebp, esp

    ;Exibe o menu principal
    push menu
    call printf
    add  esp, 4

    ;Lê a opção escolhida pelo usuário
    push opcao
    push fmt
    call scanf
    add  esp, 8

    ;Carrega a opção digitada em EAX para comparação
    mov eax, [opcao]

    ;Seleciona a funcionalidade correspondente
    cmp eax, 0
    je  sair
    cmp eax, 1
    je  caso1
    cmp eax, 2
    je  caso2
    cmp eax, 3
    je  caso3
    cmp eax, 4
    je  caso4
    cmp eax, 5
    je  caso5
    cmp eax, 6
    je  caso6

    ;Opção inválida
    push msg_invalido
    call printf
    add  esp, 4
    jmp  loop_menu

caso1:
    ;Cria uma nova playlist
    call criar_playlist_asm
    jmp  loop_menu

caso2:
    ;Lista todas as playlists
    call listar_playlist_asm
    jmp  loop_menu

caso3:
    ;Exclui uma playlist
    call excluir_playlist_asm
    jmp  loop_menu

caso4:
    ;Adiciona uma faixa a uma playlist
    call adicionar_faixa_asm
    jmp  loop_menu

caso5:
    ;Lista as faixas de uma playlist
    call listar_faixas_asm
    jmp  loop_menu

caso6:
    ;Exclui uma faixa de uma playlist
    call excluir_faixa_asm
    jmp  loop_menu

sair:
    ;Encerra a aplicação
    push msg_fim
    call printf
    add  esp, 4

    mov  esp, ebp
    pop  ebp
    ret