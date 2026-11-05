#ifndef LIVRO_H
#define LIVRO_H

//dados armazenados livro
typedef struct {
    int id;
    char titulo[80];
    char autor[80];
    int ano_publicacao;
} Livro;

#endif