const express = require('express');
const path = require('path');

const app = express();
const PORT = 3000;

app.use(express.json());
app.use(express.static(path.join(__dirname, 'public')));

// Simulação das estruturas de dados (mesma lógica do seu código em C)
let filaPedidos = [];
let historicoPedidos = [];
let proximoId = 1;

// Rota para pegar os pedidos da fila
app.get('/api/pedidos', (req, res) => {
    res.json(filaPedidos);
});

// Rota para cadastrar um novo pedido (equivalente à Opção 1 em C)
app.post('/api/pedidos', (req, res) => {
    const { cliente, produto, quantidade, preco } = req.body;
    
    const novoPedido = {
        id: proximoId++,
        cliente,
        produto,
        quantidade: parseInt(quantidade),
        preco: parseFloat(preco)
    };

    filaPedidos.push(novoPedido); // Enfileirar (Enqueue)
    res.status(201).json({ mensagem: 'Pedido cadastrado com sucesso!', pedido: novoPedido });
});

// Rota para preparar o próximo pedido (equivalente à Opção 3 em C)
app.post('/api/preparar', (req, res) => {
    if (filaPedidos.length === 0) {
        return res.status(400).json({ erro: 'Fila vazia!' });
    }

    const pedidoProcessado = filaPedidos.shift(); // Remove do início da fila (Dequeue)
    historicoPedidos.unshift(pedidoProcessado);   // Adiciona ao histórico (Pilha/LIFO)

    res.json({ mensagem: 'Pedido preparado com sucesso!', pedido: pedidoProcessado });
});

// Rota para consultar o histórico (equivalente à Opção 4 em C)
app.get('/api/historico', (req, res) => {
    res.json(historicoPedidos);
});

app.listen(PORT, () => {
    console.log(`Servidor rodando! Acesse: http://localhost:${PORT}`);
});