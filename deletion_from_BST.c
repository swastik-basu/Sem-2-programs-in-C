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
void display(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    display(root->left);
    printf("%d\t", root->data);
    display(root->right);
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
    printf("\nBST before deletion\n");
    display(root);
    root = delete (root, 21);
    root = delete (root, 11);
    root = delete (root, 80);
    printf("\nBST after deletion\n");
    display(root);
    printf("\nInorder traversal of BST sorts the numbers\n");
}