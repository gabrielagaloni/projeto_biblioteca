#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

#include "livro.h"
#include "bst.h"
#include "lista.h"
#include "pilha.h"
#include "fila.h"

/* Le um numero inteiro de forma segura */
int lerInteiro(const char *mensagem, int minimo, int maximo, int *valor) {
    char linha[128];
    char *fim;
    long numero;

    while (1) {
        printf("%s", mensagem);
        fflush(stdout);

        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            return 0;
        }

        if (strchr(linha, '\n') == NULL && !feof(stdin)) {
            int caractere;

            while ((caractere = getchar()) != '\n' && caractere != EOF) {
            }

            printf("Entrada muito longa. Tente novamente.\n");
            continue;
        }

        errno = 0;
        numero = strtol(linha, &fim, 10);

        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        if (fim == linha || *fim != '\0' || errno == ERANGE ||
            numero < minimo || numero > maximo) {
            printf("Valor invalido. Tente novamente.\n");
            continue;
        }

        *valor = (int)numero;
        return 1;
    }
}

/* Le uma opcao do menu reutilizando a funcao lerInteiro */
int lerOpcaoMenu(int *opcao) {
    if (!lerInteiro("Escolha uma opcao: ", 0, 7, opcao)) {
        return -1; // EOF / Fim do arquivo
    }
    return 1;
}

/* Le um texto */
int lerTexto(const char *mensagem, char texto[80]) {
    char linha[128];
    size_t inicio;
    size_t fim;
    size_t tamanho;

    while (1) {
        printf("%s", mensagem);
        fflush(stdout);

        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            return 0;
        }

        if (strchr(linha, '\n') == NULL && !feof(stdin)) {
            int caractere;

            while ((caractere = getchar()) != '\n' && caractere != EOF) {
            }

            printf("Texto muito longo. Tente novamente.\n");
            continue;
        }

        tamanho = strlen(linha);

        if (tamanho > 0 && linha[tamanho - 1] == '\n') {
            linha[tamanho - 1] = '\0';
        }

        inicio = 0;

        while (isspace((unsigned char)linha[inicio])) {
            inicio++;
        }

        fim = strlen(linha);

        while (fim > inicio &&
               isspace((unsigned char)linha[fim - 1])) {
            fim--;
        }

        tamanho = fim - inicio;

        if (tamanho == 0) {
            printf("O texto nao pode ficar vazio.\n");
            continue;
        }

        if (tamanho > 79) {
            printf("O texto deve ter no maximo 79 caracteres.\n");
            continue;
        }

        memcpy(texto, linha + inicio, tamanho);
        texto[tamanho] = '\0';

        return 1;
    }
}

/* Exibe os dados de um livro */
void exibirLivro(const Livro *livro) {
    printf("\nID: %d\n", livro->id);
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano de publicacao: %d\n", livro->ano_publicacao);
}

/* Cadastra um livro na BST */
void cadastrarLivro(Arvore *arvore) {
    Livro livro;

    printf("\n--- CADASTRAR REGISTRO NA BST ---\n");

    if (!lerInteiro("Digite o ID: ", 1, INT_MAX, &livro.id)) {
        return;
    }

    if (!lerTexto("Digite o titulo: ", livro.titulo)) {
        return;
    }

    if (!lerTexto("Digite o autor: ", livro.autor)) {
        return;
    }

    if (!lerInteiro("Digite o ano de publicacao: ",
                    1, 2026, &livro.ano_publicacao)) {
        return;
    }

    if (inserirLivro(arvore, livro)) {
        printf("\nLivro cadastrado com sucesso!\n");
    } else {
        printf("\nNao foi possivel cadastrar o livro. Verifique se o ID ja existe ou se ha memoria disponivel.\n");
    }
}

/* Busca um livro pelo ID */
void consultarLivro(const Arvore *arvore) {
    int id;
    NoArvore *resultado;

    printf("\n--- BUSCAR REGISTRO NA BST ---\n");

    if (!lerInteiro("Digite o ID para buscar: ", 1, INT_MAX, &id)) {
        return;
    }

    resultado = buscarLivro(arvore, id);

    if (resultado != NULL) {
        printf("\nRegistro encontrado:\n");
        exibirLivro(&resultado->livro);
    } else {
        printf("\nLivro nao encontrado.\n");
    }
}

/* Remove um livro da BST */
void excluirLivro(Arvore *arvore) {
    int id;

    printf("\n--- REMOVER REGISTRO DA BST ---\n");

    if (!lerInteiro("Digite o ID para remover: ", 1, INT_MAX, &id)) {
        return;
    }

    if (removerLivro(arvore, id)) {
        printf("\nLivro removido com sucesso!\n");
    } else {
        printf("\nLivro nao encontrado.\n");
    }
}

/* Menu das estruturas lineares */
void exibirMenuEstruturas(void) {
    printf("\n--- ESTRUTURAS LINEARES ---\n");
    printf("1 - Lista\n");
    printf("2 - Pilha\n");
    printf("3 - Fila\n");
}

/* Escolhe uma estrutura linear */
int escolherEstrutura(void) {
    int escolha;

    exibirMenuEstruturas();

    if (!lerInteiro("Escolha a estrutura: ", 1, 3, &escolha)) {
        return 0;
    }

    return escolha;
}

/* Insere um ID na estrutura escolhida */
void inserirNaEstrutura(Lista *lista, Pilha *pilha, Fila *fila) {
    int estrutura;
    int id;

    estrutura = escolherEstrutura();

    if (estrutura == 0) {
        return;
    }

    if (!lerInteiro("Digite o ID: ", 1, INT_MAX, &id)) {
        return;
    }

    switch (estrutura) {
        case 1:
            inserirFinal(lista, id);
            break;

        case 2:
            if (empilhar(pilha, id)) {
                printf("ID inserido na pilha com sucesso!\n");
            }
            break;

        case 3:
            if (enfileirar(fila, id)) {
                printf("ID inserido na fila com sucesso!\n");
            }
            break;
    }
}

/* Remove um elemento da estrutura escolhida */
void removerDaEstrutura(Lista *lista, Pilha *pilha, Fila *fila) {
    int estrutura;
    int id;

    estrutura = escolherEstrutura();

    if (estrutura == 0) {
        return;
    }

    switch (estrutura) {
        case 1:
            if (removerInicio(lista)) {
                printf("Elemento removido da lista.\n");
            } else {
                printf("A lista esta vazia.\n");
            }
            break;

        case 2:
            if (desempilhar(pilha)) {
                printf("Elemento removido da pilha.\n");
            } else {
                printf("A pilha esta vazia.\n");
            }
            break;

        case 3:
            if (desenfileirar(fila, &id)) {
                printf("ID removido da fila: %d\n", id);
            } else {
                printf("A fila esta vazia.\n");
            }
            break;
    }
}

/* Exibe a estrutura escolhida */
void exibirEstrutura(Lista *lista, Pilha *pilha, Fila *fila) {
    int estrutura;

    estrutura = escolherEstrutura();

    if (estrutura == 0) {
        return;
    }

    printf("\n--- ELEMENTOS DA ESTRUTURA ---\n");

    switch (estrutura) {
        case 1:
            exibirLista(lista);
            break;

        case 2:
            exibirPilha(pilha);
            break;

        case 3:
            exibirFila(fila);
            break;
    }
}

/* Exibe o menu principal */
void exibirMenu(void) {
    printf("\n==========================================\n");
    printf("     SISTEMA DE ESTRUTURA DE DADOS\n");
    printf("==========================================\n");
    printf("1 - Cadastrar registro na BST\n");
    printf("2 - Buscar registro por ID na BST\n");
    printf("3 - Remover registro da BST\n");
    printf("4 - Listar registros em-ordem\n");
    printf("5 - Inserir ID na estrutura linear\n");
    printf("6 - Remover da estrutura linear\n");
    printf("7 - Exibir estrutura linear\n");
    printf("0 - Encerrar\n");
    printf("==========================================\n");
    fflush(stdout);
}

/* Funcao principal */
int main(void) {
    Arvore arvore;
    Lista lista;
    Pilha pilha;
    Fila fila;

    int opcao;
    int leitura;

    inicializarArvore(&arvore);
    inicializarLista(&lista);
    inicializarPilha(&pilha);
    inicializarFila(&fila);

    do {
        exibirMenu();

        leitura = lerOpcaoMenu(&opcao);

        if (leitura == -1) {
            break;
        }

        if (leitura == 0) {
            continue;
        }

        switch (opcao) {
            case 1:
                cadastrarLivro(&arvore);
                break;

            case 2:
                consultarLivro(&arvore);
                break;

            case 3:
                excluirLivro(&arvore);
                break;

            case 4:
                printf("\n--- REGISTROS EM ORDEM ---\n");
                listarEmOrdem(arvore.raiz);
                
                // Pausa adicionada para você conseguir ver o resultado na tela
                printf("\nPressione Enter para continuar...");
                fflush(stdout);
                {
                    char dummy[10];
                    fgets(dummy, sizeof(dummy), stdin);
                }
                break;

            case 5:
                inserirNaEstrutura(&lista, &pilha, &fila);
                break;

            case 6:
                removerDaEstrutura(&lista, &pilha, &fila);
                break;

            case 7:
                exibirEstrutura(&lista, &pilha, &fila);
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;
        }

    } while (opcao != 0);

    liberarArvore(arvore.raiz);
    liberarLista(&lista);
    liberarPilha(&pilha);
    liberarFila(&fila);

    return 0;
}