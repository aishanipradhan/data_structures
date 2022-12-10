#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node* createLinkedList(int arr[], int n)
{
    if (n == 0)
        return NULL;

    node *head = (node*)malloc(sizeof(node));
    head->data = arr[0];
    head->next = NULL;

    node *curr = head;

    for (int i = 1; i < n; i++)
    {
        node *n = (node*)malloc(sizeof(node));
        n->data = arr[i];
        n->next = NULL;
        
        curr->next = n;

        curr = n;
    }

    return head;
}

void printLinkedList(node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    node *curr = head;

    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    node *head = createLinkedList(arr, n);
    printLinkedList(head);
    

    return 0;
}
