#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100
struct Stack2
{
    int arr[MAX_SIZE];
    int top;
};
struct Stack2 s2;
void initialise2()
{
    s2.top = -1;
}
bool isFull2()
{
    return s2.top == MAX_SIZE - 1;
}
bool isEmpty2()
{
    return s2.top == -1;
}
void push2(int data)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s2.arr[++s2.top] = data;
    }
}

int pop2()
{
    if (isEmpty())
    {
        printf("Stack Underflow.Returning -1\n");
        return -1;
    }
    else
    {
        return s2.arr[s2.top--];
    }
}
int peek2()
{
    if (isEmpty())
    {
        printf("The stack is empty Nothing to peek.\n");
    }
    else
    {
        return s2.arr[s2.top];
    }
}