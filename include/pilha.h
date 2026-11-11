
#ifndef PILHA_H
#define PILHA_H

// Estrutura de cada elemento da pilha
typedef struct NoPilha {
    int id;
    struct NoPilha *proximo;
} NoPilha;

// Estrutura principal da pilha
typedef struct {
    NoPilha *topo;
} Pilha;

// Funções da pilha
void inicializarPilha(Pilha *pilha);
int empilhar(Pilha *pilha, int id);
int desempilhar(Pilha *pilha);
void exibirPilha(const Pilha *pilha);
void liberarPilha(Pilha *pilha);

#endif