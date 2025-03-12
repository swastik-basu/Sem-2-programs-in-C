#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
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
    struct node *root = NULL;
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
}