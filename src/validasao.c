#include "validasao.h"

/*
========================================================
       NAME: tem_numero
 PARAMETROS: nome que deseja verificar
    RETORNO: 0 caso não tenha número
             1 caso tenha números
DESCRIPTION: Função que verifica se a string tem número.
========================================================
*/


int tem_numero(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            return 1;
        }
    }
    return 0;
}

/*
========================================================
       NAME: tem_numero
 PARAMETROS: nome que deseja verificar, nomes já existente do banco de dados
    RETORNO: 0 caso não tenha repetido
             1 caso tenha repetido
DESCRIPTION: Função que verifica se a string é igual a uma já existente do banco de dados.
             Verifica as strings já existente e e converte ambas para minúscullas para fazer a comparação
========================================================
*/

int nome_duplicado(char *novo, char *existente) {
    for (int i = 0; novo[i] != '\0' || existente[i] != '\0'; i++) {
        char c1 = novo[i];
        char c2 = existente[i];

        // converte pra minúsculo se for letra maiúscula
        if (c1 >= 'A' && c1 <= 'Z') c1 = c1 + 32;
        if (c2 >= 'A' && c2 <= 'Z') c2 = c2 + 32;

        //Se for diferente, para
        if (c1 != c2) return 0;
    }
    //Saõ iguais
    return 1;
}