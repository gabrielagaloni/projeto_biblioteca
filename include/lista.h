#ifndef LISTA_H
#define LISTA_H

typedef struct NoLista { //elementos lista  
    int id; //identificador livro
    struct NoLista *proximo;
} NoLista;

typedef struct {
    NoLista *inicio;
    NoLista *fim;
} Lista;

void inicializarLista(Lista *lista);
void inserirFinal(Lista *lista, int id);
void exibirLista(const Lista *lista);
void liberarLista(Lista *lista);

#endif