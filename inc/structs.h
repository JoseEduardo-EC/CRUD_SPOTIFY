#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_PLATLIST    10
#define MAX_FAIXAS      10
#define MAX_CARACTERES  50

typedef struct {
    char titulo[MAX_CARACTERES];       //titulo da faixa
    char autores[MAX_CARACTERES];     //string com o nome dos autores
    int tempo_segundos;              //variavel com o tempo das musicas de cada faixa
}Faixa;


typedef struct {
    char nome[MAX_CARACTERES];       //string com o nome da playlist
    char criador[MAX_CARACTERES];   //string com o nome do criador da plyalist
    Faixa faixas[MAX_FAIXAS];      //array com as faixas
    int num_faixas;               //flag para verificar a quantidade de faixas  

}Playlist;

extern int playlist_selecionada;                   
extern Playlist biblioteca[MAX_PLATLIST];  //array com o banco de dados das playlists
extern int num_playlist;                  //flag para verificar a quantidade de playlists

#endif