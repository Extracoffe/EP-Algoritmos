#ifndef FILA_H
#define FILA_H

#include "pedidos.h"

typedef struct No {
    Pedido pedido;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int quantidade;
} Fila;

void inicializarFila(Fila *fila);
int filaVazia(Fila *fila);
void adicionarPedido(Fila *fila, Pedido pedido);
int removerPedido(Fila *fila, Pedido *pedido);
void mostrarFila(Fila *fila);
void liberarFila(Fila *fila);
void inserirInicio(Fila *fila, Pedido pedido);


#endif