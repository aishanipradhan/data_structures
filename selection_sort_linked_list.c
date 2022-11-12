#include <stdio.h>
#include <stdlib.h>
  
struct node {
    int data;
    struct node* next;
};
  
void printList(struct node* n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
    printf("\n");
}

int main()
{
    struct node*head = (struct node*)malloc(sizeof(struct node));
    struct node*second = (struct node*)malloc(sizeof(struct node));
    struct node*third = (struct node*)malloc(sizeof(struct node));
  
    head->data = 37; 
    head->next = second; 
  
    second->data = 23; 
    second->next = third;
  
    third->data = 2973; 
    third->next = NULL;
  
    
    printf("original linked list:");
    printList(head);
    
    struct node* temp = head;
  
    
    while (temp) {
        struct node* min = temp;
        struct node* new = temp->next;
  
        
        while (new) {
            if (min->data > new->data)
                min = new;
  
            new = new->next;
        }
  
        
        int x = temp->data;
        temp->data = min->data;
        min->data = x;
        temp = temp->next;
    }
    printf("sorted linked list:");
    printList(head);
  
    return 0; }
