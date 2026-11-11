
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Inicializa a lista vazia
void inicializarLista(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

// Insere um novo ID no final da lista
void inserirFinal(Lista *lista, int id) {
    NoLista *novo = malloc(sizeof(NoLista));

    if (novo == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return;
    }

    novo->id = id;
    novo->proximo = NULL;

    // Verifica se a lista está vazia
    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        lista->fim->proximo = novo;
    }

    lista->fim = novo;
}

// Remove o primeiro elemento da lista
int removerInicio(Lista *lista) {

    // Verifica se a lista está vazia
    if (lista->inicio == NULL) {
        return 0;
    }

    NoLista *temporario = lista->inicio;

    lista->inicio = lista->inicio->proximo;

    // Se não restar nenhum elemento, atualiza o fim
    if (lista->inicio == NULL) {
        lista->fim = NULL;
    }

    free(temporario);

    return 1;
}

// Exibe todos os IDs da lista
void exibirLista(const Lista *lista) {
    NoLista *atual = lista->inicio;

    if (atual == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    while (atual != NULL) {
        printf("%d ", atual->id);
        atual = atual->proximo;
    }

    printf("\n");
}

// Libera a memória utilizada pela lista
void liberarLista(Lista *lista) {
    NoLista *atual = lista->inicio;

    while (atual != NULL) {
        NoLista *temporario = atual;
        atual = atual->proximo;
        free(temporario);
    }

    lista->inicio = NULL;
    lista->fim = NULL;
}
