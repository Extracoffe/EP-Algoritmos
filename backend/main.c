
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pedidos.h"
#include "fila.h"
#include "pilha.h"


// Le a quantidade e verifica se e um numero inteiro positivo
int lerInteiroPositivo(const char *mensagem) {
    char entrada[100];
    char caractereExtra;
    int valor;

    while (1) {
        printf("%s", mensagem);

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            exit(0);
        }

        if (sscanf(entrada, "%d %c", &valor, &caractereExtra) == 1
            && valor > 0) {
            return valor;
        }

        printf("Entrada invalida! Digite um numero inteiro maior que zero.\n");
    }
}


// Le o preco e verifica se e positivo
float lerPrecoPositivo(const char *mensagem) {
    char entrada[100];
    char caractereExtra;
    float valor;

    while (1) {
        printf("%s", mensagem);

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            exit(0);
        }

        if (sscanf(entrada, "%f %c", &valor, &caractereExtra) == 1
            && valor > 0) {
            return valor;
        }

        printf("Entrada invalida!\n");
    }
}


// Le um texto e impede que o campo fique vazio ou ultrapasse o limite
void lerTexto(const char *mensagem, char destino[], size_t tamanho) {
    int caractere;
    int possuiConteudo;

    while (1) {
        printf("%s", mensagem);

        if (fgets(destino, tamanho, stdin) == NULL) {
            exit(0);
        }

        if (strchr(destino, '\n') == NULL) {
            caractere = getchar();

            if (caractere != '\n' && caractere != EOF) {
                while ((caractere = getchar()) != '\n' && caractere != EOF) {
                }

                printf("Texto muito longo! Tente novamente.\n");
                continue;
            }
        }

        destino[strcspn(destino, "\n")] = '\0';

        possuiConteudo = 0;

        for (int i = 0; destino[i] != '\0'; i++) {
            if (!isspace((unsigned char)destino[i])) {
                possuiConteudo = 1;
                break;
            }
        }

        if (possuiConteudo) {
            return;
        }

        printf("O campo nao pode ficar vazio!\n");
    }
}


int main() {
    Fila filaPedidos;
    Pilha historicoPedidos;

    inicializarFila(&filaPedidos);
    inicializarPilha(&historicoPedidos);

    int opcao = -1;
    int proximoId = 1;
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

                novoPedido.id = proximoId;

                lerTexto("Nome do cliente: ", novoPedido.cliente,
                         sizeof(novoPedido.cliente));

                lerTexto("Produto: ", novoPedido.produto,
                         sizeof(novoPedido.produto));

                novoPedido.quantidade = lerInteiroPositivo("Quantidade: ");

                novoPedido.preco = lerPrecoPositivo("Preco unitario: R$ ");

                adicionarPedido(&filaPedidos, novoPedido);

                proximoId++;

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
