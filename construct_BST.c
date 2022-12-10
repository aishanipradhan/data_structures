#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
} node;   

node* newNode(int key)
{
    node* n = (node*)malloc(sizeof(node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node* insert(node *root, int key)
{
    if (root == NULL)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

node* constructBST(int arr[], int n)
{
    node *root = NULL;

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    return root;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);

        printf("%d ", root->key);

        inorder(root->right);
    }
}


int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
  
    node *root = constructBST(arr, n);
  
    inorder(root);

    return 0;
}
