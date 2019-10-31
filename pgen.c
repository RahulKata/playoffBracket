// Given an integer n, generates all combinations of balanced n-pair parentheses strings.
// for ex.if n = 2 then [ "()()", "(())" ] are the possible valid solutions.
// n=3 then [ "((()))", "(()())", "(())()", "()(())", "()()()" ] is the solution set.

#include <stdio.h>
#define size 5000

void tt(int);
void ssv(int, int, int, int);

int main(void)
{
    int n;
    printf("\n~~Enter a Number => ");
    scanf("%d", &n);
    printf("The valid solutions are: \n");
    tt(n);
    // getchar();
    return 0;
}

void tt(int n)
{
    if (n > 0)
    {
        ssv(0, n, 0, 0);
        return;
    }
}

void ssv(int pos, int n, int open, int close)
{
    static char str[size];
    if (close == n)
    {
        printf("%s\n", str);
        return;
    }
    else
    {
        if (open < n)
        {
            str[pos] = '(';
            ssv(pos + 1, n, open + 1, close);
        }
        if (open > close)
        {
            str[pos] = ')';
            ssv(pos + 1, n, open, close + 1);
        }
    }
}