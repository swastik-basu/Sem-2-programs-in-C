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

struct node *reverse()
{
    struct node *prev = NULL;
    struct node *next = NULL;
    while (head != NULL)
    {
        next = head->next;
        head->next = prev;

        prev = head;
        head = next;
    }
    head = prev;
    return prev;
}

struct node *removeDuplicates()
{
    struct node *curr1 = head;
    while (curr1 != NULL)
    {
        struct node *curr2 = curr1;
        while (curr2->next != NULL)
        {
            if (curr2->next->data == curr1->data)
            {
                struct node *duplicate = curr2->next;
                curr2->next = curr2->next->next;
                free(duplicate);
            }
            else
            {
                curr2 = curr2->next;
            }
        }
        curr1 = curr1->next;
    }
    return head;
}

struct node *display()
{
    struct node *temporary = head;
    while (temporary != NULL)
    {
        printf("%d->", temporary->data);
        temporary = temporary->next;
    }
    printf("NULL\n");
    return head;
}

int main()
{
    printf("Enter the number of elements in the LL\n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter data to enter\n");
        scanf("%d", &data);
        insert_at_end(data);
    }
    printf("List before operation\n");
    display();
    reverse();
    removeDuplicates();
    reverse();
    printf("List after operation\n");
    display();
}