#ifndef PILHA_H
#define PILHA_H

#include "pedidos.h"

typedef struct NoPilha {
    Pedido pedido;
    struct NoPilha *proximo;
} NoPilha;

typedef struct {
    NoPilha *topo;
    int quantidade;
} Pilha;

void inicializarPilha(Pilha *pilha);
int pilhaVazia(Pilha *pilha);
int empilhar(Pilha *pilha, Pedido pedido);
int desempilhar(Pilha *pilha, Pedido *pedido);
void mostrarPilha(Pilha *pilha);
void liberarPilha(Pilha *pilha);

#endif