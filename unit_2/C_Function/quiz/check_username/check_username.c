#include "stdio.h"
#include "string.h"
int main()
{
    char cname[]="Abdullah";
    char ename[100];
    printf("Enter username: ");
    gets(ename);
    stricmp(ename,cname)?printf("wrong"):printf("correct");
}