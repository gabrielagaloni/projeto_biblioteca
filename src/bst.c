
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Inicializa a arvore vazia
void inicializarArvore(Arvore *arvore) {
    arvore->raiz = NULL;
}

// Insere um livro na arvore, sem permitir IDs duplicados
int inserirLivro(Arvore *arvore, Livro livro) {
    NoArvore **atual = &arvore->raiz;

    while (*atual != NULL) {
        if (livro.id == (*atual)->livro.id) {
            return 0;
        }

        if (livro.id < (*atual)->livro.id) {
            atual = &(*atual)->esquerda;
        } else {
            atual = &(*atual)->direita;
        }
    }

    NoArvore *novo = malloc(sizeof(NoArvore));

    if (novo == NULL) {
        return 0;
    }

    novo->livro = livro;
    novo->esquerda = NULL;
    novo->direita = NULL;

    *atual = novo;

    return 1;
}

// Busca um livro pelo ID
NoArvore *buscarLivro(const Arvore *arvore, int id) {
    NoArvore *atual = arvore->raiz;

    while (atual != NULL) {
        if (id == atual->livro.id) {
            return atual;
        }

        if (id < atual->livro.id) {
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
    }

    return NULL;
}

// Encontra o menor no de uma subarvore
static NoArvore *menorNo(NoArvore *no) {
    while (no->esquerda != NULL) {
        no = no->esquerda;
    }

    return no;
}

// Remove um no da arvore
static NoArvore *removerNo(NoArvore *raiz, int id, int *removido) {
    if (raiz == NULL) {
        return NULL;
    }

    if (id < raiz->livro.id) {
        raiz->esquerda = removerNo(raiz->esquerda, id, removido);
    } else if (id > raiz->livro.id) {
        raiz->direita = removerNo(raiz->direita, id, removido);
    } else {
        *removido = 1;

        // Caso 1: no sem filho esquerdo
        if (raiz->esquerda == NULL) {
            NoArvore *temporario = raiz->direita;
            free(raiz);
            return temporario;
        }

        // Caso 2: no sem filho direito
        if (raiz->direita == NULL) {
            NoArvore *temporario = raiz->esquerda;
            free(raiz);
            return temporario;
        }

        // Caso 3: no com dois filhos
        NoArvore *sucessor = menorNo(raiz->direita);

        raiz->livro = sucessor->livro;

        int ignorado = 0;

        raiz->direita = removerNo(
            raiz->direita,
            sucessor->livro.id,
            &ignorado
        );
    }

    return raiz;
}

// Funcao principal de remocao
int removerLivro(Arvore *arvore, int id) {
    int removido = 0;

    arvore->raiz = removerNo(arvore->raiz, id, &removido);

    return removido;
}

// Percorre a arvore em ordem
static void percorrerEmOrdem(const NoArvore *raiz) {
    if (raiz == NULL) {
        return;
    }

    percorrerEmOrdem(raiz->esquerda);

    printf("ID: %d | Titulo: %s | Autor: %s | Ano: %d\n",
           raiz->livro.id,
           raiz->livro.titulo,
           raiz->livro.autor,
           raiz->livro.ano_publicacao);

    percorrerEmOrdem(raiz->direita);
}

// Exibe os livros em ordem crescente de ID
void listarEmOrdem(const NoArvore *raiz) {
    if (raiz == NULL) {
        printf("Nenhum livro cadastrado na BST.\n");
        return;
    }

    percorrerEmOrdem(raiz);
}

// Libera a memoria da arvore
void liberarArvore(NoArvore *raiz) {
    if (raiz == NULL) {
        return;
    }

    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);

    free(raiz);
}