#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Inicializa a pilha
void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
    pilha->quantidade = 0;
}

// Verifica se a pilha está vazia
int pilhaVazia(Pilha *pilha) {
    return pilha->topo == NULL;
}

// Adiciona um pedido ao topo da pilha
int empilhar(Pilha *pilha, Pedido pedido) {

    NoPilha *novo = malloc(sizeof(NoPilha));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 0;
    }

    novo->pedido = pedido;
    novo->proximo = pilha->topo;

    pilha->topo = novo;
    pilha->quantidade++;

    return 1;
}

// Remove o pedido que está no topo
int desempilhar(Pilha *pilha, Pedido *pedido) {

    if (pilhaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return 0;
    }

    NoPilha *auxiliar = pilha->topo;

    *pedido = auxiliar->pedido;

    pilha->topo = auxiliar->proximo;

    free(auxiliar);

    pilha->quantidade--;

    return 1;
}

// Mostra os pedidos preparados, do mais recente ao mais antigo
void mostrarPilha(Pilha *pilha) {

    if (pilhaVazia(pilha)) {
        printf("Historico de pedidos vazio!\n");
        return;
    }

    NoPilha *atual = pilha->topo;

    printf("\n--- HISTORICO DE PEDIDOS PREPARADOS ---\n");

    while (atual != NULL) {

        printf("Pedido: %d\n", atual->pedido.id);
        printf("Cliente: %s\n", atual->pedido.cliente);
        printf("Produto: %s\n", atual->pedido.produto);

        printf("-------------------------\n");

        atual = atual->proximo;
    }
}

// Libera a memoria utilizada pela pilha
void liberarPilha(Pilha *pilha) {

    NoPilha *atual = pilha->topo;

    while (atual != NULL) {

        NoPilha *auxiliar = atual;
        atual = atual->proximo;

        free(auxiliar);
    }

    pilha->topo = NULL;
    pilha->quantidade = 0;
}