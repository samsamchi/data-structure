#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define ITEM char
#define TAM 50

typedef struct pilha 
{
    ITEM vet[TAM];
    int topo;
} TPilha;

void create(TPilha *p) 
{
    p->topo = -1;
}

void destroy(TPilha *p) 
{
    p->topo = -1;
}

int isfull(TPilha *p) 
{
    return p->topo == TAM;
}

int isempty(TPilha *p) 
{
    return p->topo == -1;
}

void push(TPilha *p, ITEM x) 
{
    if (isfull(p)) {
        puts("overflow");
        abort();
    }
    p->topo++;
    p->vet[p->topo] = x;
}

ITEM pop(TPilha *p) 
{
    if (isempty(p)) 
    {
        puts("underflow");
        abort();
    }
    ITEM x = p->vet[p->topo];
    p->topo--;
    return x;
}

ITEM top(TPilha *p) 
{
    if (isempty(p)) {
        puts("underflow");
        abort();
    }
    return p->vet[p->topo];
}

int palindromo(char s[]) 
{
    char copia[TAM];
    TPilha pilha;
    create(&pilha);

    int tamanho = strlen(s);
    int inicio = 0;

    for (int i = 0; i <= tamanho; i++) 
    {
        if (s[i] == ' ' || s[i] == '\0') // caso leia um espaço em branco ou caractere nulo, significa que é uma palavra
        {
            for (int j = inicio; j < i; j++) 
            {
                push(&pilha, s[j]); // empilha os caracteres na string s (a palavra esta em ordem)
            }

            for (int j = inicio; j < i; j++) 
            {
                copia[j] = pop(&pilha); // vai desempilhado e jogando na string copia (a palavra esta ao contrario)
            }

            inicio = i + 1; // leu uma palavra (de uma frase) e depois vai para a outra
        }
    }

    int palindrome = 1; // flag de controle, assume que é um palindromo

    for (int i = 0; i < tamanho; i++) 
    {
        if (copia[i] != s[i]) 
        {
            palindrome = 0; // se os caracteres nao batem, muda a flag para 0
            break;
        }
    }

    return palindrome;
}

int main(void) 
{
    char palavra[TAM];

    scanf("%s", palavra);

    if (palindromo(palavra)) 
    {
        printf("sim\n");
    } 
    else 
    {
        printf("nao\n");
    }

    return 0;
}
