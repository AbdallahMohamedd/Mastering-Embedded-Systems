#include "stdio.h"
#include "string.h"
void reverse(char word[]);
int main()
{
    char word[1000];
    printf("Enter the name: ");
    gets(word);
    printf("Name after reverse: ");
    reverse(word);
}
void reverse(char word[])
{
    int i, space;
    for (i = 0; i < strlen(word); i++)
    {
        if (word[i] == ' ')
        {
            space = i;
            break;
        }
    }
    printf("%s ", &word[space + 1]);
    for (i = 0; i < space; i++)
    {
        printf("%c", word[i]);
    }
}