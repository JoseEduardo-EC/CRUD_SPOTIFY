#include <stdio.h>
#include "structs.h"
#include "validasao.h"

extern unsigned int listar_playlist();


/*
========================================================
       NAME: adicionar_faixa
 PARAMETROS: void
    RETORNO: void
DESCRIPTION: Função que adiciona uma nova faixa a uma playlist selecionada.
             Caso não tenha nenhuma playlist adicionada, retornar ERROR.
========================================================
*/

void adicionar_faixa(){
    //Lista as playlist do banco de dados
    if(listar_playlist()) return;

    int option;

    do {
        printf("Escolha: ");
        scanf("%d", &option);

        //Escolheu um número que não tem uma playlist correspondente
        if(option > num_playlist || option <= 0){
            printf("Escolha invalida, tente novamente.\n");
        }
        //A playlist escolhida já está cheia
        else if(biblioteca[option - 1].num_faixas >= MAX_FAIXAS){
            printf("A PLAYLIST ESTA CHEIA........\n");
        }
    } while (option > num_playlist || option <= 0 || biblioteca[option - 1].num_faixas >= MAX_FAIXAS);

    Faixa musica;

    do
    {
        printf("Digite o nome da faixa: ");
        scanf(" %49[^\n]", musica.titulo);

        //Verifica se tem número no nome
        if(tem_numero(musica.titulo)){      
            printf("Nome invalido! Nao use numeros.\n");
            continue;
        }

        //Verifica se o nome não é repetido
        int duplicado = 0;
        for(int i = 0; i < biblioteca[option - 1].num_faixas; i++){
            if(nome_duplicado(musica.titulo, biblioteca[option - 1].faixas[i].titulo)){
                duplicado = 1;
                printf("Ja existe uma faixa com esse nome!\n");
                break;
            }
        }
        if(duplicado == 1) {
            continue;
        }

        else{
            break;
        }
    } while (1);
    
    do
    {
        printf("Digite os autores separados por virgula: ");
        scanf(" %49[^\n]", musica.autores);

        //Verifica se tem número no nome
        if(tem_numero(musica.autores)){    
            printf("Nome invalido! Nao use numeros.\n");
            continue;
        }
        break;
    } while (1);
    
    printf("Digite o tempo da musica em segundos: ");
    scanf("%d", &musica.tempo_segundos);

    int aux = biblioteca[option - 1].num_faixas;
    biblioteca[option - 1].faixas[aux] = musica;
    biblioteca[option - 1].num_faixas++;

    printf("Faixa adicionada com sucesso!\n");
}