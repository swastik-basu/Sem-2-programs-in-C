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
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return head;
    }
    else
    {
        struct node *temp = head;
        do
        {
            temp = temp->next;
        } while (temp->next != head);

        temp->next = newNode;
        newNode->next = head;

        return head;
    }
}
void display()
{
    struct node *temp = head;
    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp->next != head->next);
}

int main()
{
    char ch;
    while (1)
    {
        printf("Enter 'e' to enter data to the head, 'd' to display linkedlist,'q' to quit\n");
        scanf("%c", &ch);
        getchar();
        if (ch == 'e')
        {
            int data;
            printf("Enter data to be inserted at head\n");
            scanf("%d", &data);
            getchar();
            insert_at_end(data);
        }
        else if (ch == 'd')
        {
            display();
            printf("\n");
        }
        else
        {
            break;
        }
    }

    return 0;
}