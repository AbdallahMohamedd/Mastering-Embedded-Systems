#include <stdio.h>
int ss();
int main()
{
    printf("%d", ss());
}
int ss()
{
    static int i = 0;
    static int sum = 0;
    if (i != 100)
    {
        i++;
        sum += i;
        ss();
    }
    else
        return sum;
}