Registro do processo de desenvolvimento com ferramentas de IA

1. Identificação do projeto

- Disciplina: Algoritmos
- Atividade: EP – Pilhas e Filas
- Tema: Gerenciamento de pedidos de fast-food
- Linguagem: C
- Repositório: https://github.com/Extracoffe/EP-Algoritmos
- Pasta local do projeto: `~/Documentos/EP-Algoritmos`
- Pasta do backend: `~/Documentos/EP-Algoritmos/backend`
- Ambiente utilizado: Debian 12, Visual Studio Code e GCC 12.2.0
- Arquivo de execução: `fastfood`

OBSERVAÇÃO IMPORTANTE SOBRE O ESCOPO E A FIDELIDADE DO REGISTRO

Este documento registra exclusivamente a participação da estudante no desenvolvimento do backend em linguagem C. Não documenta o desenvolvimento do site ou as tarefas realizadas por outros integrantes.

As iterações abaixo são uma reconstrução cronológica em forma de síntese, baseada nas informações e nos registros de desenvolvimento que estão disponíveis. Elas não são uma transcrição literal e integral de todas as mensagens trocadas com a IA. Por esse motivo, os textos identificados como “síntese” não devem ser interpretados como prompts ou respostas reproduzidos palavra por palavra. Nenhuma fala literal foi criada para preencher lacunas. Para cumprir a exigência de histórico integral de interações, as conversas completas originais devem ser anexadas ou exportadas separadamente, caso ainda estejam disponíveis.

2. Objetivo e descrição do problema

O projeto consiste em um sistema de gerenciamento de pedidos de um estabelecimento de fast-food. O sistema permite cadastrar pedidos, consultar os pedidos que aguardam preparo, preparar o próximo pedido, consultar o histórico dos pedidos preparados e recuperar o último pedido preparado.

O problema foi escolhido para demonstrar o uso de duas estruturas de dados estudadas na disciplina:

- Fila (FIFO – First In, First Out): organiza os pedidos que aguardam preparo. O primeiro pedido cadastrado é o primeiro a ser preparado.
- Pilha (LIFO – Last In, First Out): guarda o histórico dos pedidos preparados. O pedido preparado mais recentemente fica no topo e é o primeiro que pode ser recuperado.

As duas estruturas são essenciais para o funcionamento proposto: a fila controla a ordem de atendimento e a pilha permite consultar e recuperar o pedido preparado mais recentemente.

3. Organização das estruturas e decisões do projeto

3.1 Fila de pedidos aguardando

Foi escolhida uma fila implementada com lista encadeada. Cada nó armazena um pedido e um ponteiro para o próximo nó. A estrutura mantém referências para o início e o fim da fila, além da quantidade de elementos.

- A inclusão de um pedido novo acontece no final da fila.
- A preparação remove o pedido do início da fila.
- A consulta percorre a fila sem alterar sua ordem.

Essa organização representa o atendimento por ordem de chegada (FIFO).

3.2 Pilha de pedidos preparados

Foi escolhida uma pilha implementada com lista encadeada. Cada nó armazena um pedido e um ponteiro para o nó abaixo dele. A estrutura mantém uma referência para o topo e a quantidade de elementos.

- Quando um pedido é preparado, ele é colocado no topo da pilha.
- A consulta mostra primeiro o pedido preparado mais recentemente.
- A recuperação retira o pedido do topo da pilha.

Essa organização representa o comportamento LIFO.

3.3 Recuperação do último pedido preparado

Foi definida uma operação para recuperar o pedido que acabou de ser preparado. A operação retira o pedido do topo da pilha e o insere no início da fila, para que ele seja o próximo a ser preparado novamente, antes dos pedidos que já estavam aguardando.

Essa decisão mantém explícita a diferença entre as estruturas: a recuperação usa a operação de desempilhar e, em seguida, insere o pedido no começo da fila.

4. Registro cronológico das iterações

As datas abaixo correspondem aos dias associados às etapas no histórico recuperável. Os horários não foram registrados neste documento. As solicitações e orientações são apresentadas como sínteses, não como citações literais.

Iteração 1 — Definição do escopo e do tema

- Data: 08/11/2026
- Objetivo: delimitar o problema e definir o que seria implementado no trabalho.
- Solicitação à IA (síntese): orientação para desenvolver o EP de Algoritmos sobre gerenciamento de pedidos de fast-food, com foco em pilhas e filas.
- Orientação recebida (síntese): separar o problema em operações de cadastro, consulta, preparo e recuperação de pedidos; identificar onde cada estrutura de dados seria necessária.
- Decisão: desenvolver o backend em C. Os arquivos do site que já existiam no repositório não fariam parte das alterações desta etapa.
- Resultado: escopo funcional definido para o sistema de pedidos.

Iteração 2 — Escolha e justificativa das estruturas

- Data: 08/11/2026
- Objetivo: determinar como pilha e fila seriam usadas de maneira necessária, e não apenas decorativa.
- Solicitação à IA (síntese): avaliar a aplicação de FIFO e LIFO no fluxo de pedidos e propor as operações principais.
- Orientação recebida (síntese): usar uma fila para os pedidos aguardando preparo e uma pilha para o histórico dos pedidos preparados.
- Observação sobre alternativas: a solução adotada foi separar os pedidos aguardando em uma fila e os pedidos preparados em uma pilha. Não há registro literal suficiente para afirmar que uma alternativa específica foi efetivamente testada; por isso, não se atribui ao processo uma comparação experimental que não esteja documentada.
- Decisão: manter as duas estruturas, com responsabilidades diferentes. Também foi incluída a recuperação do último pedido preparado, que evidencia a operação LIFO.
- Resultado: fluxo de dados definido antes da implementação.

Iteração 3 — Preparação do ambiente e organização dos arquivos

- Data: 08/11/2026
- Objetivo: preparar o projeto local e organizar os arquivos do backend.
- Solicitação à IA (síntese): orientação para trabalhar no repositório do projeto usando o ambiente Debian, VS Code e compilador GCC.
- Orientação recebida (síntese): manter os arquivos do backend separados e compilar os módulos C em conjunto.
- Decisão: utilizar arquivos `.h` para declarações e estruturas e arquivos `.c` para implementações e integração.
- Resultado: ambiente de desenvolvimento preparado na pasta `backend`.

Iteração 4 — Definição da estrutura Pedido

- Data: 08/11/2026
- Objetivo: definir os dados necessários para representar cada pedido.
- Solicitação à IA (síntese): estruturar em C os campos de um pedido de fast-food.
- Orientação recebida (síntese): criar uma estrutura compartilhada para que fila, pilha e programa principal trabalhassem com o mesmo tipo de dado.
- Decisão: criar `pedidos.h` com a estrutura `Pedido`, contendo identificador, nome do cliente, produto, quantidade e preço.
- Resultado: tipo de dado comum definido para os módulos.

Iteração 5 — Implementação da fila

- Data: 08/11/2026
- Objetivo: implementar a fila de pedidos aguardando preparo.
- Solicitação à IA (síntese): desenvolver a fila em C com lista encadeada e operações de inicialização, inserção, remoção, consulta e liberação de memória.
- Orientação recebida (síntese): manter ponteiros para o início e o fim, inserir no final e remover do início, respeitando FIFO.
- Decisão: separar declarações e implementação em `fila.h` e `fila.c`.
- Resultado: foram criadas as funções `inicializarFila`, `filaVazia`, `adicionarPedido`, `removerPedido`, `mostrarFila`, `liberarFila` e `inserirInicio`. A função `inserirInicio` também permite devolver um pedido recuperado ou restaurar um pedido em uma situação de falha.

Iteração 6 — Implementação da pilha

- Data: 08/11/2026
- Objetivo: implementar o histórico dos pedidos preparados.
- Solicitação à IA (síntese): criar uma pilha encadeada em C, com operações de empilhar, desempilhar, consulta e liberação.
- Orientação recebida (síntese): inserir e remover sempre pelo topo, para manter a regra LIFO.
- Decisão: separar declarações e implementação em `pilha.h` e `pilha.c`, usando nós próprios da pilha.
- Resultado: foram criadas as funções `inicializarPilha`, `pilhaVazia`, `empilhar`, `desempilhar`, `mostrarPilha` e `liberarPilha`.

Iteração 7 — Integração e menu principal

- Data: 08/11/2026
- Objetivo: integrar as estruturas em um programa interativo.
- Solicitação à IA (síntese): organizar o menu e conectar as operações da fila e da pilha.
- Orientação recebida (síntese): oferecer opções separadas para cadastrar, consultar, preparar, consultar histórico, recuperar e sair.
- Decisão: implementar o menu em `main.c` com as opções:
  1. Cadastrar pedido;
  2. Mostrar pedidos aguardando;
  3. Preparar próximo pedido;
  4. Consultar histórico de preparados;
  5. Recuperar último pedido preparado;
  0. Sair.
- Resultado: as operações principais passaram a ser acessíveis pelo menu.

Iteração 8 — Compilação inicial e correções

- Data: 08/11/2026 a 09/11/2026
- Objetivo: verificar se os módulos compilavam juntos e localizar problemas de integração.
- Solicitação à IA (síntese): analisar erros de compilação e orientar os testes do programa.
- Orientação recebida (síntese): compilar todos os arquivos `.c` necessários em um único comando, habilitando avisos do compilador.
- Comando utilizado:

  ```bash
  gcc -Wall -Wextra -std=c11 main.c fila.c pilha.c -o fastfood
  ```

- Decisão: manter os avisos `-Wall` e `-Wextra` durante a compilação para ajudar a identificar problemas.
- Resultado: compilação concluída sem mensagens de erro ou avisos. O executável foi iniciado com `./fastfood`.

Iteração 9 — Validação das entradas

- Data: 09/11/2026
- Objetivo: impedir entradas inválidas nos dados dos pedidos e no menu.
- Solicitação à IA (síntese): revisar a leitura de dados e considerar situações como texto em campos numéricos, valores não positivos e campos de texto vazios.
- Orientação recebida (síntese): validar as entradas antes de utilizá-las e tratar leituras de texto com `fgets`.
- Decisão: utilizar as funções `lerTexto`, `lerInteiroPositivo` e `lerPrecoPositivo` para validar os campos. A quantidade deve ser um inteiro positivo e o preço deve ser positivo.
- Testes realizados:
  - Digitar `abc` no menu: entrada identificada como inválida.
  - Digitar uma quantidade decimal: valor rejeitado, pois a quantidade deve ser inteira.
  - Informar dados válidos: cadastro aceito.
- Resultado: validações básicas verificadas.

Iteração 10 — Testes de fila vazia, pilha vazia e operações

- Data: 09/11/2026
- Objetivo: testar os casos de borda e o funcionamento das operações.
- Solicitação à IA (síntese): propor casos de teste para fila e pilha, incluindo tentativas de remover elementos quando as estruturas estão vazias.
- Orientação recebida (síntese): testar cada operação isoladamente e depois testar o fluxo completo de cadastro, preparo e recuperação.
- Testes realizados e resultados:
  - Consultar fila vazia: exibiu `Fila vazia!`.
  - Consultar histórico vazio: exibiu `Historico de pedidos vazio!`.
  - Preparar com fila vazia: exibiu `Nao existem pedidos na fila!`.
  - Recuperar com pilha vazia: exibiu `Pilha vazia!`.
  - Cadastrar pedido com cliente Tina, produto hot dog, quantidade 2 e preço unitário 20,2: dados exibidos com preço `R$ 20.20`.
  - Preparar um pedido: ele saiu da fila e foi armazenado no histórico.
  - Recuperar um pedido: ele saiu do histórico e voltou para o início da fila.
  - Escolher a opção 0: o programa encerrou normalmente.
- Resultado: casos básicos e casos de estrutura vazia verificados.

Iteração 11 — Teste específico de FIFO e LIFO

- Data: 09/11/2026
- Objetivo: verificar, com mais de um pedido, se as estruturas respeitavam suas regras de remoção.
- Solicitação à IA (síntese): conferir um cenário que permitisse observar a ordem dos pedidos na fila e na pilha.
- Orientação recebida (síntese): cadastrar três pedidos, preparar os dois primeiros e comparar a ordem exibida no histórico; depois recuperar o último preparado.
- Teste realizado: foram cadastrados três pedidos identificados como 1, 2 e 3. Os pedidos 1 e 2 foram preparados.
- Resultado observado:
  - A fila manteve o pedido 3 aguardando.
  - O histórico mostrou o pedido 2 antes do pedido 1, pois 2 foi o último a ser preparado (LIFO).
  - Ao recuperar o pedido 2, ele saiu do topo da pilha e foi colocado no início da fila.
  - A fila passou a mostrar 2 antes de 3, e o histórico permaneceu com o pedido 1.
- Conclusão: o teste confirmou o comportamento FIFO da fila e LIFO da pilha, além da regra escolhida para recuperação.

Iteração 12 — Primeiro registro no GitHub

- Data: 09/11/2026
- Objetivo: registrar a primeira versão funcional do backend no controle de versão.
- Solicitação à IA (síntese): orientação para verificar os arquivos modificados e realizar o commit do backend.
- Decisão: adicionar os arquivos-fonte do backend, sem incluir o executável gerado nem arquivos intermediários de compilação.
- Commit: `85d781d` — `Adiciona backend de gerenciamento de pedidos`.
- Link: https://github.com/Extracoffe/EP-Algoritmos/commit/85d781d
- Resultado: primeira versão do backend registrada no repositório remoto.

Iteração 13 — Ajuste do título do histórico

- Data: 10/11/2026
- Objetivo: corrigir a exibição duplicada do título ao consultar o histórico.
- Problema observado: a opção 4 do menu imprimia um título antes de chamar `mostrarPilha`, mas a própria função `mostrarPilha` já imprimia o título do histórico. Isso causava duplicidade.
- Solicitação à IA (síntese): analisar a duplicação e indicar a menor alteração necessária.
- Orientação recebida (síntese): retirar a impressão redundante do `case 4` em `main.c` e deixar a função responsável pela exibição do histórico.
- Alteração realizada: o `case 4` passou a chamar somente `mostrarPilha(&historicoPedidos);`.
- Teste realizado: executar o programa, escolher a opção 4 com a pilha vazia e verificar a mensagem apresentada.
- Resultado: foi exibida apenas a mensagem `Historico de pedidos vazio!`, sem o título duplicado.

Iteração 14 — Commit do ajuste e envio ao GitHub

- Data: 10/11/2026
- Objetivo: registrar a correção de exibição no repositório.
- Solicitação à IA (síntese): orientação para conferir a alteração e registrar o segundo commit.
- Commit: `3433f50` — `Ajusta exibicao do historico de pedidos`.
- Link: https://github.com/Extracoffe/EP-Algoritmos/commit/3433f50
- Resultado: o commit foi enviado com sucesso para a branch `main`.

5. Arquivos do backend

| Arquivo | Responsabilidade |
|---|---|
| `pedidos.h` | Declara a estrutura `Pedido`, compartilhada pelos módulos. |
| `fila.h` | Declara a estrutura da fila e suas funções. |
| `fila.c` | Implementa a fila encadeada de pedidos aguardando preparo. |
| `pilha.h` | Declara a estrutura da pilha e suas funções. |
| `pilha.c` | Implementa a pilha encadeada do histórico de pedidos preparados. |
| `main.c` | Contém o menu, a leitura dos dados e a integração das operações. |

Principais funções

Fila: `inicializarFila`, `filaVazia`, `adicionarPedido`, `removerPedido`, `mostrarFila`, `liberarFila` e `inserirInicio`.

Pilha: `inicializarPilha`, `pilhaVazia`, `empilhar`, `desempilhar`, `mostrarPilha` e `liberarPilha`.

Entrada de dados: `lerTexto`, `lerInteiroPositivo` e `lerPrecoPositivo`.

6. Como compilar e executar

Dentro da pasta `backend`, utilizar:

```bash
gcc -Wall -Wextra -std=c11 main.c fila.c pilha.c -o fastfood
./fastfood
```

7. Resumo dos testes realizados

| Cenário | Resultado esperado/observado |
|---|---|
| Opção inválida no menu (`abc`) | Entrada rejeitada como inválida. |
| Consultar fila vazia | Mensagem de fila vazia. |
| Consultar pilha vazia | Mensagem de histórico vazio. |
| Preparar sem pedidos | Operação não realizada; mensagem informativa. |
| Recuperar sem histórico | Operação não realizada; mensagem informativa. |
| Quantidade decimal | Entrada rejeitada; quantidade exige inteiro positivo. |
| Cadastro válido | Pedido cadastrado e exibido corretamente. |
| Preparar pedido | Pedido removido do início da fila e empilhado no histórico. |
| Recuperar pedido | Pedido desempilhado e inserido no início da fila. |
| Dois preparos em sequência | Histórico apresenta primeiro o pedido preparado por último. |
| Encerrar pelo menu | Programa encerra normalmente. |
| Consultar histórico vazio após ajuste | Mensagem aparece sem título duplicado. |
| Compilação com `-Wall -Wextra` | Compilação concluída sem avisos ou erros. |

8. Participação e uso da IA

A IA foi utilizada como ferramenta de apoio ao desenvolvimento, principalmente para organizar o problema, discutir a escolha das estruturas de dados, orientar a implementação incremental, revisar trechos do código, sugerir testes e auxiliar na interpretação de erros e ajustes.

As decisões de projeto foram acompanhadas de testes no ambiente local. A estudante executou o programa, forneceu entradas, observou as saídas, identificou o problema de título duplicado e verificou a correção. O uso da IA não substitui a necessidade de compreender e explicar o funcionamento das estruturas, das funções e das decisões durante a apresentação.

Este documento é um registro individual da participação da estudante no backend. Ele não substitui os registros dos demais integrantes, caso a entrega do grupo exija reunir também as interações realizadas por eles.

9. Histórico de versões no GitHub

1. `85d781d` — Adiciona backend de gerenciamento de pedidos  
   https://github.com/Extracoffe/EP-Algoritmos/commit/85d781d
2. `3433f50` — Ajusta exibicao do historico de pedidos  
   https://github.com/Extracoffe/EP-Algoritmos/commit/3433f50

10. Conferência final e materiais complementares

Antes da entrega, é necessário:

- Anexar ou exportar o histórico original completo das conversas com a IA, incluindo prompts e respostas, se ainda estiver disponível. Essa etapa é necessária porque este documento contém sínteses cronológicas e não uma transcrição integral.
- Conferir se as datas das iterações correspondem aos registros originais. Se alguma data não puder ser confirmada, identificá-la como aproximada ou não determinada, em vez de apresentar uma data como exata.
- Conferir se o código no repositório corresponde à versão que será demonstrada.
- Preparar a explicação individual sobre FIFO, LIFO, operações de inserção e remoção, recuperação de pedidos e tratamento de fila ou pilha vazia.
- Se o professor solicitar um único arquivo do grupo, reunir separadamente os registros dos outros integrantes, sem atribuir a esta estudante atividades que não realizou.

11. Limites do que foi verificado

Os testes descritos nas iterações são os testes relatados durante o desenvolvimento. Não se afirma que foram realizados testes automatizados, testes de desempenho, análise com Valgrind ou testes de falha forçada de alocação de memória. A compilação registrada foi feita com `-Wall -Wextra -std=c11` e foi relatada sem avisos ou erros.

A validação da alocação de memória e a restauração do pedido em caso de falha durante a transferência entre fila e pilha são comportamentos descritos no código, mas não devem ser apresentados como casos de falha efetivamente testados, a menos que um teste específico seja realizado e registrado.
