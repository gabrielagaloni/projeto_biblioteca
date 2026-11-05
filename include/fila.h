#ifndef FILA_H
#define FILA_H

//FIFO
typedef struct NoFila { //cada elemento fila
    int id;
    struct NoFila *proximo;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
} Fila;

void inicializarFila(Fila *fila);
int enfileirar(Fila *fila, int id);
int desenfileirar(Fila *fila, int *id);
int filaVazia(const Fila *fila);
void liberarFila(Fila *fila);

#endif