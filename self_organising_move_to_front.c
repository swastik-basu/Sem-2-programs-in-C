#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
struct node *insert_at_end(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
    }
    return head;
}
struct node *front(int data)
{
    struct node *curr = head;
    while (curr != NULL && curr->data != data)
    {
        curr = curr->next;
    }

    if (curr == NULL || curr == head)
    {
        printf("element not found\n");
        return head;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    curr->next = head;
    curr->prev = NULL;
    head->prev = curr;
    head = curr;

    return head;
}

struct node *display()
{
    struct node *temporary = head;
    printf("NULL<->");
    while (temporary != NULL)
    {
        printf("%d<->", temporary->data);
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
    display();
    char ch = 's';
    printf("Enter any element to access\n");
    while (ch == 's')
    {
        int data;
        scanf("%d", &data);
        front(data);
        printf("Enter character s to search again and any other character to exit\n");
        getchar();
        scanf("%c", &ch);
    }
    display();
}