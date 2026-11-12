# Resultados dos Testes – Projeto Biblioteca

Este documento registra os testes funcionais realizados no Sistema de Estrutura de Dados – Biblioteca.

## 1. Testes da Árvore Binária de Busca (BST)

| Teste | Procedimento | Resultado obtido |
|---|---|---|
| Cadastro | Cadastrar livros com IDs 30, 10 e 20 | Cadastros realizados com sucesso |
| Busca existente | Buscar ID 20 | Livro encontrado e dados exibidos |
| Busca inexistente | Buscar ID 99 | Registro não encontrado |
| ID duplicado | Cadastrar novamente o ID 20 | Cadastro rejeitado |
| Listagem em ordem | Listar os livros cadastrados | IDs exibidos em ordem crescente |
| Remoção de folha | Remover um nó sem filhos | Registro removido corretamente |
| Remoção de um filho | Remover um nó com apenas um filho | Árvore reorganizada corretamente |
| Remoção de dois filhos | Remover ID 30, com dois filhos | Árvore reorganizada corretamente, mantendo os demais registros |

## 2. Testes das estruturas lineares

### Lista encadeada

| Teste | Procedimento | Resultado obtido |
|---|---|---|
| Inserção | Inserir IDs 10, 20 e 30 | Exibidos na ordem 10, 20 e 30 |
| Remoção | Remover o primeiro elemento | ID 10 removido corretamente |
| Estrutura vazia | Tentar remover com a lista vazia | Sistema informou que a lista estava vazia |

### Pilha

| Teste | Procedimento | Resultado obtido |
|---|---|---|
| Inserção | Inserir IDs 10, 20 e 30 | Exibidos do topo à base: 30, 20 e 10 |
| Remoção | Remover o elemento do topo | ID 30 removido corretamente |
| Estrutura vazia | Tentar remover com a pilha vazia | Sistema informou que a pilha estava vazia |

### Fila

| Teste | Procedimento | Resultado obtido |
|---|---|---|
| Inserção | Inserir IDs 10, 20 e 30 | Exibidos na ordem 10, 20 e 30 |
| Remoção | Remover o primeiro elemento | ID 10 removido corretamente |
| Estrutura vazia | Tentar remover com a fila vazia | Sistema informou que a fila estava vazia |

## 3. Testes de validação

| Teste | Procedimento | Resultado obtido |
|---|---|---|
| ID zero | Informar ID 0 | Entrada rejeitada |
| ID negativo | Informar um ID negativo | Entrada rejeitada |
| ID textual | Informar texto no campo ID | Entrada rejeitada |
| Ano inválido | Informar ano fora do intervalo de 1 a 2026 | Entrada rejeitada |
| Texto vazio | Informar campo textual vazio | Entrada rejeitada |
| Texto com espaços | Informar campo contendo apenas espaços | Entrada rejeitada |
| ID repetido nas estruturas lineares | Inserir IDs repetidos | Repetição permitida |

## 4. Testes do menu e encerramento

| Teste | Procedimento | Resultado obtido |
|---|---|---|
| Opção inválida | Informar opção 9 no menu principal | Sistema informou que o valor era inválido |
| Encerramento | Selecionar a opção 0 | Programa encerrou corretamente |
| Liberação de memória | Encerrar o programa após utilizar as estruturas | Rotinas de liberação executadas no encerramento |

## 5. Conclusão dos testes

Os testes funcionais realizados verificaram as operações de cadastro, busca, remoção e listagem da BST, além das operações de inserção, remoção e exibição das estruturas lineares.
Também foram verificadas as validações de entrada, o tratamento de estruturas vazias e o encerramento do programa.