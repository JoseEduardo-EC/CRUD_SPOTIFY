#include <stdio.h>
#include "structs.h"
#include "validasao.h"

Playlist biblioteca[MAX_PLATLIST];
int num_playlist = 0;
int playlist_selecionada = 0;


/*
========================================================
       NAME: criar_playlist
 PARAMETROS: void
    RETORNO: void
DESCRIPTION: Função que cria uma nova playlist e adiciona no banco de dados biblioteca.
             Caso já tenha alcansado o número máximo de playlist, retornar ERROR.
========================================================
*/

void criar_playlist(){

    //Verifica se já foi atingido o número máximo de playlists
    if(num_playlist >= 10){
        printf("NUMERO MAXIMO DE PLAYLSIT ALCANSADO.......\n");
        return;
    }

    Playlist nova;

    do
    {
        printf("Digite o nome da playlist\n");
        scanf(" %49[^\n]", nova.nome);

        //Verifica se tem número no nome
        if(tem_numero(nova.nome)){
            printf("Nome invalido! Nao use numeros.\n ");
            continue;
        }

        //Verifica se já existe uma playlist com o mesmo nome
        int duplicado = 0;
        for(int i = 0; i < num_playlist; i++){
            if(nome_duplicado(nova.nome, biblioteca[i].nome)){
                printf("Ja existe uma playlist com esse nome!\n");
                duplicado = 1;
                break;
            }
        }

        //Nome duplicado, solicita um novo nome
        if(duplicado == 1) {
            continue;
        }

        //Nome válido
        else{
            break;
        }

    } while (1);

    printf("Adicionando nome.......\n");

    do
    {
        printf("Digite o nome do criador da playlist\n");
        scanf(" %49[^\n]", nova.criador);

        //Verifica se tem número no nome
        if(tem_numero(nova.criador)){
            printf("Nome invalido! Nao use numeros.\n ");
            continue;
        }

        //Nome válido
        else{
            break;
        }
    } while (1);
    
    printf("Adiconando autor........\n\n");

    //Inicializa a nova playlist sem nenhuma faixa
    nova.num_faixas = 0;

    //Adiciona a playlist ao banco de dados
    biblioteca[num_playlist] = nova;

    //Atualiza a quantidade de playlists cadastradas
    num_playlist++;

    printf("playlist criada com sucesso\n");
    printf("  ----------------------------------------\n");

}