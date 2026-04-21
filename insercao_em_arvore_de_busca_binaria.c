#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int conteudo;
    struct no *esquerda, *direita;
} No;

typedef struct
{
    No *raiz;
} ArvB;

void inseriresquerda(No *no, int valor)
{
    if (no->esquerda == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->esquerda = novo;
    }
    else
    {
        if (valor < no->esquerda->conteudo)
        {
            inseriresquerda(no->esquerda, valor);
        }
        else
        {
            inserirdireita(no->esquerda, valor);
        }
    }
}

void inserirdireita(No *no, int valor)
{
    if (no->direita == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->direita = novo;
    }
    else
    {
        if (valor >= no->direita->conteudo) 
        {
            inserirdireita(no->direita, valor);
        }
        else
        {
            inseriresquerda(no->direita, valor);
        }
    }
}

void print(No *arvore)
{
    if (arvore == NULL)
    {
        printf(" () ");
        return;
    }
    else
    {
        printf(" ( %d ", arvore->conteudo);
        print(arvore->esquerda);
        print(arvore->direita);
        printf(") ");
    }
}

void inserir(ArvB *arv, int valor)
{
    if (arv->raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arv->raiz = novo;
    }
    else
    {
        if (valor < arv->raiz->conteudo)
        {
            inseriresquerda(arv->raiz, valor);
        }
        else
        {
            inserirdireita(arv->raiz, valor);
        }
    }
}

int main()
{
    int n;
    ArvB arvore;
    arvore.raiz = NULL;

    while (scanf("%d", &n) != EOF)
    {
        inserir(&arvore, n);
        printf("----\nAdicionando %d\n  ", n);
        print(arvore.raiz);
        printf("\n");
    }
    printf("----");

    return 0;
}
