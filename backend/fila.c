#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Inicializa a fila
void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->quantidade = 0;
}

// Verifica se a fila está vazia
int filaVazia(Fila *fila) {
    return fila->inicio == NULL;
}

// Adiciona um pedido no final da fila
void adicionarPedido(Fila *fila, Pedido pedido) {

    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->pedido = pedido;
    novo->proximo = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novo;
    } else {
        fila->fim->proximo = novo;
    }

    fila->fim = novo;
    fila->quantidade++;

    printf("Pedido %d adicionado com sucesso!\n", pedido.id);
}

// Remove o primeiro pedido da fila
int removerPedido(Fila *fila, Pedido *pedido) {

    if (filaVazia(fila)) {
        printf("Nao existem pedidos na fila!\n");
        return 0;
    }

    No *auxiliar = fila->inicio;

    *pedido = auxiliar->pedido;

    fila->inicio = auxiliar->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(auxiliar);

    fila->quantidade--;

    return 1;
}

// Mostra todos os pedidos aguardando
void mostrarFila(Fila *fila) {

    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }

    No *atual = fila->inicio;

    printf("\n--- PEDIDOS AGUARDANDO ---\n");

    while (atual != NULL) {

        printf("Pedido: %d\n", atual->pedido.id);
        printf("Cliente: %s\n", atual->pedido.cliente);
        printf("Produto: %s\n", atual->pedido.produto);
        printf("Quantidade: %d\n", atual->pedido.quantidade);
        printf("Preco: R$ %.2f\n", atual->pedido.preco);

        printf("-------------------------\n");

        atual = atual->proximo;
    }
}

// Libera a memoria utilizada pela fila
void liberarFila(Fila *fila) {

    No *atual = fila->inicio;

    while (atual != NULL) {

        No *auxiliar = atual;
        atual = atual->proximo;

        free(auxiliar);
    }

    fila->inicio = NULL;
    fila->fim = NULL;
    fila->quantidade = 0;
}

// Insere um pedido no inicio da fila
void inserirInicio(Fila *fila, Pedido pedido) {

    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->pedido = pedido;
    novo->proximo = fila->inicio;

    fila->inicio = novo;

    if (fila->fim == NULL) {
        fila->fim = novo;
    }

    fila->quantidade++;

    printf("Pedido %d recuperado para a fila!\n", pedido.id);
}