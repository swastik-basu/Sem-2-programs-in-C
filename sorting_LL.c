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
void sorting()
{
    struct node *pointer_one = head;
    while (pointer_one->next != NULL)
    {
        struct node *pointer_two = pointer_one->next;
        while (pointer_two->next != NULL)
        {
            if (pointer_one->data >= pointer_two->data)
            {
                int temp = pointer_one->data;
                pointer_one->data = pointer_two->data;
                pointer_two->data = temp;
            }
            pointer_two = pointer_two->next;
        }
        pointer_one = pointer_one->next;
    }
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
    printf("\nSorted LL becomes\n");
    sorting();
    display();
    return 0;
}