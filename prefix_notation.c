#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "char_stack.h"

int isCharacter(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
void reverseString(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}
void infixToPostfix(char *infix, char *prefix)
{
    reverseString(infix);
    int len = strlen(infix);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        char ch = infix[i];

        if (isCharacter(ch))
        {
            prefix[j++] = ch;
        }
        else if (ch == ')')
        {
            push(ch);
        }
        else if (ch == '(')
        {
            while (!isEmpty() && peek() != ')')
            {
                prefix[j++] = pop();
            }
            pop();
        }
        else if (isOperator(ch))
        {
            while (!isEmpty() && precedence(peek()) >= precedence(ch))
            {
                prefix[j++] = pop();
            }
            push(ch);
        }
    }
    while (!isEmpty())
    {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';
    reverseString(prefix);
}

int main()
{
    int n;
    printf("Enter the number of all total operators and operands you want to enter\n");
    scanf("%d", &n);

    char infix[n + 1], prefix[n + 1];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, prefix);

    printf("Postfix expression: %s\n", prefix);

    return 0;
}
