#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
} node;

node* newNode(int key)
{
    node* n = (node*)malloc(sizeof(node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1; 
    return n;
}

int height(node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int balanceFactor(node *n)
{
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}


node* rightRotate(node* n)
{
    node *x = n->left;
    node *T2 = x->right;

    x->right = n;
    n->left = T2;

    n->height = max(height(n->left), height(n->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

node* leftRotate(node* n)
{
    node *y = n->right;
    node *T2 = y->left;

    y->left = n;
    n->right = T2;

    n->height = max(height(n->left), height(n->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

node* insert(node* n, int key)
{
    if (n == NULL)
        return newNode(key);

    if (key < n->key)
        n->left = insert(n->left, key);
    else if (key > n->key)
        n->right = insert(n->right, key);
    else 
        return n;


    n->height = 1 + max(height(n->left), height(n->right));


    int balance = balanceFactor(n);
    
    if (balance > 1 && key < n->left->key)
        return rightRotate(n);

    if (balance < -1 && key > n->right->key)
        return leftRotate(n);

    if (balance > 1 && key > n->left->key)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }

    if (balance < -1 && key < n->right->key)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
}

node* arrayToAVL(int arr[], int n)
{
    node *root = NULL;

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    return root;
}

void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int n = sizeof(arr) / sizeof(arr[0]);

    node *root = arrayToAVL(arr, n);

    printf("Preorder traversal of the constructed AVL tree is: \n");
    preorder(root);

    return 0;
}


