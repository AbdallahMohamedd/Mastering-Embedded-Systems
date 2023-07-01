#include "stdio.h"
int power(int base, int po);
int main()
{
    int n, p;
    printf("Enter base number: ");
    scanf("%d", &n);
    printf("Enter power number(+ve integer): ");
    scanf("%d", &p);
    printf("%d^%d = %d", n, p, power(n, p));
}
int power(int base, int po)
{
    int r = 0;
    if (po != 0)
    {
        po--;
        r = base * power(base, po);
        return r;
    }
    return 1;
}
