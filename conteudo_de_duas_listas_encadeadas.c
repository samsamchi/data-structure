#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* addToEnd(struct Node* list, int data)
{
    struct Node* newNode = createNode(data);

    if (list == NULL)
    {
        return newNode;
    }

    struct Node* current = list;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    return list;
}

void scan(struct Node** list, int size)
{
    int number;
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &number);
        *list = addToEnd(*list, number);
    }
}

void print(struct Node* list)
{
    while (list != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

int sub(struct Node* listA, struct Node* listB)
{
    while (listB != NULL)
    {
        int found = 0;
        struct Node* currentA = listA;

        while (currentA != NULL)
        {
            if (currentA->data == listB->data)
            {
                found = 1;
                break;
            }
            currentA = currentA->next;
        }

        if (!found)
        {
            return 0; 
        }

        listB = listB->next;
    }

    return 1;
}

void freeList(struct Node* list)
{
    struct Node* current = list;
    struct Node* next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

int main()
{
    int sizeA;
    scanf("%d", &sizeA);
    struct Node* listA = NULL;
    scan(&listA, sizeA);

    int sizeB;
    scanf("%d", &sizeB);
    struct Node* listB = NULL;
    scan(&listB, sizeB);

    printf("List A: ");
    print(listA);

    printf("List B: ");
    print(listB);

    if (sub(listA, listB))
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }

    freeList(listA);
    freeList(listB);

    return 0;
}
