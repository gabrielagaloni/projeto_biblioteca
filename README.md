# Projeto Prático – Estrutura de Dados: Biblioteca

**Instituição:** FATEC Ribeirão Preto  
**Curso:** Análise e Desenvolvimento de Sistemas – 3º semestre  
**Disciplina:** Estrutura de Dados  
**Linguagem:** C11  
**Tema:** Biblioteca

## 1. Objetivo

Desenvolver um programa de terminal em linguagem C para cadastrar e gerenciar registros de livros utilizando uma Árvore Binária de Busca (BST) e estruturas de dados lineares dinâmicas.

Cada livro possui os seguintes campos:
- ID: identificador inteiro positivo e único;
- Título;
- Autor;
- Ano de publicação, entre 1 e 2026.

## 2. Estruturas de dados

### Árvore Binária de Busca (BST)

A BST armazena os livros organizados pelo ID. O sistema permite:
- Cadastrar livros;
- Buscar livros pelo ID;
- Remover livros, considerando os casos de zero, um ou dois filhos;
- Listar os livros em ordem crescente de ID.

IDs duplicados e inválidos são rejeitados.

### Estruturas lineares

O projeto implementa três estruturas lineares dinâmicas:

- **Lista encadeada:** inserção no final, remoção no início e exibição do início ao fim.
- **Pilha:** inserção no topo, remoção do topo e exibição do topo à base.
- **Fila:** inserção no final, remoção do início e exibição do início ao fim.

As estruturas armazenam IDs inteiros positivos, independentemente dos registros cadastrados na BST. IDs repetidos são permitidos nessas estruturas.

## 3. Organização dos arquivos

```text
projeto-biblioteca/
│
├── include/
│   ├── livro.h
│   ├── bst.h
│   ├── lista.h
│   ├── pilha.h
│   └── fila.h
│
├── src/
│   ├── main.c
│   ├── bst.c
│   ├── lista.c
│   ├── pilha.c
│   └── fila.c
│
└── README.md
```

## 4. Tecnologias e ambiente

- Linguagem C11;
- Compilador GCC;
- Visual Studio Code;
- Sistema operacional Windows;
- Git e GitHub para versionamento.

## 5. Como compilar e executar

Abra o terminal na pasta principal do projeto.

**Compilação:**

```bash
gcc -Wall -Wextra -std=c11 -Iinclude src/main.c src/bst.c src/lista.c src/pilha.c src/fila.c -o biblioteca.exe
```

**Execução no Windows (PowerShell):**

```powershell
.\biblioteca.exe
```

## 6. Como reproduzir os testes

Os testes devem ser realizados seguindo os passos abaixo e comparando os resultados obtidos com os resultados esperados.

| Teste | Procedimento | Resultado esperado |
|---|---|---|
| Cadastro na BST | Cadastrar livros com IDs diferentes | Livros cadastrados corretamente |
| Busca na BST | Buscar um ID existente | Exibir os dados do livro |
| Busca inexistente | Buscar um ID não cadastrado | Informar que o registro não foi encontrado |
| ID duplicado | Cadastrar novamente um ID existente | Rejeitar o cadastro |
| Remoção de folha | Remover um nó sem filhos | Remover somente o registro escolhido |
| Remoção de um filho | Remover um nó com um filho | Manter os demais registros na BST |
| Remoção de dois filhos | Remover um nó com dois filhos | Manter a organização da BST |
| Listagem | Cadastrar IDs fora de ordem e listar | Exibir os registros em ordem crescente |
| ID inválido | Informar zero, número negativo ou texto | Rejeitar a entrada |
| Ano inválido | Informar ano fora do intervalo de 1 a 2026 | Rejeitar a entrada |
| Lista | Inserir, exibir e remover IDs | Respeitar a ordem de inserção |
| Pilha | Inserir, exibir e remover IDs | Remover primeiro o último inserido |
| Fila | Inserir, exibir e remover IDs | Remover primeiro o primeiro inserido |
| IDs repetidos | Inserir o mesmo ID em uma estrutura linear | Permitir a repetição |
| Estrutura vazia | Tentar remover de uma estrutura vazia | Informar que está vazia e continuar funcionando |
| Encerramento | Encerrar o programa | Liberar a memória alocada |

Os resultados efetivamente obtidos devem ser registrados no relatório técnico ou em arquivos dentro da pasta `tests/`, junto com as entradas e os passos utilizados.

## 7. Gerenciamento de memória

As estruturas utilizam alocação dinâmica de memória. As funções de liberação são responsáveis por desalocar os nós alocados durante a execução do programa ao encerrá-lo.

## 8. Considerações finais

O projeto permite aplicar conceitos de estruturas de dados em linguagem C, incluindo structs, ponteiros, funções, alocação dinâmica de memória, árvores binárias de busca, listas encadeadas, pilhas e filas.