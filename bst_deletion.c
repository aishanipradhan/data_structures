#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

int getRightMin(struct node *root)
{
    struct node *temp = root;

    while(temp->left != NULL){ temp = temp->left;}

    return temp->key;
}

struct node *removeNode(struct node *root, int val)
{
    if(root == NULL)
        return NULL;

    if(root->key < val)
        root->right = removeNode(root->right,val);

    else if(root->key > val)
        root->left = removeNode(root->left,val);

    else
    {

        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        else if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            int rightMin = getRightMin(root->right);
            root->key = rightMin;
            root->right = removeNode(root->right,rightMin);
        }

    }

    //return the actual root's address
    return root;
}
