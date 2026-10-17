#include <stdio.h>
#include "structs.h"

/*
========================================================
       NAME: listar_playlist
 PARAMETROS: void
    RETORNO: 0
DESCRIPTION: Função que lista as playlist do banco de dados.
========================================================
*/

unsigned int listar_playlist(){

    //Verifica se existe pelo menos uma playlist cadastrada
    if(num_playlist <= 0){
        printf("ERROR\nSEM PLAYLIST ADCICIONADAS......\n\n");
        return 1;
    }

    printf("\n========================================\n");
    printf("           SUAS PLAYLISTS               \n");
    printf("========================================\n");

    //Percorre todas as playlists cadastradas no banco de dados
    for (int i = 0; i < num_playlist; i++) {
        printf("\n  [%d] %s\n", i + 1, biblioteca[i].nome);
        printf("      Criador: %s\n", biblioteca[i].criador);
        printf("      Faixas:  %d\n", biblioteca[i].num_faixas);
        printf("  ----------------------------------------\n");
    }

    //Indica que a listagem foi realizada com sucesso
    return 0;
}