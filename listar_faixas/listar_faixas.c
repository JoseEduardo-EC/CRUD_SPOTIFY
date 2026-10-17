#include <stdio.h>
#include "structs.h"

extern unsigned int listar_playlist();

/*
========================================================
       NAME: listar_faixas
 PARAMETROS: void
    RETORNO: 0
DESCRIPTION: Função que lista as faixas de uma playlist selecionada.
========================================================
*/

int listar_faixas(){

    //Lista todas as playlists cadastradas
    if(listar_playlist()) return 1;

    int option;

    do {
        printf("Escolha: ");
        scanf("%d", &option);

        //Verifica se a playlist escolhida existe
        if(option > num_playlist || option <= 0){
            printf("Escolha invalida, tente novamente.\n");
        }

    } while (option > num_playlist || option <= 0);

    //Armazena o índice da playlist selecionada
    playlist_selecionada = option - 1;

    printf("\n========================================\n");
    printf("             SUAS FAIXAS                \n");
    printf("========================================\n");

    //Percorre todas as faixas da playlist selecionada
    for (int i = 0; i < biblioteca[playlist_selecionada].num_faixas; i++) {

        printf("\n  [%d] %s\n", i + 1, biblioteca[playlist_selecionada].faixas[i].titulo);
        printf("      Criadores: %s\n", biblioteca[playlist_selecionada].faixas[i].autores);

        //Converte o tempo da música de segundos para minutos e segundos
        int aux_minutos = biblioteca[playlist_selecionada].faixas[i].tempo_segundos / 60;
        int aux_segundos = biblioteca[playlist_selecionada].faixas[i].tempo_segundos % 60;

        printf("      %d:%02d\n", aux_minutos, aux_segundos);
        printf("  ----------------------------------------\n");
    }

    //Indica que a operação foi realizada com sucesso
    return 0;
}