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

struct Queue q;

void initialise(int size)
{
    q.arr = (int *)malloc(sizeof(int) * size);
    q.capacity = size;
    q.front = -1;
    q.rear = -1;
}

bool isFull()
{
    return (q.rear + 1) % q.capacity == q.front;
}

bool isEmpty()
{
    return q.front == -1;
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue is Full\n");
        return;
    }

    if (q.front == -1)
    {
        q.front = 0;
        q.rear = 0;
    }
    else
    {
        q.rear = (q.rear + 1) % q.capacity;
    }

    q.arr[q.rear] = data;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return -1;
    }

    int temp = q.arr[q.front];

    if (q.front == q.rear)
    {
        q.front = -1;
        q.rear = -1;
    }
    else
    {
        q.front = (q.front + 1) % q.capacity;
    }

    return temp;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements are: ");
    int i = q.front;
    printf("%d\t", q.arr[i]);
    do
    {

        i = (i + 1) % q.capacity;
        printf("%d\t", q.arr[i]);
    } while (i != q.rear);

    printf("\n");
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
        printf("Enter 'e' to enqueue, 'd' to dequeue, 'q' to quit and display: \n");
        scanf(" %c", &choice);

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
            if (data != -1)
                printf("Dequeued element is: %d\n", data);
        }
        else if (choice == 'q')
        {
            printf("Exiting the program\n");
            break;
        }
    }

    display();
    free(q.arr);
    return 0;
}
