#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue
{
    int *arr;
    int capacity;
    int front;
    int rear;
};

struct Queue s;
void initialise(int size)
{
    s.arr = (int *)malloc(size * sizeof(int)); // Allocate memory for the array
    s.front = -1;
    s.rear = -1;
    s.capacity = size;
}
bool isFull()
{
    return s.rear == s.capacity - 1;
}
bool isEmpty()
{
    return (s.front == s.capacity - 1);
}
void enqueue(int data)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
    }
    else
    {
        if (s.front == -1)
        {
            s.front = 0;
            s.arr[++s.rear] = data;
        }
        else
        {
            s.arr[++s.rear] = data;
        }
    }
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Stack Underflow.Returning garbage\n");
        return -999999;
    }
    else
    {
        return s.arr[s.front++];
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
        printf("Enter 'e' to enqueue, 'd' to dequeue , 'q' to quit: \n");
        scanf(" %c", &choice);
        getchar();
        if (choice == 'e')
        {
            int data;
            printf("Enter the data to be enqueued: ");
            scanf("%d", &data);
            enqueue(data);
        }
        else if (choice == 'd')
        {
            int data = dequeue();
            printf("Dequeued element is: %d\n", data);
        }
        else
        {

            printf("Exiting the program\n");
            break;
        }
    }

    return 0;
}