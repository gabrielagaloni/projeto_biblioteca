#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void inicializarArvore(Arvore *arvore) {
    arvore->raiz = NULL;
}

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

static NoArvore *menorNo(NoArvore *no) {
    while (no->esquerda != NULL) {
        no = no->esquerda;
    }

    return no;
}

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

        if (raiz->esquerda == NULL) {
            NoArvore *temporario = raiz->direita;
            free(raiz);
            return temporario;
        }

        if (raiz->direita == NULL) {
            NoArvore *temporario = raiz->esquerda;
            free(raiz);
            return temporario;
        }

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

int removerLivro(Arvore *arvore, int id) {
    int removido = 0;

    arvore->raiz = removerNo(arvore->raiz, id, &removido);

    return removido;
}

void listarEmOrdem(const NoArvore *raiz) {
    if (raiz == NULL) {
        return;
    }

    listarEmOrdem(raiz->esquerda);

    printf("ID: %d | Titulo: %s | Autor: %s | Ano: %d\n",
           raiz->livro.id,
           raiz->livro.titulo,
           raiz->livro.autor,
           raiz->livro.ano_publicacao);

    listarEmOrdem(raiz->direita);
}

void liberarArvore(NoArvore *raiz) {
    if (raiz == NULL) {
        return;
    }

    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);

    free(raiz);
}