#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head;
typedef struct Node node;
void insert(int item)
{
    node *temp = head;
    node *new = (node *)malloc(sizeof(node));
    new->data = item;
    if (head == NULL)
    {
        new->next = new;
        head = new;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        new->next = head;
        temp->next = new;

        head = new;
    }
}
void traverse()
{
    node *temp = head;
    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
void deleteAtLast()
{
    node *temp = head;
    node *temp2 = head;
    if (head == NULL)
    {
        printf("List is already empty!!!");
        return;
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
    }
    else
    {
        while (temp->next != head)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = temp->next;
        free(temp);
    }
}
int main()
{
    insert(40);
    insert(30);
    insert(20);
    insert(10);

    printf("The main linked list is : ");
    traverse();

    deleteAtLast();
    printf("\nAfter delete last node the list is : ");
    traverse();

    return 0;
}