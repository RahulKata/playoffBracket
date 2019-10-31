// A simple parenthesis checker(for now).
// Also prints the number of matched parenthesis pairs
// Will also include the code to Balance the parentheses in future

#include <stdio.h>
#include <string.h>

char st[100];
int top = -1, matches = 0;
void push(char);
char pop();

int main()
{
    char a[100], t;
    int i, f = 1;
    printf("\n~~Enter an Expression => ");
    scanf("%s", a);
    for (i = 0; i < strlen(a); i++)
    {
        if ((a[i] == '(') || (a[i] == '{') || (a[i] == '['))
        {
            push(a[i]);
        }
        if ((a[i] == ')') || (a[i] == '}') || (a[i] == ']'))
        {
            if (top == -1)
                f = 0;
            else
            {
                t = pop();
                if ((a[i] == ')') && (t == '[' || t == '{'))
                    f = 0;
                if ((a[i] == '}') && (t == '(' || t == '['))
                    f = 0;
                if ((a[i] == ']') && (t == '{' || t == '('))
                    f = 0;
            }
        }
    }
    if (top >= 0)
        f = 0;
    if (f == 0)
    {
        printf("\n\n --------UnBalanced-------- \n\n");
        // printf("%s\n", st);
        printf("Number of matched parenthesis pairs are: %d\n", matches);
    }
    else
    {
        printf("\n\n --------Balanced-------- \n\n");
        printf("Number of matched parenthesis pairs are: %d\n", matches);
    }
    return 0;
}

void push(char a)
{
    top = top + 1;
    st[top] = a;
    printf("\n%c - pushed into the stack", st[top]);
}

char pop()
{
    printf("\n%c - popped from the stack", st[top]);
    matches++;
    return st[top--];
}