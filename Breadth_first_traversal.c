#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (value >= root->data)
    {
        root->right = insert(root->right, value);
    }
    if (value <= root->data)
    {
        root->left = insert(root->left, value);
    }
    return root;
}

void BFT(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    insert_at_end(root->data);
}

int main()
{

    char ch = 'e';
    while (ch == 'e')
    {
        int value;
        printf("Enter the value to be inserted: ");
        scanf("%d", &value);
        root = insert(root, value);
        printf("Press 'e' to continue insertion and 'q' to quit: ");
        getchar();
        scanf("%c", &ch);
        getchar();
    }

    display(root);
    printf("Inorder traversal of BST sorts the numbers\n");
}