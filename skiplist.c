#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int key;
    struct node *next;
    struct node *forward;
} node;

node* newNode(int key)
{
    node* n = (node*)malloc(sizeof(node));
    n->key = key;
    n->next = NULL;
    n->forward = NULL;
    return n;
}

void insert(node **head, int key)
{
    node *n = newNode(key);
    n->forward = (node*)malloc(sizeof(node));
    n->forward->forward = (node*)malloc(sizeof(node));

    n->forward->key = key;
    n->forward->forward->key = key;

    n->next = *head;
    n->forward->next = (*head)->forward;
    n->forward->forward->next = (*head)->forward->forward;

    *head = n;
}



int main()
{
    node *head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);

    return 0;
}

