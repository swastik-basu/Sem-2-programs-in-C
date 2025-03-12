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

void infixToPostfix(char *infix, char *postfix)
{

    int len = strlen(infix);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        char ch = infix[i];

        if (isCharacter(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else if (isOperator(ch))
        {
            while (!isEmpty() && precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    while (!isEmpty())
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main()
{
    int n;
    printf("Enter the number of all total operators and operands you want to enter\n");
    scanf("%d", &n);

    char infix[n + 1], postfix[n + 1];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
