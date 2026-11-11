
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Inicializa a pilha vazia
void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

// Insere um novo ID no topo da pilha
int empilhar(Pilha *pilha, int id) {
    NoPilha *novo = malloc(sizeof(NoPilha));

    if (novo == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return 0;
    }

    novo->id = id;
    novo->proximo = pilha->topo;

    pilha->topo = novo;

    return 1;
}

// Remove o elemento do topo da pilha
int desempilhar(Pilha *pilha) {
    if (pilha->topo == NULL) {
        return 0;
    }

    NoPilha *temporario = pilha->topo;

    pilha->topo = temporario->proximo;

    free(temporario);

    return 1;
}

// Exibe os IDs do topo para a base
void exibirPilha(const Pilha *pilha) {
    NoPilha *atual = pilha->topo;

    if (atual == NULL) {
        printf("A pilha esta vazia.\n");
        return;
    }

    while (atual != NULL) {
        printf("%d\n", atual->id);
        atual = atual->proximo;
    }
}

// Libera toda a memoria utilizada pela pilha
void liberarPilha(Pilha *pilha) {
    while (pilha->topo != NULL) {
        NoPilha *temporario = pilha->topo;

        pilha->topo = temporario->proximo;

        free(temporario);
    }
}