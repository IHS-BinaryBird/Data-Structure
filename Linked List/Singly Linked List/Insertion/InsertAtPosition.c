#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

void traverse(node *a)
{
    node *temp = a;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

void insertAtPosition(node **a, int item, int pos)
{
    node *temp = *a;
    node *new = (node *)malloc(sizeof(node));
    new->data = item;
    new->next = NULL;

    if (pos == 1)
    {
        new->next = *a;
        *a = new;
        return;
    }
    int i = 1;
    while (i < pos - 1)
    {
        /*if (temp == NULL || temp->next == NULL)
        {
            printf("\nItem position not found in the linked list !!!");
            return;
        }*/
        temp = temp->next;
        i++;
    }
    new->next = temp->next;
    temp->next = new;
}
int main()
{
    node *a = NULL;
    a = (node *)malloc(sizeof(node));
    node *b = (node *)malloc(sizeof(node));

    a->data = 20;
    a->next = b;
    b->data = 30;
    b->next = NULL;

    printf("The main list is : ");
    traverse(a);

    int n;
    printf("\nEnter the position : ");
    scanf("%d", &n);

    insertAtPosition(&a, 40, n);

    printf("The inserted list is : ");
    traverse(a);

    return 0;
}