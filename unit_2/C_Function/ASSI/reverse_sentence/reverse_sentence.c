#include <stdio.h>
#include <string.h>
void reverse(char sentence[], int length);
int main()
{
    char sentence[500];
    printf("Enter a sentence: ");
    gets(sentence);
    reverse(sentence, strlen(sentence));
}

void reverse(char sentence[], int length)
{
    if (length < 0)
        return;
    printf("%c", sentence[length]);
    length--;
    reverse(sentence, length);
}