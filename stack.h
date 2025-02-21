#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100
struct Stack
{
    int arr[MAX_SIZE];
    int top;
};
struct Stack s;
void initialise()
{
    s.top = -1;
}
bool isFull()
{
    return s.top == MAX_SIZE - 1;
}
bool isEmpty()
{
    return s.top == -1;
}
void push(int data)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
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
        printf("Stack Underflow.Returning -1\n");
        return -1;
    }
    else
    {
        return s.arr[s.top--];
    }
}
int peek()
{
    if (isEmpty())
    {
        printf("The stack is empty Nothing to peek.\n");
    }
    else
    {
        return s.arr[s.top];
    }
}