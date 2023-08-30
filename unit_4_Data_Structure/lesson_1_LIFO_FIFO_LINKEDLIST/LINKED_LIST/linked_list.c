/*
 Master Embedded Systems "learn in depth"
 Eng.: Abdullah Mohamed
 Unit 4********Lesson:1********Topic:linked list
 File:linked_list.c
 */

#include "linked_list.h"

/*DEBUG*/
// #define debug
#define yarab printf("@ Func: %s, File: %s, Line: %d \n", __func__, __FILE__, __LINE__);

/*Initialize global pointer variable to point first location in list*/
struct S_NODE_STUDENT *P_G_FIRST_STUDENT = NULL;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ADD_STUDENT_FUNC(void)
{
    char temp_text[60];
    struct S_NODE_STUDENT *P_NEW_STUDENT;                      // Must be local.. to delete it when finsh calling time
    struct S_NODE_STUDENT *P_LAST_STUDENT = P_G_FIRST_STUDENT; // Must be local.. to delete it when finsh calling time
    /*Have 2 cases... if list is empty or not*/
    if (!P_G_FIRST_STUDENT)
    {
        /*Creat a new record*/
        P_NEW_STUDENT = (struct S_NODE_STUDENT *)malloc(sizeof(struct S_NODE_STUDENT));
        /*Assign P_NEW_STUDENT to p_g_first_student */
        P_G_FIRST_STUDENT = P_NEW_STUDENT;
    }
    else
    {
        while (P_LAST_STUDENT->P_NEXT_STUDENT) // navigate till find last student "when return 0"
        {
            P_LAST_STUDENT = P_LAST_STUDENT->P_NEXT_STUDENT; // enter here to make next student is the last student and navigate again
            // leave loop when next student of last student is a null
        }
        // now creat a new record & make next student of last student = new student  instead of null
        /*Creat a new record*/
        P_NEW_STUDENT = (struct S_NODE_STUDENT *)malloc(sizeof(struct S_NODE_STUDENT));
        /*Assign P_NEW_STUDENT to p_g_first_student */
        P_LAST_STUDENT->P_NEXT_STUDENT = P_NEW_STUDENT;
    }
    /*fill current student*/
    printf("Please Enter the ID: ");
    gets(temp_text);
    P_NEW_STUDENT->current_student.ID = atoi(temp_text);

    printf("Please Enter the Name: ");
    gets(P_NEW_STUDENT->current_student.name);

    printf("Please Enter the height: ");
    gets(temp_text);
    P_NEW_STUDENT->current_student.height = atof(temp_text);

    /*set next student = null*/
    P_NEW_STUDENT->P_NEXT_STUDENT = NULL;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int DELETE_STUDENT_FUNC(void)
{
    if (P_G_FIRST_STUDENT) // make sure list is exist
    {
        unsigned int selected_id;                                      // select id
        struct S_NODE_STUDENT *P_SELECTED_STUDENT = P_G_FIRST_STUDENT; // selected pointer in current student
        struct S_NODE_STUDENT *P_PREVIOUS_STUDENT = NULL;              // selected pointer in previous student
        printf("\nPlease enter the id:");                              // ask user to take a student's id
        scanf("%d", &selected_id);                                     // take if
        while (P_SELECTED_STUDENT)                                     // loop on all student
        {
            if (P_SELECTED_STUDENT->current_student.ID == selected_id)
            {
                if (P_PREVIOUS_STUDENT) // enter in condtion if selected student NOT 1st student
                {
                    P_PREVIOUS_STUDENT->P_NEXT_STUDENT = P_SELECTED_STUDENT->P_NEXT_STUDENT; // make next of previous ==next of selected
                }
                else // enter else if selected student == 1st student
                {
                    P_G_FIRST_STUDENT = P_SELECTED_STUDENT->P_NEXT_STUDENT; // make p_g_first_student == next student of selected student
                }
                free(P_SELECTED_STUDENT); // delete student doneeeeeeeeeeeeeeeeeeeeeeee
                return 0;                 // END FUNCTION ;)
            }
            /*Before enter the loop again, must increment 2 pointers.... previous=selected and selected=next of selected*/
            P_PREVIOUS_STUDENT = P_SELECTED_STUDENT;
            P_SELECTED_STUDENT = P_SELECTED_STUDENT->P_NEXT_STUDENT;
        }
        printf("\n Can NOT find the ID :(");
        return 1; // END FUNCTION :(
    }
    else
    {
        printf("\n The list is empty :("); // print it if list is NOT exist
        return 1;                          // END FUNCTION :(
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VIEW_ALL_LIST_FUNC(void)
{
    int counter = 0;
    struct S_NODE_STUDENT *P_SELECTED_STUDENT = P_G_FIRST_STUDENT; // selected pointer in current student
    if (P_G_FIRST_STUDENT)                                         // make sure list is exist
    {
        while (P_SELECTED_STUDENT)
        {
            printf("\nPrinting record number(%d)", counter + 1);
            printf("\nID: %d", P_SELECTED_STUDENT->current_student.ID);
            printf("\nName: %s", P_SELECTED_STUDENT->current_student.name);
            printf("\nHeight: %f", P_SELECTED_STUDENT->current_student.height);
            P_SELECTED_STUDENT = P_SELECTED_STUDENT->P_NEXT_STUDENT;
            counter++;
            printf("\n==============================================");
        }
    }
    else
    {
        printf("\n The list is empty :("); // print it if list is NOT exist
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DELETE_ALL_FUNC(void)
{
    struct S_NODE_STUDENT *P_SELECTED_STUDENT = P_G_FIRST_STUDENT; // selected pointer in current student
    if (P_G_FIRST_STUDENT)                                         // make sure list is exist
    {
        while (P_SELECTED_STUDENT)
        {
            struct S_NODE_STUDENT *P_TEMP = P_SELECTED_STUDENT;
            P_SELECTED_STUDENT = P_SELECTED_STUDENT->P_NEXT_STUDENT;
            free(P_TEMP);
        }
        P_G_FIRST_STUDENT = NULL;
    }
    else
    {
        printf("\n The list is empty :("); // print it if list is NOT exist
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int GET_SPECIFIC_NODE_FUNC(void)
{
    if (P_G_FIRST_STUDENT) // make sure list is exist
    {
        int node_number;
        printf("Please enter Nth student:  ");
        scanf("%d", &node_number);
        int counter = 1;                                               // counter to loop in all student
        struct S_NODE_STUDENT *P_SELECTED_STUDENT = P_G_FIRST_STUDENT; // selected pointer in current student
        while (P_SELECTED_STUDENT)                                     // make sure list is not finished
        {
            if (counter == node_number)
            {
                printf("\nPrinting record number(%d)", node_number);
                printf("\nID: %d", P_SELECTED_STUDENT->current_student.ID);
                printf("\nName: %s", P_SELECTED_STUDENT->current_student.name);
                printf("\nHeight: %f", P_SELECTED_STUDENT->current_student.height);
                return 0; // END FUNCTION ;)
            }
            else
            {
                counter++;
                P_SELECTED_STUDENT = P_SELECTED_STUDENT->P_NEXT_STUDENT;
            }
        }
        printf("\n Can NOT find the (%dth) Student 'WRONG NUMBER' ;(", node_number);
        return 1; // END FUNCTION :(
    }
    else
    {
        printf("\n The list is empty :("); // print it if list is NOT exist
        return 1;                          // END FUNCTION :(
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int The_number_of_students_in_the_list_FUNC(void)
{
    if (P_G_FIRST_STUDENT) // make sure list is exist
    {
        int counter = 0;
        struct S_NODE_STUDENT *P_SELECTED_STUDENT = P_G_FIRST_STUDENT; // selected pointer in current student
        while (P_SELECTED_STUDENT)
        {
            counter++;
            P_SELECTED_STUDENT = P_SELECTED_STUDENT->P_NEXT_STUDENT;
        }
        return counter; // END FUNCTION ;)
    }
    else
    {
        return 0; // END FUNCTION :(
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int GET_SPECIFIC_NODE_FROM_END_FUNC(void)
{
    if (P_G_FIRST_STUDENT) // make sure list is exist
    {
        int node_number, i = 0;
        printf("Please enter Nth ==>'FROM END'<== student:  ");
        scanf("%d", &node_number);
        struct S_NODE_STUDENT *P_SELECTED_STUDENT = P_G_FIRST_STUDENT;
        struct S_NODE_STUDENT *FAST_POINTER = P_G_FIRST_STUDENT;
        if (The_number_of_students_in_the_list_FUNC() > node_number)
        {
#ifdef debug
            yarab
#endif
                while (i != node_number)
            {
#ifdef debug
                yarab
                    printf("%d", i);
#endif
                FAST_POINTER = FAST_POINTER->P_NEXT_STUDENT;
#ifdef debug
                yarab
                    printf("%d", i);
#endif
                i++;
#ifdef debug
                yarab
                    printf("%d", i);
#endif
            }
            while (P_SELECTED_STUDENT) // make sure list is not finished
            {
                if (!FAST_POINTER) // NOT EQUAL NULL
                {
                    printf("\nPrinting record number(%d)", node_number);
                    printf("\nID: %d", P_SELECTED_STUDENT->current_student.ID);
                    printf("\nName: %s", P_SELECTED_STUDENT->current_student.name);
                    printf("\nHeight: %f", P_SELECTED_STUDENT->current_student.height);
                    return 0; // END FUNCTION ;)
                }
                else
                {
#ifdef debug
                    yarab;
#endif
                    FAST_POINTER = FAST_POINTER->P_NEXT_STUDENT;
                    P_SELECTED_STUDENT = P_SELECTED_STUDENT->P_NEXT_STUDENT;
                }
            }
        }
        else
        {
            printf("\n Can NOT find the (%dth) Student 'WRONG NUMBER' ;(", node_number);
            return 1; // END FUNCTION :(
        }
    }
    else
    {
        printf("\n The list is empty :("); // print it if list is NOT exist
        return 1;                          // END FUNCTION :(
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
