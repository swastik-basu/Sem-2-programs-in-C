#include <stdio.h>
#include <stdlib.h>

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

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}

struct node *minimum(struct node *root)
{
    struct node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}

struct node *delete(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key > root->data)
    {
        root->right = delete (root->right, key);
    }
    else if (key < root->data)
    {
        root->left = delete (root->left, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = minimum(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
    }

    return root;
}