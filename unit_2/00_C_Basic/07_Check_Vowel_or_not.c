#include "stdio.h"
int main()
{
    char alphabet;
    printf("Enter an alphabet: ");
    scanf("%c", &alphabet);

    /*    if ((alphabet == 'a') || (alphabet == 'o') || (alphabet == 'e') || (alphabet == 'i') || (alphabet == 'u') || (alphabet == 'A') || (alphabet == 'O') || (alphabet == 'E') || (alphabet == 'I') || (alphabet == 'U'))
        {
            printf("%c is a Vowel", alphabet);
        }
        else
            printf("%c is a consonant", alphabet);
            */

    switch (alphabet)
    {
    case 'a':
    case 'o':
    case 'u':
    case 'e':
    case 'i':
    case 'A':
    case 'O':
    case 'U':
    case 'E':
    case 'I':
    {
        printf("%c is a Vowel", alphabet);
    }
    break;
    default:
        printf("%c is a consonant", alphabet);
    }
}
