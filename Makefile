CC      = gcc
NASM    = nasm

CFLAGS    = -m32 -Wall -Iinc
NASMFLAGS = -f elf32

TARGET = app
OBJDIR = obj

OBJ = \
	$(OBJDIR)/main.o \
	$(OBJDIR)/validasao.o \
	$(OBJDIR)/criar_playlist.o \
	$(OBJDIR)/criar_playlist_asm.o \
	$(OBJDIR)/listar_playlist.o \
	$(OBJDIR)/listar_playlist_asm.o \
	$(OBJDIR)/excluir_playlist.o \
	$(OBJDIR)/excluir_playlist_asm.o \
	$(OBJDIR)/adicionar_faixa.o \
	$(OBJDIR)/adicionar_faixa_asm.o \
	$(OBJDIR)/listar_faixas.o \
	$(OBJDIR)/listar_faixas_asm.o \
	$(OBJDIR)/excluir_faixa.o \
	$(OBJDIR)/excluir_faixa_asm.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

obj:
	mkdir -p obj

$(OBJDIR)/main.o: src/main.asm | obj
	$(NASM) $(NASMFLAGS) $< -o $@

$(OBJDIR)/validasao.o: src/validasao.c inc/validasao.h | obj
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/criar_playlist.o: criar_playlist/criar_playlist.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/criar_playlist_asm.o: criar_playlist/criar_playlist.asm | obj
	$(NASM) $(NASMFLAGS) $< -o $@

$(OBJDIR)/listar_playlist.o: listar_playlist/listar_playlist.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/listar_playlist_asm.o: listar_playlist/listar_playlist.asm | obj
	$(NASM) $(NASMFLAGS) $< -o $@

$(OBJDIR)/excluir_playlist.o: excluir_playlist/excluir_playlist.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/excluir_playlist_asm.o: excluir_playlist/excluir_playlist.asm | obj
	$(NASM) $(NASMFLAGS) $< -o $@

$(OBJDIR)/adicionar_faixa.o: adicionar_faixa/adicionar_faixa.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/adicionar_faixa_asm.o: adicionar_faixa/adicionar_faixa.asm | obj
	$(NASM) $(NASMFLAGS) $< -o $@

$(OBJDIR)/listar_faixas.o: listar_faixas/listar_faixas.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/listar_faixas_asm.o: listar_faixas/listar_faixas.asm | obj
	$(NASM) $(NASMFLAGS) $< -o $@

$(OBJDIR)/excluir_faixa.o: excluir_faixa/excluir_faixa.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/excluir_faixa_asm.o: excluir_faixa/excluir_faixa.asm | obj
	$(NASM) $(NASMFLAGS) $< -o $@

clean:
	rm -rf obj app

.PHONY: all clean