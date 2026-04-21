#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    int numero;
    struct no *proximo;
} No;

No *empilhar(No *topo, int numero)
{
    No *novo = malloc(sizeof(No));
    
    if (novo)
    {
        novo->numero = numero;
        novo->proximo = topo;
        return novo;
    }
    else 
    {
        printf("Erro ao alocar memoria para o no\n");
        return NULL;
    }
}

No *desempilhar(No **topo)
{
    if (*topo != NULL)
    {
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else
    {
        printf("Pilha vazia\n");
        return NULL;
    }
}

void imprimir(No *topo)
{
    while (topo != NULL)
    {
        printf("%d ", topo->numero);
        topo = topo->proximo;
    }
    printf("\n");
}

int main()
{
    No *remover, *topo = NULL;
    char operacao[15];

    while (scanf("%s", operacao) != EOF)
    {
        if(strcmp(operacao, "Finalizar") == 0)
        {
            break;
        }
        else if(strcmp(operacao, "Empilhar") == 0)
        {
            int numero;
            scanf("%d", &numero);
            topo = empilhar(topo, numero);
        }
        else if (strcmp(operacao, "Desempilhar") == 0)
        {
            remover = desempilhar(&topo);

            if (remover != NULL)
            {
                free(remover); 
            }
        }
        else if(strcmp(operacao, "Imprimir") == 0)
        {
            imprimir(topo);
        }
    }

    return 0;
}
