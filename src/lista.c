#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializarLista(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

void inserirFinal(Lista *lista, int id) {
    NoLista *novo = malloc(sizeof(NoLista));

    if (novo == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return;
    }

    novo->id = id;
    novo->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        lista->fim->proximo = novo;
    }

    lista->fim = novo;
}

void exibirLista(const Lista *lista) {
    NoLista *atual = lista->inicio;

    while (atual != NULL) {
        printf("%d ", atual->id);
        atual = atual->proximo;
    }

    printf("\n");
}

void liberarLista(Lista *lista) {
    NoLista *atual = lista->inicio;

    while (atual != NULL) {
        NoLista *temporario = atual;
        atual = atual->proximo;
        free(temporario);
    }

    lista->inicio = NULL;
    lista->fim = NULL;
}