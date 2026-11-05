#include <stdlib.h>
#include "fila.h"

void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int enfileirar(Fila *fila, int id) { //id final
    NoFila *novo = malloc(sizeof(NoFila));

    if (novo == NULL) {
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

int desenfileirar(Fila *fila, int *id) { //retira primeiro id
    if (fila->inicio == NULL) {
        return 0;
    }

    NoFila *temporario = fila->inicio;

    *id = temporario->id;
    fila->inicio = temporario->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temporario);
    return 1;
}

int filaVazia(const Fila *fila) {
    return fila->inicio == NULL;
}

void liberarFila(Fila *fila) {
    int id;

    while (desenfileirar(fila, &id)) { 
    }
}