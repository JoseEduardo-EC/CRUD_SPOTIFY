#include <stdio.h>
#include "structs.h"

extern int listar_faixas();
extern int playlist_selecionada;

/*
========================================================
       NAME: excluir_faixa
 PARAMETROS: void
    RETORNO: void
DESCRIPTION: Função que exclui uma faixa de alguma playlist.
========================================================
*/

void excluir_faixa(){

    //Lista as faixas da playlist selecionada
    if(listar_faixas()) return;

    int escolha;

    do {
        printf("Qual faixa deseja excluir? ");
        scanf("%d", &escolha);

        //Verifica se a faixa escolhida existe
        if(escolha <= 0 || escolha > biblioteca[playlist_selecionada].num_faixas){
            printf("ESCOLHA INVALIDA.......\n");
        }

    } while (escolha <= 0 || escolha > biblioteca[playlist_selecionada].num_faixas);

    //Desloca todas as faixas seguintes uma posição para a esquerda
    for(int i = escolha - 1; i < biblioteca[playlist_selecionada].num_faixas - 1; i++){
        biblioteca[playlist_selecionada].faixas[i] = biblioteca[playlist_selecionada].faixas[i + 1];
    }

    //Atualiza a quantidade de faixas da playlist
    biblioteca[playlist_selecionada].num_faixas--;

    printf("Faixa excluida com sucesso!\n");
}