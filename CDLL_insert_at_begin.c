#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;

struct node *insert_at_begin(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return head;
    }
    else
    {
        newNode->prev = head->prev;
        newNode->next = head;
        head->prev->next = newNode;
        head = newNode;
    }
    return head;
}

void display()
{
    struct node *temporary = head;
    do
    {
        printf("%d\t", temporary->data);
        temporary = temporary->next;
    } while (temporary != head);
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
        insert_at_begin(data);
    }
    display();
    printf("\n");
    return 0;
}