#ifndef PEDIDOS_H
#define PEDIDOS_H

typedef struct {
    int id;
    char cliente[50];
    char produto[50];
    int quantidade;
    float preco;
} Pedido;

#endif