#include "stdio.h"
#include "string.h"
int main()
{
    char sentence[100];
    char *p_sentence = sentence;
    int i = 0;
    printf("Input a string : ");
    gets(sentence);
    printf("Reverse of the string is : ");
    for (; i < strlen(sentence); i++)
    {
        *p_sentence = sentence[i];
        p_sentence++;
    }
    i = 0;
    do
    {
        printf("%c", *p_sentence);
        p_sentence--;
        i++;
    } while (i <= strlen(sentence));
}