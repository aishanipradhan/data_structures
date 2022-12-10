void printFirstHalf(node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
  
    node *curr = head;

    int count = 0;

    while (curr != NULL)
    {
        curr = curr->next;
        count++;
    }

    curr = head;

    for (int i = 0; i < count / 2; i++)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}
