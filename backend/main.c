
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pedidos.h"
#include "fila.h"
#include "pilha.h"

int main() {

    Fila filaPedidos;
    Pilha historicoPedidos;

    inicializarFila(&filaPedidos);
    inicializarPilha(&historicoPedidos);

    int opcao = -1;
    int proximoId = 1;
    int descarte;

    char entrada[100];
    char caractereExtra;

    Pedido novoPedido;
    Pedido pedidoProcessado;

    do {

        printf("\n===== GERENCIAMENTO DE PEDIDOS =====\n");
        printf("1 - Cadastrar pedido\n");
        printf("2 - Mostrar pedidos aguardando\n");
        printf("3 - Preparar proximo pedido\n");
        printf("4 - Consultar historico de preparados\n");
        printf("5 - Recuperar ultimo pedido preparado\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            opcao = 0;
        } else if (sscanf(entrada, "%d %c", &opcao, &caractereExtra) != 1) {
            opcao = -1;
        }

        switch (opcao) {

            case 1:
                printf("\n--- CADASTRAR PEDIDO ---\n");

                novoPedido.id = proximoId++;

                printf("Nome do cliente: ");
                scanf(" %49[^\n]", novoPedido.cliente);

                printf("Produto: ");
                scanf(" %49[^\n]", novoPedido.produto);

                printf("Quantidade: ");
                scanf("%d", &novoPedido.quantidade);

                printf("Preco unitario: R$ ");
                scanf("%f", &novoPedido.preco);

                while ((descarte = getchar()) != '\n' && descarte != EOF) {
                }

                adicionarPedido(&filaPedidos, novoPedido);

                break;

            case 2:
                mostrarFila(&filaPedidos);
                break;

            case 3:
                printf("\n--- PREPARAR PEDIDO ---\n");

                if (removerPedido(&filaPedidos, &pedidoProcessado)) {

                    if (empilhar(&historicoPedidos, pedidoProcessado)) {

                        printf("\nPedido preparado com sucesso!\n");
                        printf("Numero do pedido: %d\n", pedidoProcessado.id);
                        printf("Cliente: %s\n", pedidoProcessado.cliente);
                        printf("Produto: %s\n", pedidoProcessado.produto);

                    } else {

                        inserirInicio(&filaPedidos, pedidoProcessado);

                        printf("Nao foi possivel registrar o pedido no historico.\n");
                    }
                }

                break;

            case 4:
                printf("\n--- HISTORICO DE PEDIDOS ---\n");
                mostrarPilha(&historicoPedidos);
                break;

            case 5:
                printf("\n--- RECUPERAR PEDIDO ---\n");

                if (desempilhar(&historicoPedidos, &pedidoProcessado)) {

                    inserirInicio(&filaPedidos, pedidoProcessado);

                    printf("Pedido %d voltou para a fila!\n", pedidoProcessado.id);
                }

                break;

            case 0:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    liberarFila(&filaPedidos);
    liberarPilha(&historicoPedidos);

    return 0;
}
