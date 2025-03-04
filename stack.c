#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
    int *arr;
    int capacity;
    int top;
};

struct Stack s;

void initialise(int size)
{
    s.arr = (int *)malloc(sizeof(int) * size);
    s.capacity = size;
    s.top = -1;
}

bool isFull()
{
    return s.top == s.capacity - 1;
}

bool isEmpty()
{
    return s.top == -1;
}

void push(int data)
{
    if (isFull())
    {
        printf("Stack is Full\n");
    }
    else
    {
        s.arr[++s.top] = data;
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack is Empty\n");
        return -99999;
    }
    else
    {
        int popped = s.arr[s.top--];
        return popped;
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("Stack is Empty. Nothing to peek\n");
    }
    else
    {
        printf("Topmost element of the stack is:- %d\n", s.arr[s.top]);
    }
}

int main()
{

    printf("Enter the maximum size of the queue: ");
    int capacity;
    scanf("%d", &capacity);
    initialise(capacity);
    char choice;
    while (1)
    {
        printf("Enter 'e' to enqueue, 'd' to dequeue , 'p' to peek, 'q' to quit: \n");
        scanf(" %c", &choice);
        getchar();
        if (choice == 'e')
        {
            int data;
            printf("Enter the data to be pushed: ");
            scanf("%d", &data);
            getchar();
            push(data);
        }
        else if (choice == 'd')
        {
            int data = pop();
            printf("Popped element is: %d\n", data);
        }

        else if (choice == 'p')
        {
            peek();
        }
        else
        {

            printf("Exiting the program\n");
            break;
        }
    }

    return 0;
}