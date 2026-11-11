//armazenagem dos livros
#ifndef BST_H
#define BST_H

#include "livro.h"

typedef struct NoArvore {
    Livro livro; // guardar dados livros
    struct NoArvore *esquerda; //id menor na esquerda
    struct NoArvore *direita; //id maior na direita 
} NoArvore;

typedef struct {
    NoArvore *raiz; 
} Arvore;

void inicializarArvore(Arvore *arvore);
int inserirLivro(Arvore *arvore, Livro livro);
NoArvore *buscarLivro(const Arvore *arvore, int id);
int removerLivro(Arvore *arvore, int id);
void listarEmOrdem(const NoArvore *raiz);
void liberarArvore(NoArvore *raiz);

#endif