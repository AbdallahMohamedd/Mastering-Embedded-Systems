#include "stdio.h"
#include "string.h"
void add_digits(char data[], int length); // function prototype
int main()
{                                       // start scope of main function
    char number[10000];                 // declaration number which taken from user
    printf("Enter the number: ");       // sentence to display in screen to user enter number
    gets(number);                       // get number from user as a string
    add_digits(number, strlen(number)); // calling function
} // end main function
//////////////////////////////////////////////////////////////////////////////////////////////////////
void add_digits(char data[], int length) // header of function
{                                        // start scope of function
    int r = 0;                           // declaration and initialization result variable
    for (int i = 0; i < length; i++)     // start loop to take all value of string
    {                                    // start scope of loop
        data[i] = data[i] - 48;          // from ascci code (int number = char number - 48)"
        r += data[i];                    // add digits
    }                                    // end scope of loop
    printf("%d", r);                     // print result
} // end scope of function