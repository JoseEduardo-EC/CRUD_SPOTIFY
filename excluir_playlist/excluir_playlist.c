#include <stdio.h>
#include "structs.h"

extern unsigned int listar_playlist();

/*
========================================================
       NAME: excluir_playlist
 PARAMETROS: void
    RETORNO: void
DESCRIPTION: Função que exclui uma playlist.
========================================================
*/

void excluir_playlist(){

    //Lista todas as playlists cadastradas
    if(listar_playlist()) return;

    printf("Qual deseja excluir? \n");
    int escolha;

    do {
        printf("Escolha: ");
        scanf("%d", &escolha);

        //Verifica se a playlist escolhida existe
        if (escolha <= 0 || escolha > num_playlist) {
            printf("Escolha invalida, tente novamente.\n");
        }

    } while (escolha <= 0 || escolha > num_playlist);

    //Desloca todas as playlists seguintes uma posição para a esquerda
    for(int i = escolha - 1; i < num_playlist - 1; i++){
        biblioteca[i] = biblioteca[i + 1];
    }

    //Atualiza a quantidade de playlists cadastradas
    num_playlist--;

    printf("  ----------------------------------------\n");
}