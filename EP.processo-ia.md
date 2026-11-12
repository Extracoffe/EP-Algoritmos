# REGISTRO DO PROCESSO DE DESENVOLVIMENTO COM APOIO DE INTELIGÊNCIA ARTIFICIAL

EP -- Pilhas e Filas | Disciplina: Algoritmos

Projeto: Sistema de gerenciamento de pedidos de fast-food

## 1. IDENTIFICAÇÃO E ESCOPO DA PARTICIPAÇÃO

-   Atividade: EP -- Pilhas e Filas.
-   Tema: gerenciamento de pedidos de um estabelecimento de fast-food.
-   Linguagem do backend: C.
-   Repositório do grupo: https://github.com/Extracoffe/EP-Algoritmos
-   Pasta local do projeto: `~/Documentos/EP-Algoritmos`
-   Pasta do backend: `~/Documentos/EP-Algoritmos/backend`
-   Ambiente utilizado: Debian 12, Visual Studio Code e GCC 12.2.0.
-   Executável do backend: `fastfood`.
-   Período documentado: 08/11/2026 a 10/11/2026, conforme os registros
    recuperáveis.

### 1.1 Escopo individual

Este documento registra a participação da estudante na implementação e
nos testes do backend em C. O repositório é compartilhado pelo grupo e
também contém a parte de site/interface, mas este diário não atribui à
estudante tarefas de desenvolvimento do site nem atividades executadas
por outros integrantes.

### 1.2 Como este registro foi elaborado e consulta ao histórico original

Este diário organiza cronologicamente o processo de desenvolvimento,
com sínteses das solicitações feitas à IA, das orientações recebidas,
das decisões tomadas, das alterações realizadas e dos testes relatados.
Os trechos identificados como "pedido à IA --- reconstrução" e as
sínteses das respostas não são transcrições palavra por palavra; foram
redigidos para resumir com clareza o conteúdo das interações, sem
inventar mensagens, horários, erros ou testes.

A conversa original sobre o desenvolvimento foi realizada nesta
plataforma e está disponibilizada pelo link compartilhado abaixo. O
histórico integral deve ser consultado diretamente nesse endereço; este
arquivo funciona como diário organizado e guia de leitura do processo,
não como substituto da conversa original.

Histórico original da conversa com a IA:
https://chatgpt.com/share/6af3af16-9d68-83e9-a1ba-c4e1ac8074f2

Para a conferência pelo professor, é importante testar o link em uma
janela anônima ou em outro navegador e confirmar que a conversa está
visível sem depender da conta da estudante. Se a plataforma solicitar
acesso ou se o compartilhamento não estiver disponível, será necessário
ajustar as permissões do compartilhamento ou anexar uma exportação da
conversa. Caso outros integrantes tenham utilizado IA em conversas
separadas, os respectivos históricos também devem ser disponibilizados.

## 2. ORIENTAÇÕES DA ATIVIDADE CONSIDERADAS DURANTE O DESENVOLVIMENTO

A atividade propõe que o grupo desenvolva uma aplicação funcional na
qual pilha e/ou fila sejam necessárias para resolver o problema
escolhido. Além de entregar o código e demonstrar o funcionamento, os
integrantes precisam compreender e justificar as estruturas utilizadas,
explicar as operações e apresentar o processo de desenvolvimento com IA.

As orientações consideradas neste trabalho incluem:

-   escolher um problema em que as estruturas de dados tenham uma função
    real;
-   explicar por que a fila, a pilha ou ambas são adequadas ao problema;
-   desenvolver a solução em etapas pequenas, verificando cada parte
    antes de avançar;
-   testar operações normais e casos de borda, como estruturas vazias;
-   registrar cronologicamente solicitações, orientações, alternativas
    consideradas, decisões, mudanças, testes e correções;
-   manter o código funcional e conseguir explicar seu funcionamento
    durante a apresentação.

A apresentação informada para a atividade está prevista para 13/11/2026,
com tempo de apresentação e demonstração seguido de perguntas. Por isso,
além da implementação, foi necessário compreender a lógica de FIFO, LIFO
e a integração entre as estruturas.

## 3. PROBLEMA ESCOLHIDO E FUNCIONAMENTO ESPERADO

O sistema representa o fluxo básico de pedidos de um fast-food. A pessoa
usuária pode cadastrar pedidos, visualizar os pedidos que aguardam
preparo, preparar o próximo pedido, consultar os pedidos preparados que
ainda podem ser recuperados e recuperar o último pedido preparado.

Cada pedido é representado pela estrutura `Pedido`, com os seguintes
dados:

-   identificador;
-   nome do cliente;
-   produto;
-   quantidade;
-   preço.

O sistema utiliza duas estruturas diferentes porque existem duas regras
de organização distintas:

### 3.1 Fila --- FIFO (First In, First Out)

A fila armazena os pedidos que aguardam preparo. O primeiro pedido que
entra é o primeiro que deve sair para ser preparado.

-   Cadastro normal: insere no final da fila.
-   Preparação: remove do início da fila.
-   Consulta: percorre a fila para mostrar os pedidos sem mudar sua
    ordem.

A implementação utiliza lista encadeada, com referências para o início e
o fim e um contador de elementos. Cada nó guarda um pedido e o ponteiro
para o próximo nó.

### 3.2 Pilha --- LIFO (Last In, First Out)

A pilha armazena os pedidos que já foram preparados e que continuam
disponíveis para recuperação. O pedido preparado mais recentemente fica
no topo e é o primeiro que pode ser recuperado.

-   Preparação: empilha o pedido no topo.
-   Consulta: apresenta primeiro o elemento do topo.
-   Recuperação: desempilha o pedido do topo.

A implementação também utiliza lista encadeada, mas com nós próprios da
pilha e uma referência para o topo.

Precisão conceitual: a pilha não é um histórico permanente e imutável de
todos os pedidos preparados. Como a recuperação retira o pedido por meio
de `desempilhar`, ela representa os pedidos preparados que ainda podem
ser recuperados.

### 3.3 Operação de recuperação

Ao recuperar um pedido, o programa retira o elemento do topo da pilha e
o insere no início da fila. Essa inserção especial é feita para que o
pedido recuperado seja o próximo a ser preparado, ficando antes dos
pedidos que já aguardavam.

Isso não altera a regra do cadastro normal: pedidos novos continuam
entrando no final da fila. A função `inserirInicio` existe para atender
à recuperação e também para permitir a restauração de um pedido ao
início da fila em uma situação de falha durante a transferência.

## 4. DIÁRIO CRONOLÓGICO DETALHADO DAS INTERAÇÕES E ITERAÇÕES

As datas indicam os dias associados às etapas nos registros
recuperáveis. Quando uma etapa abrange mais de um dia, isso é informado.
Não foram preservados horários completos para todas as interações. Os
pedidos à IA abaixo são reconstruções de conteúdo, não citações
literais.

Iteração 1 --- Entendimento da atividade e delimitação do trabalho

-   Data: 08/11/2026.
-   Objetivo: compreender o que o EP exigia e delimitar a parte que
    seria desenvolvida pela estudante.
-   Pedido à IA --- reconstrução: ajudar a interpretar a atividade de
    Algoritmos sobre pilhas e filas, considerando a necessidade de uma
    aplicação funcional, código, demonstração e registro do uso de IA.
-   Orientação recebida --- síntese: começar pelo problema e pelo fluxo
    de funcionamento; não utilizar pilha ou fila apenas para cumprir
    formalmente a exigência, mas fazer com que as operações dependam das
    regras dessas estruturas.
-   Contexto/decisão da estudante: o backend deveria ser desenvolvido em
    C, no Visual Studio Code, enquanto o projeto do grupo também possuía
    uma parte de site/interface. O escopo individual do registro ficou
    restrito ao backend.
-   Resultado: definido que o diário acompanharia a implementação em C,
    sem atribuir à estudante a parte de site.

Iteração 2 --- Escolha do tema de gerenciamento de pedidos

-   Data: 08/11/2026.
-   Objetivo: definir um problema simples de demonstrar e que
    justificasse o uso das estruturas estudadas.
-   Pedido à IA --- reconstrução: estruturar uma proposta de sistema de
    gerenciamento de pedidos de fast-food e identificar as operações que
    fariam sentido nesse cenário.
-   Orientação recebida --- síntese: organizar o fluxo em cadastro de
    pedido, consulta dos pedidos aguardando, preparo do próximo,
    consulta dos pedidos preparados e recuperação do último preparado.
-   Alternativas e justificativa: armazenar todos os pedidos em uma
    lista genérica seria possível, mas não evidenciaria diretamente as
    regras FIFO e LIFO. A separação em fila e pilha torna as estruturas
    parte essencial da lógica.
-   Decisão: adotar o gerenciamento de pedidos de fast-food como tema.
-   Resultado: problema delimitado e operações principais identificadas.

Iteração 3 --- Definição de como cada estrutura seria utilizada

-   Data: 08/11/2026.
-   Objetivo: garantir que fila e pilha tivessem papéis diferentes e
    justificáveis.
-   Pedido à IA --- reconstrução: avaliar como aplicar FIFO e LIFO no
    fluxo de pedidos e propor a responsabilidade de cada estrutura.
-   Orientação recebida --- síntese: utilizar a fila para pedidos que
    aguardam preparo e a pilha para pedidos já preparados que podem ser
    recuperados.
-   Decisão: a fila controlaria a ordem normal de atendimento; a pilha
    permitiria recuperar o pedido preparado mais recentemente.
-   Resultado: definida a relação entre o problema e os conceitos
    FIFO/LIFO antes de avançar para o código.

Iteração 4 --- Planejamento da organização dos arquivos

-   Data: 08/11/2026.
-   Objetivo: organizar o backend em módulos para separar
    responsabilidades.
-   Pedido à IA --- reconstrução: orientar a divisão do backend em
    arquivos C e cabeçalhos, de modo que fila, pilha e programa
    principal pudessem ser desenvolvidos e compilados em conjunto.
-   Orientação recebida --- síntese: separar a estrutura compartilhada
    do pedido, os módulos de fila e pilha e o arquivo principal com menu
    e integração.
-   Decisão: utilizar `main.c`, `pedidos.h`, `fila.h`, `fila.c`,
    `pilha.h` e `pilha.c`.
-   Resultado: estrutura inicial de arquivos definida na pasta `backend`
    do repositório local.

Iteração 5 --- Definição da estrutura `Pedido`

-   Data: 08/11/2026.
-   Objetivo: determinar quais informações cada elemento das estruturas
    precisaria armazenar.
-   Pedido à IA --- reconstrução: elaborar uma estrutura em C que
    representasse um pedido de fast-food e pudesse ser compartilhada
    pela fila e pela pilha.
-   Orientação recebida --- síntese: criar uma definição comum de
    pedido, evitando que cada módulo utilize uma representação
    diferente.
-   Decisão: declarar em `pedidos.h` a estrutura `Pedido` com
    identificador, cliente, produto, quantidade e preço.
-   Resultado: tipo de dado comum definido para as operações do sistema.

Iteração 6 --- Implementação e compilação isolada da fila

-   Data: 08/11/2026.
-   Objetivo: construir primeiro a estrutura responsável pelos pedidos
    aguardando preparo.
-   Pedido à IA --- reconstrução: implementar uma fila encadeada em C,
    com inicialização, verificação de vazio, inserção, remoção, exibição
    e liberação de memória.
-   Orientação recebida --- síntese: manter ponteiros para início e fim;
    inserir no final e remover do início, garantindo FIFO. Também foi
    prevista uma operação de inserção no início para a recuperação de
    pedidos.
-   Decisão: implementar as declarações em `fila.h` e as operações em
    `fila.c`.
-   Funções desenvolvidas: `inicializarFila`, `filaVazia`,
    `adicionarPedido`, `removerPedido`, `mostrarFila`, `liberarFila` e
    `inserirInicio`.
-   Verificação registrada: foi utilizado o comando de compilação
    isolada:

``` bash
gcc -Wall -Wextra -std=c11 -c fila.c -o fila.o
```

-   Resultado: o objeto `fila.o` foi criado (registro de tamanho: 3768
    bytes). Essa etapa verificou a compilação do módulo; não deve ser
    confundida com um teste de execução de todas as operações da fila.

Iteração 7 --- Implementação e compilação isolada da pilha

-   Data: 08/11/2026.
-   Objetivo: construir a estrutura que armazenaria os pedidos
    preparados disponíveis para recuperação.
-   Pedido à IA --- reconstrução: implementar uma pilha encadeada em C,
    com inicialização, verificação de vazio, empilhamento,
    desempilhamento, exibição e liberação de memória.
-   Orientação recebida --- síntese: inserir e remover sempre pelo topo.
    A lógica LIFO é garantida ao ligar o novo nó ao topo anterior e
    atualizar o ponteiro `topo`.
-   Decisão: separar a interface em `pilha.h` e a implementação em
    `pilha.c`, utilizando nós próprios da pilha.
-   Funções desenvolvidas: `inicializarPilha`, `pilhaVazia`, `empilhar`,
    `desempilhar`, `mostrarPilha` e `liberarPilha`.
-   Verificação registrada: foi utilizado o comando:

``` bash
gcc -Wall -Wextra -std=c11 -c pilha.c -o pilha.o
```

-   Resultado: o objeto `pilha.o` foi criado (registro de tamanho: 3360
    bytes). A compilação isolada verificou o módulo, mas não substituiu
    os testes integrados do programa.

Iteração 8 --- Integração das estruturas no programa principal

-   Data: 08/11/2026.
-   Objetivo: conectar fila e pilha e permitir o uso do sistema por um
    menu.
-   Pedido à IA --- reconstrução: estruturar o `main.c` para inicializar
    as estruturas e oferecer as operações de cadastro, consulta,
    preparo, consulta dos preparados, recuperação e saída.
-   Orientação recebida --- síntese: manter o menu no programa principal
    e chamar as funções dos módulos de fila e pilha, sem misturar toda a
    implementação em um único arquivo.
-   Decisão: organizar o menu com as opções:
    1.  Cadastrar pedido;
    2.  Mostrar pedidos aguardando;
    3.  Preparar próximo pedido;
    4.  Consultar histórico de preparados;
    5.  Recuperar último pedido preparado;
    6.  Sair.
-   Resultado: operações das duas estruturas integradas em uma aplicação
    interativa.

Iteração 9 --- Compilação conjunta e execução do backend

-   Data: 08/11/2026 a 09/11/2026.
-   Objetivo: verificar se os módulos compilavam em conjunto e se o
    executável iniciava.
-   Pedido à IA --- reconstrução: orientar a compilação de todos os
    arquivos-fonte do backend e a execução do programa no terminal.
-   Orientação recebida --- síntese: compilar os arquivos `.c` juntos,
    utilizar os avisos `-Wall` e `-Wextra` e gerar o executável
    `fastfood`.
-   Comando utilizado:

``` bash
gcc -Wall -Wextra -std=c11 main.c fila.c pilha.c -o fastfood
```

-   Execução:

``` bash
./fastfood
```

-   Resultado: compilação conjunta relatada sem mensagens de erro ou
    avisos e inicialização do programa pelo terminal.

Iteração 10 --- Validação das entradas do usuário

-   Data: 09/11/2026.
-   Objetivo: impedir que dados inválidos fossem aceitos pelo menu e
    pelo cadastro.
-   Pedido à IA --- reconstrução: revisar a leitura de texto e números,
    considerando entradas não numéricas, quantidade decimal, valores não
    positivos e campos textuais vazios ou excessivamente longos.
-   Orientação recebida --- síntese: utilizar leitura de texto com
    `fgets` e funções específicas para validar cada tipo de entrada
    antes de utilizá-la.
-   Decisão/implementação: utilizar `lerTexto`, `lerInteiroPositivo` e
    `lerPrecoPositivo`. A quantidade deve ser um inteiro positivo; o
    preço deve ser positivo.
-   Testes registrados:
    -   Digitar `abc` no menu: a entrada foi rejeitada como inválida.
    -   Digitar quantidade decimal: o valor foi rejeitado, pois a
        quantidade exige inteiro.
    -   Informar dados válidos: o cadastro foi aceito.
-   Observação: a entrada de preço utilizada no teste foi com ponto
    decimal (`20.2`), e a exibição formatada apareceu como `R$ 20.20`.
-   Resultado: validações básicas de entrada verificadas.

Iteração 11 --- Testes de fila vazia e pilha vazia

-   Data: 09/11/2026.
-   Objetivo: verificar se o programa tratava corretamente operações
    solicitadas quando não havia elementos.
-   Pedido à IA --- reconstrução: propor testes de borda para consultar,
    preparar ou recuperar pedidos quando a fila ou a pilha estivesse
    vazia.
-   Orientação recebida --- síntese: testar as condições vazias
    separadamente e confirmar que o programa informa a situação sem
    tentar remover um elemento inexistente.
-   Testes realizados e resultados:
    -   Consultar fila vazia: `Fila vazia!`.
    -   Consultar pilha vazia: `Historico de pedidos vazio!`.
    -   Preparar sem pedidos na fila: `Nao existem pedidos na fila!`.
    -   Recuperar sem pedidos na pilha: `Pilha vazia!`.
-   Resultado: os principais casos de estruturas vazias foram
    verificados.

Iteração 12 --- Teste combinado para demonstrar FIFO e LIFO

-   Data: 09/11/2026.
-   Objetivo: verificar a ordem das operações com mais de um pedido, em
    vez de observar apenas um elemento.
-   Pedido à IA --- reconstrução: montar um cenário com três pedidos,
    preparar dois e conferir a ordem apresentada pela fila e pela pilha;
    em seguida, recuperar o último preparado.
-   Orientação recebida --- síntese: utilizar pedidos identificados como
    1, 2 e 3. Preparar 1 e depois 2; a fila deve manter 3, enquanto a
    pilha deve mostrar 2 antes de 1.
-   Teste realizado: foram cadastrados três pedidos identificados como
    1, 2 e 3; os pedidos 1 e 2 foram preparados.
-   Resultados observados:
    -   A fila manteve o pedido 3 aguardando.
    -   A pilha mostrou o pedido 2 antes do pedido 1, pois 2 foi o
        último preparado.
    -   Ao recuperar, o pedido 2 foi removido do topo da pilha.
    -   O pedido 2 foi inserido no início da fila, ficando antes do
        pedido 3.
    -   A pilha permaneceu com o pedido 1.
-   Conclusão: o teste demonstrou FIFO na fila, LIFO na pilha e o
    comportamento especial da recuperação.

Iteração 14 --- Primeiro commit do backend

-   Data: 09/11/2026.
-   Objetivo: registrar a versão inicial dos arquivos do backend no
    controle de versão.
-   Pedido à IA --- reconstrução: orientar a conferência dos arquivos e
    a criação do commit no repositório Git.
-   Decisão: adicionar os arquivos-fonte do backend, sem incluir o
    executável gerado nem arquivos intermediários de compilação.
-   Commit registrado: `85d781d` ---
    `Adiciona backend de gerenciamento de pedidos`.
-   Link: https://github.com/Extracoffe/EP-Algoritmos/commit/85d781d
-   Resultado: primeira versão do backend registrada no GitHub.

Iteração 15 --- Sincronização do repositório com as alterações do grupo

-   Data: 10/11/2026.
-   Objetivo: atualizar a cópia local do repositório sem sobrescrever
    alterações locais.
-   Contexto: o repositório era compartilhado com a parte de
    site/interface. Foi verificado que a branch local estava atrás da
    versão remota.
-   Pedido à IA --- reconstrução: orientar a atualização da branch local
    e a preservação dos arquivos de trabalho que não estavam rastreados
    pelo Git.
-   Orientação recebida --- síntese: buscar as atualizações remotas e
    realizar um `pull` em modo fast-forward, sem criar merge
    desnecessário.
-   Comandos registrados:

``` bash
git fetch origin
git pull --ff-only origin main
```

-   Resultado: a atualização da branch `main` foi concluída. A
    verificação posterior indicou que os artefatos locais de compilação,
    como `fastfood`, `fila.o` e `pilha.o`, continuavam como arquivos não
    rastreados.
-   Decisão de segurança: não executar limpeza geral nem remover esses
    arquivos automaticamente. Eles foram mantidos, pois eram artefatos
    locais e não deveriam ser apagados sem necessidade.

Iteração 16 --- Identificação da duplicação no título do histórico

-   Data: 10/11/2026.
-   Objetivo: melhorar a apresentação da consulta dos pedidos
    preparados.
-   Problema observado: ao selecionar a opção 4, o `main.c` imprimia um
    título antes de chamar `mostrarPilha`, mas a própria função
    `mostrarPilha` também imprimia o título. A saída ficava duplicada.
-   Pedido à IA --- reconstrução: analisar por que o título aparecia
    duas vezes e indicar a menor correção possível, preservando o
    comportamento da função de exibição.
-   Orientação recebida --- síntese: remover a impressão redundante do
    `case 4` e deixar a função `mostrarPilha` controlar a própria
    apresentação.
-   Código anterior:

``` c
case 4:
    printf("\n--- HISTORICO DE PEDIDOS ---\n");
    mostrarPilha(&historicoPedidos);
    break;
```

-   Código ajustado:

``` c
case 4:
    mostrarPilha(&historicoPedidos);
    break;
```

-   Decisão: manter uma única responsabilidade pela impressão do título,
    evitando duplicação.
-   Resultado esperado: a consulta do histórico apresenta o título uma
    única vez quando há elementos; quando a pilha está vazia, apresenta
    a mensagem correspondente.

Iteração 17 --- Teste da correção do histórico

-   Data: 10/11/2026.
-   Objetivo: verificar se a alteração eliminou a duplicação sem
    prejudicar a consulta da pilha vazia.
-   Pedido à IA --- reconstrução: orientar a execução de um teste
    simples da opção 4 após a alteração.
-   Procedimento: executar `./fastfood`, escolher a opção 4 com a pilha
    vazia e observar a saída; depois encerrar com a opção 0.
-   Resultado observado: foi apresentada a mensagem
    `Historico de pedidos vazio!`, sem o título duplicado. O programa
    retornou ao menu e encerrou normalmente após a opção 0.
-   Conclusão: o caso testado confirmou a correção da saída para a pilha
    vazia.

Iteração 18 --- Segundo commit e envio da correção

-   Data: 10/11/2026.
-   Objetivo: registrar a correção de exibição no histórico do
    repositório.
-   Pedido à IA --- reconstrução: orientar a conferência da alteração em
    `main.c` e o registro de um novo commit.
-   Commit registrado: `3433f50` ---
    `Ajusta exibicao do historico de pedidos`.
-   Link: https://github.com/Extracoffe/EP-Algoritmos/commit/3433f50
-   Resultado: o commit foi enviado com sucesso para a branch `main`.

## 5. ORGANIZAÇÃO TÉCNICA DOS ARQUIVOS

| Arquivo | Responsabilidade |
|---|---|
| `pedidos.h` | Declara a estrutura `Pedido`, compartilhada pelos módulos. |
| `fila.h` | Declara a estrutura da fila e os protótipos de suas funções. |
| `fila.c` | Implementa a fila encadeada de pedidos aguardando preparo. |
| `pilha.h` | Declara a estrutura da pilha e os protótipos de suas funções. |
| `pilha.c` | Implementa a pilha encadeada de pedidos preparados disponíveis para recuperação. |
| `main.c` | Contém o menu, a leitura dos dados e a integração das operações. |

Os arquivos `.h` reúnem declarações compartilhadas, como estruturas e
protótipos de funções. Os arquivos `.c` contêm as implementações. O
`main.c` integra os módulos e realiza a interação com a pessoa usuária.
Essa separação evita concentrar todas as responsabilidades em um único
arquivo.

Funções da fila: `inicializarFila`, `filaVazia`, `adicionarPedido`,
`removerPedido`, `mostrarFila`, `liberarFila` e `inserirInicio`.

Funções da pilha: `inicializarPilha`, `pilhaVazia`, `empilhar`,
`desempilhar`, `mostrarPilha` e `liberarPilha`.

Funções de entrada: `lerTexto`, `lerInteiroPositivo` e
`lerPrecoPositivo`.

## 6. COMPILAÇÃO E EXECUÇÃO

Dentro da pasta `backend`, a compilação conjunta é realizada com:

``` bash
gcc -Wall -Wextra -std=c11 main.c fila.c pilha.c -o fastfood
```

Para executar o programa:

``` bash
./fastfood
```

Os parâmetros `-Wall` e `-Wextra` habilitam avisos adicionais do
compilador, enquanto `-std=c11` define o padrão da linguagem C
utilizado.

## 7. REGISTRO CONSOLIDADO DOS TESTES

Os testes descritos nesta seção foram realizados manualmente durante o desenvolvimento do backend, nos dias 08/11/2026, 09/11/2026 e 10/11/2026, conforme as etapas registradas no diário. Os testes relacionados à correção do histórico foram realizados após a alteração correspondente no código. Os resultados apresentados refletem o comportamento observado durante essas execuções, não uma bateria de testes automatizados.

| Teste | Procedimento | Resultado observado |
|---|---|---|
| Compilação isolada da fila | Compilar `fila.c` com `-Wall -Wextra -std=c11 -c` | Arquivo `fila.o` criado. |
| Compilação isolada da pilha | Compilar `pilha.c` com `-Wall -Wextra -std=c11 -c` | Arquivo `pilha.o` criado. |
| Compilação integrada | Compilar `main.c`, `fila.c` e `pilha.c` juntos | Compilação relatada sem erros ou avisos. |
| Entrada inválida no menu | Digitar `abc` | Entrada rejeitada. |
| Consulta de fila vazia | Selecionar a consulta sem pedidos | `Fila vazia!`. |
| Consulta de pilha vazia | Consultar sem pedidos disponíveis para recuperação | `Historico de pedidos vazio!`. |
| Preparação sem pedidos | Tentar preparar com fila vazia | `Nao existem pedidos na fila!`. |
| Recuperação sem pedidos | Tentar recuperar com pilha vazia | `Pilha vazia!`. |
| Quantidade decimal | Informar quantidade com casas decimais | Valor rejeitado; quantidade exige inteiro. |
| Cadastro válido | Tina, hot dog, quantidade 2, preço unitário `20.2` | Cadastro aceito e preço exibido como `R$ 20.20`. |
| Preparação | Preparar um pedido cadastrado | Pedido removido da fila e empilhado. |
| Recuperação | Recuperar o último pedido preparado | Pedido desempilhado e inserido no início da fila. |
| FIFO/LIFO com três pedidos | Cadastrar 1, 2 e 3; preparar 1 e 2 | Fila mantém 3; pilha apresenta 2 antes de 1. |
| Prioridade da recuperação | Recuperar o pedido 2 do cenário anterior | Fila passa a apresentar 2 antes de 3; pilha mantém 1. |
| Correção do título | Consultar opção 4 com pilha vazia | Mensagem de pilha vazia sem título duplicado. |
| Encerramento | Selecionar opção 0 | Programa encerra normalmente. |

### 7.1 Testes não realizados

Não há registro de testes automatizados, testes de desempenho, análise
com Valgrind ou testes que provoquem deliberadamente falha de alocação
de memória. Embora o código possua tratamento previsto para falha
durante a transferência entre estruturas, esse cenário não foi forçado
em teste. Esses limites são registrados para diferenciar o comportamento
implementado do comportamento efetivamente verificado.

## 8. DECISÕES, PROBLEMAS ENCONTRADOS E CORREÇÕES

### 8.1 Separação de responsabilidades

Questão: como organizar o backend para não concentrar fila, pilha, dados
e menu em um único arquivo? Decisão: separar os cabeçalhos e
implementações de fila e pilha, manter a estrutura `Pedido` em cabeçalho
próprio e utilizar `main.c` para integração.

### 8.2 Garantia das regras FIFO e LIFO

Questão: como demonstrar que as estruturas realmente determinam o
funcionamento? Decisão: inserir pedidos novos no final e remover do
início da fila; inserir e remover pedidos preparados pelo topo da pilha.
O teste com três pedidos confirmou a ordem observada.

### 8.3 Recuperação de pedido

Questão: como fazer com que o pedido recuperado seja preparado antes dos
que já aguardavam? Decisão: desempilhar o pedido mais recente e usar
`inserirInicio` na fila. O cadastro normal continua usando
`adicionarPedido`, que insere no final.

### 8.4 Entradas inválidas

Questão: como impedir que texto seja aceito como número ou que a
quantidade seja fracionária? Decisão: utilizar funções de leitura e
validação específicas, incluindo `lerTexto`, `lerInteiroPositivo` e
`lerPrecoPositivo`. Os testes com `abc` no menu e quantidade decimal
foram rejeitados.

### 8.5 Título duplicado na consulta do histórico

Problema: tanto o `case 4` do menu quanto `mostrarPilha` imprimiam o
título. Correção: retirar o `printf` redundante do `case 4`, mantendo a
chamada `mostrarPilha(&historicoPedidos);`. Verificação: executar a
opção 4 com a pilha vazia e confirmar a mensagem sem duplicação.

### 8.6 Sincronização do repositório

Situação: a branch local estava atrás da versão remota do repositório
compartilhado. Ação: executar `git fetch origin` e
`git pull --ff-only origin main`. Cuidado adotado: preservar os arquivos
locais não rastreados (`fastfood`, `fila.o` e `pilha.o`), sem executar
uma limpeza geral que pudesse removê-los.

## 9. PARTICIPAÇÃO DA ESTUDANTE E USO DA IA

A IA foi utilizada como ferramenta de apoio, não como substituta da
verificação do programa. As interações recuperáveis envolveram:

-   compreensão e delimitação da atividade;
-   escolha e justificativa do problema;
-   definição das responsabilidades de fila e pilha;
-   planejamento da divisão em arquivos;
-   orientação para implementação incremental;
-   compilação isolada e integrada dos módulos;
-   validação de entradas;
-   elaboração e interpretação de testes;
-   análise da saída duplicada do histórico;
-   orientação para commits e sincronização do repositório.

A estudante participou das decisões, executou os comandos no ambiente
local, forneceu entradas ao programa, observou as saídas, relatou os
resultados e verificou a correção da duplicação. A compreensão
individual do código permanece essencial para a apresentação e para
responder às perguntas do professor.

## 10. REGISTRO DE SOLICITAÇÕES À IA POR ASSUNTO

Esta seção consolida os principais pedidos que aparecem ao longo das
iterações. São reconstruções temáticas dos prompts, não transcrições
literais. Foram incluídas para deixar explícitos os objetivos das
interações e facilitar a conferência com a conversa original, disponível
no link registrado na seção 1.2.

1. Interpretação do EP: solicitação de ajuda para entender a atividade
    de pilhas e filas, seus entregáveis e a necessidade de demonstrar as
    estruturas em uma aplicação funcional.

2. Definição do problema: solicitação de orientação para estruturar um
    sistema de gerenciamento de pedidos de fast-food.

3. Escolha das estruturas: solicitação de análise de como aplicar fila
    FIFO aos pedidos aguardando e pilha LIFO aos pedidos preparados que
    podem ser recuperados.

4. Arquitetura do backend: solicitação de organização dos arquivos C e
    cabeçalhos para separar dados, fila, pilha e menu.

5. Estrutura do pedido: solicitação de definição dos campos necessários
    para representar um pedido.

6. Implementação da fila: solicitação de implementação de lista
    encadeada com inicialização, inserção, remoção, consulta e liberação
    de memória.

7. Implementação da pilha: solicitação de implementação de lista
    encadeada com empilhamento, desempilhamento, consulta e liberação de
    memória.

8. Integração: solicitação de conexão dos módulos por meio de um menu
    interativo.

9. Compilação: solicitação de orientação para compilar todos os
    arquivos `.c` com GCC e interpretar o resultado.

10. Validação: solicitação de revisão da entrada de texto, números,
    quantidade e preço.

11. Testes de borda: solicitação de cenários para fila vazia, pilha
    vazia, preparação e recuperação sem elementos.

12. Teste FIFO/LIFO: solicitação de um cenário com três pedidos para
    observar a ordem das estruturas.

13. GitHub: solicitação de orientação para conferir arquivos e registrar
    commits sem incluir executáveis ou objetos de compilação.

14. Sincronização: solicitação de orientação para atualizar a branch
    local preservando arquivos não rastreados.

15. Correção visual: solicitação de análise do título duplicado e
    indicação da menor alteração no `main.c`.

16. Verificação final: solicitação de confirmação do comportamento após
    a correção e do registro do novo commit.


## 11. LIMITES E DECLARAÇÃO DE FIDELIDADE

Este documento registra as etapas e os fatos que puderam ser recuperados
sobre o desenvolvimento do backend. Não afirma que houve testes ou
procedimentos que não foram relatados. Em particular, não afirma a
realização de Valgrind, testes automatizados, testes de desempenho ou
simulação de falha de alocação.

Os prompts e as respostas apresentados neste diário são sínteses e
reconstruções temáticas, não transcrições literais. A conversa original
com a IA está indicada na seção 1.2 para consulta integral. A
acessibilidade do link deve ser conferida antes da entrega; se o
professor não conseguir visualizar a conversa pelo compartilhamento,
será necessário disponibilizar uma exportação ou outro acesso válido.
Caso o grupo tenha utilizado outras ferramentas ou contas, os
respectivos históricos devem ser acrescentados pelos integrantes
responsáveis.

A documentação procura demonstrar não apenas o resultado final, mas
também a sequência de planejamento, implementação, verificação,
identificação de problema, correção e registro de versões que levou ao
backend atual.
