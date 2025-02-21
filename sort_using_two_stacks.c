#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack2.h"
int main()
{
    int n;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int arr[n];
    initialise();
    initialise2();
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        push(arr[i]);
    }

    while (isEmpty())
    {
        int temp = peek();
        pop();
        while (!isEmpty2() && peek2() < temp)
        {
            push(peek2());
            pop2();
        }
        push2(temp);
    }

    printf("Sorted stack is\n");
    while (!isEmpty2())
    {
        printf("%d", pop2());
    }
}