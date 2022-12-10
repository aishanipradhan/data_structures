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
    // Check if the array is empty
    if (n == 0)
        return NULL;

    // Create a new node for the first element of the array
    node *head = (node*)malloc(sizeof(node));
    head->data = arr[0];
    head->next = NULL;

    // Create a pointer to the current node in the list
    node *curr = head;

    // Iterate through the rest of the array
    for (int i = 1; i < n; i++)
    {
        // Create a new node for the current element of the array
        node *n = (node*)malloc(sizeof(node));
        n->data = arr[i];
        n->next = NULL;

        // Set the next pointer of the current node to point to the new node
        curr->next = n;

        // Move the current pointer to the new node
        curr = n;
    }

    // Return a pointer to the head of the linked list
    return head;
}

void printLinkedList(node *head)
{
    // Check if the linked list is empty
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    // Create a pointer to the current node in the list
    node *curr = head;

    // Iterate through the linked list and print the data of each node
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}

int main()
{
    // Define an array with some elements
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create a linked list from the array
    node *head = createLinkedList(arr, n);
    printLinkedList(head);
    

    return 0;
}
