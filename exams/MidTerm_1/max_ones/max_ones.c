#include "stdio.h"
void max(int d_number);
int main()
{
    int d_number;
    printf("Enter the number: ");
    scanf("%d", &d_number);
    max(d_number);
}
void max(int d_number)
{
    int r[32], z = 0, g = 0, v = 0;
    printf("%d in binary is: ", d_number);
    for (int counter = 31, i = 0; counter >= 0; counter--, i++)
    {
        r[i] = 1 & (d_number >> counter);
        printf("%d", r[i]);
    }
    ////////////////////////////////////////////////////
    for (int i = 0; i < 32; i++)
    {
        if (r[i] == 0)
        {
            z = 0;
            for (; r[i + 1] != 0; i++)
                z++;
            if (g < z)
                g = z;
        }
    }
    printf("\nMax number of one's is: %d", g);
}
