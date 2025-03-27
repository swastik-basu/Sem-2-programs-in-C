#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *root = NULL;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return root->height;
}

int balanceFactor(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return height(root->left) - height(root->right);
}

struct node *leftRotation(struct node *root)
{
    if (root == NULL || root->right == NULL)
    {
        return root;
    }
    struct node *temp1 = root->right;
    struct node *temp2 = temp1->left;

    temp1->left = root;
    root->right = temp2;

    if (temp1 != NULL)
        temp1->height = max(height(temp1->left), height(temp1->right)) + 1;
    if (temp2 != NULL)
        temp2->height = max(height(temp2->right), height(temp2->left)) + 1;

    return temp1;
}

struct node *rightRotation(struct node *root)
{
    if (root == NULL || root->left == NULL)
    {
        return root;
    }
    struct node *temp1 = root->left;
    struct node *temp2 = temp1->right;

    temp1->right = root;
    root->left = temp2;

    if (temp1 != NULL)
        temp1->height = max(height(temp1->left), height(temp1->right)) + 1;
    if (temp2 != NULL)
        temp2->height = max(height(temp2->right), height(temp2->left)) + 1;

    return temp1;
}

struct node *insertion(struct node *root, int val)
{
    if (root == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;
        temp->height = 1;
        return temp;
    }

    else if (val < root->data)
    {
        root->left = insertion(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insertion(root->right, val);
    }
    else if (val == root->data)
    {
        printf("Equal elements are not allowed in BST\n");
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    if (balanceFactor(root) > 1 && val < root->left->data)
        return rightRotation(root);
    if (balanceFactor(root) < -1 && val > root->right->data)
        return leftRotation(root);
    if (balanceFactor(root) > 1 && val > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    if (balanceFactor(root) < -1 && val < root->right->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

int main()
{

    char ch = 'e';
    while (ch == 'e')
    {
        int value;
        printf("Enter the value to be inserted: ");
        scanf("%d", &value);
        root = insertion(root, value);
        printf("Press 'e' to continue insertion and 'q' to quit: ");
        scanf(" %c", &ch);
    }

    inorder(root);
    printf("\nInorder traversal of BBST sorts the numbers\n");
}