#include <stdio.h>
#include <stdlib.h>
  
struct node {
    int data;
    struct node* next;
};

struct node* sorted = NULL;
  
void printList(struct node* n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
    printf("\n");
}

void sortedInsert(struct node* newnode)
{
    if (sorted == NULL || sorted->data >= newnode->data) {
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        struct node* current = sorted;
        while (current->next != NULL
               && current->next->data < newnode->data) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}


int main()
{
    struct node*head = (struct node*)malloc(sizeof(struct node));
    struct node*second = (struct node*)malloc(sizeof(struct node));
    struct node*third = (struct node*)malloc(sizeof(struct node));
  
    head->data = 337; 
    head->next = second; 
  
    second->data = 2984;
    second->next = third;
  
    third->data = 0321; 
    third->next = NULL;
  
    printf("original linked list:");
    printList(head);
    
    struct node* current = head;
    
    
    while (current != NULL) {

        struct node* next = current->next;
        sortedInsert(current);


        current = next;
    }
  
    head = sorted;
    
    printf("sorted linked list:");
    printList(head);

    return 0; }
