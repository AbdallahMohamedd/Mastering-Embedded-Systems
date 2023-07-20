#include "stdio.h"
int main()
{
    char alpha[27];
    char *p_alpha = alpha;
    for (int i = 0; i < 26; i++)
    {
        *p_alpha = 'A' + i;
        p_alpha++;
    }
    p_alpha=alpha;
    for (int i = 0; i < 26; i++)
    {
        printf("%c  ",*p_alpha);
        p_alpha++;
    }
}