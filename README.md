# Projeto Prático – Estrutura de Dados: Biblioteca

**Instituição:** FATEC Ribeirão Preto  
**Curso:** Análise e Desenvolvimento de Sistemas – 3º semestre  
**Disciplina:** Estrutura de Dados  
**Linguagem:** C11

## 1. Objetivo

Desenvolver um sistema em C para cadastrar e gerenciar livros utilizando uma Árvore Binária de Busca (BST) e estruturas lineares dinâmicas.

Cada livro possui ID, título, autor e ano de publicação.

## 2. Estruturas de dados

**BST:** permite cadastrar, buscar, remover e listar livros em ordem crescente de ID. Não permite IDs duplicados.

**Estruturas lineares:**
- Lista encadeada: insere no final e remove do início.
- Pilha: insere e remove pelo topo.
- Fila: insere no final e remove do início.

As estruturas armazenam IDs positivos e permitem repetições, independentemente dos livros cadastrados.

## 3. Organização dos arquivos

```text
projeto-biblioteca/
├── include/
├── src/
├── tests/
│   └── resultados.md
└── README.md
```

## 4. Tecnologias

- Linguagem C11;
- GCC;
- Visual Studio Code;
- Windows;
- Git e GitHub.

## 5. Como compilar e executar

No terminal, dentro da pasta do projeto, execute:

**Compilar:**

```bash
gcc -Wall -Wextra -std=c11 -Iinclude src/main.c src/bst.c src/lista.c src/pilha.c src/fila.c -o biblioteca.exe
```

**Executar no PowerShell:**

```powershell
.\biblioteca.exe
```

## 6. Testes

Foram realizados testes de cadastro, busca, remoção e listagem da BST; validação de IDs e anos; operações com lista, pilha e fila; IDs repetidos; estruturas vazias e encerramento do programa.

Os procedimentos, entradas utilizadas e resultados esperados e obtidos estão registrados em `tests/resultados.md`.

Para reproduzir os testes, compile e execute o programa conforme a seção 5 e siga os procedimentos registrados no arquivo.

## 7. Gerenciamento de memória

O programa utiliza alocação dinâmica e possui funções para liberar a memória utilizada pelas estruturas ao encerrar.

## 8. Considerações finais

O projeto aplica conceitos de structs, ponteiros, funções, alocação dinâmica, BST, lista encadeada, pilha e fila.