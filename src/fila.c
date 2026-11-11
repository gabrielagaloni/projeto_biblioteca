
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int enfileirar(Fila *fila, int id) {
    NoFila *novo = malloc(sizeof(NoFila));

    if (novo == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return 0;
    }

    novo->id = id;
    novo->proximo = NULL;

    if (fila->fim == NULL) {
        fila->inicio = novo;
    } else {
        fila->fim->proximo = novo;
    }

    fila->fim = novo;

    return 1;
}

int desenfileirar(Fila *fila, int *id) {
    if (fila->inicio == NULL) {
        return 0;
    }

    NoFila *temporario = fila->inicio;

    *id = temporario->id;
    fila->inicio = temporario->proximo;

    // Se a fila ficar vazia, atualiza o fim
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temporario);

    return 1;
}

int filaVazia(const Fila *fila) {
    return fila->inicio == NULL;
}

void exibirFila(const Fila *fila) {
    NoFila *atual = fila->inicio;

    if (atual == NULL) {
        printf("A fila esta vazia.\n");
        return;
    }

    while (atual != NULL) {
        printf("%d ", atual->id);
        atual = atual->proximo;
    }

    printf("\n");
}

void liberarFila(Fila *fila) {
    int id;

    while (desenfileirar(fila, &id)) {
        // Continua removendo ate a fila ficar vazia
    }
}
