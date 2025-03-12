#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100
struct Stack
{
    char arr[MAX_SIZE];
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
void push(char data)
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

char pop()
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
char peek()
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