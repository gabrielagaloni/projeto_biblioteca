
#ifndef FILA_H
#define FILA_H

// Estrutura de cada elemento da fila
typedef struct NoFila {
    int id;
    struct NoFila *proximo;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
} Fila;

// Funções da fila
void inicializarFila(Fila *fila);
int enfileirar(Fila *fila, int id);
int desenfileirar(Fila *fila, int *id);
int filaVazia(const Fila *fila);
void exibirFila(const Fila *fila);
void liberarFila(Fila *fila);

#endif
