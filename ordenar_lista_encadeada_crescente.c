#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int item;
    struct Node *next;
} Node;

Node *createNode(int item)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->item = item;
    new_node->next = NULL;
    return new_node;
}

Node *add(int item, Node *list, Node *previous)
{
    if (list == NULL)
    {
        return createNode(item);
    }
    list->next = add(item, list->next, list);
    return list;
}

void print(Node *list)
{
    Node *aux = list;
    while (aux != NULL)
    {
        printf("%d ", aux->item);
        aux = aux->next;
    }
    printf("\n");
}

void bubbleSort(Node *list)
{
    int swapped, temp;
    Node *ptr1;
    Node *lptr = NULL;

    if (list == NULL)
    {
        return;
    }

    do
    {
        swapped = 0;
        ptr1 = list;

        while (ptr1->next != lptr)
        {
            if (ptr1->item > ptr1->next->item)
            {
                temp = ptr1->item;
                ptr1->item = ptr1->next->item;
                ptr1->next->item = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void freeList(Node *list)
{
    Node *current = list;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

int main()
{
    int number;
    Node *list = NULL;

    while (scanf("%d", &number) != EOF)
    {
        list = add(number, list, NULL);
    }

    bubbleSort(list);

    print(list);

    freeList(list);

    return 0;
}
