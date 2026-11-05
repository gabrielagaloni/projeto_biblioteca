#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

int empilhar(Pilha *pilha, int tipoAcao, int id1, int id2) {
    NoPilha *novo = malloc(sizeof(NoPilha));

    if (novo == NULL) {
        return 0;
    }

    novo->tipoAcao = tipoAcao;
    novo->id1 = id1;
    novo->id2 = id2;
    novo->proximo = pilha->topo;

    pilha->topo = novo;

    return 1;
}

int desempilhar(Pilha *pilha) {
    if (pilha->topo == NULL) {
        return 0;
    }

    NoPilha *temporario = pilha->topo;
    pilha->topo = temporario->proximo;

    free(temporario);

    return 1;
}

int consultarTopo(const Pilha *pilha) {
    if (pilha->topo == NULL) {
        return -1;
    }

    return pilha->topo->tipoAcao;
}

void exibirHistorico(const Pilha *pilha) {
    NoPilha *atual = pilha->topo;
    int quantidade = 0;

    while (atual != NULL && quantidade < 5) {
        printf("Acao: %d | ID 1: %d | ID 2: %d\n",
               atual->tipoAcao, atual->id1, atual->id2);

        atual = atual->proximo;
        quantidade++;
    }
}

void liberarPilha(Pilha *pilha) {
    while (pilha->topo != NULL) {
        NoPilha *temporario = pilha->topo;
        pilha->topo = temporario->proximo;
        free(temporario);
    }
}