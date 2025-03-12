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
bool isFullQ()
{
    return s.rear == s.capacity - 1;
}
bool isEmptyQ()
{
    return (s.front == s.capacity - 1);
}
void enqueue(int data)
{
    if (isFullQ())
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
    if (isEmptyQ())
    {
        printf("Stack Underflow.Returning garbage\n");
        return -999999;
    }
    else
    {
        return s.arr[s.front++];
    }
}
