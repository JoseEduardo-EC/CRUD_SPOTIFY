# Bodesfy

1. [Sobre](#sobre)
2. [Requisitos](#requisitos)
3. [Estrutura do repositório](#estrutura-do-repositório)
4. [Compilação e execução](#compilação-e-execução)
5. [Team](#team)

## Sobre

Este projeto implementa um sistema de cadastro de músicas e playlists inspirado no Spotify, desenvolvido com a linguagem C e Assembly x86 32 bits (NASM).

O desenvolvimento tem como objetivo aplicar conceitos fundamentais de programação de baixo nível, explorando a integração entre C e Assembly, manipulação de structs e organização modular de código.

O projeto possui foco nos seguintes conceitos:

- Programação em linguagem C;
- Programação em Assembly x86 32 bits com NASM;
- Integração entre C e Assembly seguindo a convenção de chamada cdecl;
- Manipulação de structs e arrays estáticos;
- Modularização do código em pares de arquivos `.c` e `.asm` por funcionalidade;
- Validação de entrada de dados;
- Utilização do Makefile para automatizar a compilação.

### Funcionalidades

1. **Criar playlist:** cadastra uma nova playlist com nome e criador, com validação de duplicatas e caracteres inválidos.
2. **Listar playlists:** exibe todas as playlists cadastradas com nome, criador e quantidade de faixas.
3. **Excluir playlist:** remove uma playlist existente do sistema.
4. **Adicionar faixa:** adiciona uma faixa a uma playlist, informando título, autores e duração.
5. **Listar faixas:** exibe todas as faixas de uma playlist selecionada com título, autores e duração formatada.
6. **Excluir faixa:** remove uma faixa de uma playlist existente.

## Requisitos

1. NASM (Netwide Assembler) para compilar os arquivos `.asm`;
2. GCC com suporte a 32 bits (`-m32`) para compilar os arquivos `.c`;
3. GNU Make para executar o Makefile;
4. Terminal para entrada de dados e visualização dos resultados.

## Estrutura do repositório

### Diretórios e arquivos principais

1. `criar_playlist/`: par `.c` e `.asm` responsável por criar uma nova playlist.
2. `listar_playlist/`: par `.c` e `.asm` responsável por listar as playlists cadastradas.
3. `excluir_playlist/`: par `.c` e `.asm` responsável por excluir uma playlist.
4. `adicionar_faixa/`: par `.c` e `.asm` responsável por adicionar uma faixa a uma playlist.
5. `listar_faixas/`: par `.c` e `.asm` responsável por listar as faixas de uma playlist.
6. `excluir_faixa/`: par `.c` e `.asm` responsável por excluir uma faixa de uma playlist.
7. `structs.h`: declaração das structs, defines e variáveis globais compartilhadas.
8. `validacoes.c` / `validacoes.h`: funções de validação de entrada (números e duplicatas).
9. `main.asm`: ponto de entrada do programa, contém o loop do menu e o dispatcher de opções em Assembly.
10. `Makefile`: contém as regras para compilar e linkar todos os módulos.

### Exemplo de organização

```text
Bodesfy/
├── criar_playlist/
│   ├── criar_playlist.c
│   └── criar_playlist.asm
├── listar_playlist/
│   ├── listar_playlist.c
│   └── listar_playlist.asm
├── excluir_playlist/
│   ├── excluir_playlist.c
│   └── excluir_playlist.asm
├── adicionar_faixa/
│   ├── adicionar_faixa.c
│   └── adicionar_faixa.asm
├── listar_faixas/
│   ├── listar_faixas.c
│   └── listar_faixas.asm
├── excluir_faixa/
│   ├── excluir_faixa.c
│   └── excluir_faixa.asm
├── structs.h
├── validacoes.c
├── validacoes.h
├── main.asm
├── Makefile
└── README.md
```

**Descrição dos arquivos:**

- `main.asm`: ponto de entrada do programa; exibe o menu, lê a opção do usuário e chama o wrapper Assembly correspondente.
- `criar_playlist.c`: lógica de cadastro de playlist com validação de duplicatas e caracteres numéricos.
- `criar_playlist.asm`: wrapper Assembly que exibe o cabeçalho da operação e chama a função C.
- `listar_playlist.c`: lógica de listagem das playlists cadastradas; retorna 1 se não houver playlists.
- `listar_playlist.asm`: wrapper Assembly que exibe o cabeçalho e chama a função C.
- `excluir_playlist.c`: lógica de remoção de playlist por índice com shift do array.
- `excluir_playlist.asm`: wrapper Assembly que exibe o cabeçalho e chama a função C.
- `adicionar_faixa.c`: lógica de adição de faixa com validação de entrada e conversão de segundos para minutos:segundos.
- `adicionar_faixa.asm`: wrapper Assembly que exibe o cabeçalho e chama a função C.
- `listar_faixas.c`: lógica de listagem de faixas de uma playlist; salva o índice selecionado na flag global.
- `listar_faixas.asm`: wrapper Assembly que exibe o cabeçalho e chama a função C.
- `excluir_faixa.c`: lógica de remoção de faixa por índice com shift do array interno da playlist.
- `excluir_faixa.asm`: wrapper Assembly que exibe o cabeçalho e chama a função C.
- `structs.h`: define as structs `Faixa` e `Playlist`, os defines de tamanho máximo e os `extern` das variáveis globais.
- `validacoes.c`: implementa `tem_numero()` e `nome_duplicado()` para validação de entrada.
- `validacoes.h`: declara os protótipos das funções de validação.

## Compilação e execução

A compilação é automatizada por meio de um `Makefile` que compila todos os arquivos `.c` e `.asm`, linka os objetos gerados e produz o executável `app` na raiz do projeto.

### 1. Compilar o projeto

Na raiz do repositório, execute:

```bash
make
```

### 2. Executar o programa

```bash
./app
```

### 3. Limpar os arquivos gerados

Para remover os arquivos objeto e o executável, execute:

```bash
make clean
```

## Team

- **Desenvolvedor:** José Eduardo