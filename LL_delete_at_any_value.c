#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *insert_at_end(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *temporary = head;
        while (temporary->next != NULL)
        {
            temporary = temporary->next;
        }
        temporary->next = temp;
    }
    return head;
}

struct node *delete_at_any(int pos)
{
    if (head == NULL)
        return NULL;
    struct node *temp = head;
    struct node *prev = NULL;
    int i = 1;
    while (temp->next != NULL && i < pos)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if (temp != NULL)
    {
        prev->next = temp->next;
        free(temp);
    }
    else
    {
        printf("Data not present\n");
    }
    temp->next = NULL;

    return head;
}

struct node *display()
{
    struct node *temporary = head;
    while (temporary != NULL)
    {
        printf("%d\t", temporary->data);
        temporary = temporary->next;
    }
    return head;
}
int main()
{
    int n;
    printf("ENter the nnumber of nodes you want\n");
    scanf("%d", &n);
    printf("Enter elements\n");
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        insert_at_end(data);
    }
    display();
    printf("\n");
    delete_at_any(3);
    printf("List after deleting the last element is\n");
    display();
    return 0;
}