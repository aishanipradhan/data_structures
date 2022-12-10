node* reverseEveryK(node *head, int k)
{
    if (head == NULL)
        return NULL;

    node *curr = head;

    int count = 0;

    while (curr != NULL)
    {
        curr = curr->next;
        count++;
    }

    curr = head;

    node *prev = NULL;

    while (curr != NULL)
    {
        node *next = curr->next;
      
        for (int i = 0; i < k; i++)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next != NULL)
                next = next->next;
        }
      
        if (head == prev)
            head = curr;
    }

    return head;
}
