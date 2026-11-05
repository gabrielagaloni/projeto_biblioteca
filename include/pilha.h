#ifndef PILHA_H
#define PILHA_H

typedef struct NoPilha {
    int tipoAcao;
    int id1;
    int id2;
    struct NoPilha *proximo;
} NoPilha;

typedef struct {
    NoPilha *topo;
} Pilha;

void inicializarPilha(Pilha *pilha);
int empilhar(Pilha *pilha, int tipoAcao, int id1, int id2);
int desempilhar(Pilha *pilha);
int consultarTopo(const Pilha *pilha);
void exibirHistorico(const Pilha *pilha);
void liberarPilha(Pilha *pilha);

#endif