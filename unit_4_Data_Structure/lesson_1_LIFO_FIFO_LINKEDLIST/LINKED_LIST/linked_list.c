/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 4********Lesson:1********Topic:linked list
File:linked_list.c
*/

#include "linked_list.h"

/*Initialize global pointer variable to point first location in list*/
struct SStudent *p_g_first_student = NULL;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ADD_STUDENT_FUN(void)
{
    char temp_text[50];
    struct SStudent *p_New_Student;                      // Must be local.. to delete it when finsh calling time
    struct SStudent *p_Last_Student = p_g_first_student; // Must be local.. to delete it when finsh calling time
    /*Have 2 cases... if list is empty or not*/
    if (!p_g_first_student)
    {
        /*Creat a new record*/
        p_New_Student = (struct SStudent *)malloc(sizeof(struct SStudent));
        /*Assign p_New_Student to p_g_first_student */
        p_g_first_student = p_New_Student;
    }
    else
    {
        while (p_Last_Student->p_Next_student) // navigate till find last student "when return 0"
        {
            p_Last_Student = p_Last_Student->p_Next_student; // enter here to make next student is the last student and navigate again
        }
        // leave loop when next student of last student is a null
        // now creat a new record & make next student of last student = new student  instead of null
        /*Creat a new record*/
        p_New_Student = (struct SStudent *)malloc(sizeof(struct SStudent));
        p_Last_Student->p_Next_student = p_New_Student;
    }
    /*fill current student*/
    printf("Please Enter the ID: ");
    gets(temp_text);
    p_New_Student->current_student.ID = atoi(temp_text);

    printf("Please Enter the Name: ");
    gets(p_New_Student->current_student.name);

    printf("Please Enter the height: ");
    gets(temp_text);
    p_New_Student->current_student.height = atof(temp_text);
    /*set next student = null*/
    p_New_Student->p_Next_student = NULL;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int DELETE_STUDENT_FUN(void)
{
    unsigned int selected_id;                               // select id
    struct SStudent *p_deleted_Student = p_g_first_student; // selected pointer in current student
    struct SStudent *p_previous_Student = NULL;             // selected pointer in previous student
    printf("\nPlease Enter the ID you want to delete");     // ask user to take a student's id
    scanf("%d", &selected_id);                              // take if
    if (p_g_first_student)                                  // make sure list is exist
    {
        while (p_deleted_Student) // loop on all student
        {
            if (p_deleted_Student->current_student.ID == selected_id)
            {
                if (p_previous_Student) // enter in condtion if selected student NOT 1st student
                {
                    p_previous_Student->p_Next_student = p_deleted_Student->p_Next_student; // make next of previous ==next of selected
                }
                else // enter else if selected student == 1st student
                {
                    p_g_first_student = p_deleted_Student->p_Next_student; // make p_g_first_student == next student of selected student
                }
                free(p_deleted_Student); // delete student doneeeeeeeeeeeeeeeeeeeeeeee
                return 1;                // END FUNCTION ;)
            }
            /*Before enter the loop again, must increment 2 pointers.... previous=selected and selected=next of selected*/
            p_previous_Student = p_deleted_Student;
            p_deleted_Student = p_deleted_Student->p_Next_student;
        }
        printf("\n Can NOT find the ID ;(");
        return 0; // END FUNCTION :(
    }
    printf("\n The list is empty ;("); // print it if list is NOT exist
    return 0;                          // END FUNCTION :(
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VIEW_ALL_LIST_FUN(void)
{
    if (p_g_first_student)
    {
        int counter = 0;
        struct SStudent *p_ccuurreenntt_student = p_g_first_student;
        while (p_ccuurreenntt_student)
        {
            printf("\nPrinting record number(%d)", counter + 1);
            printf("\nID: %d", p_ccuurreenntt_student->current_student.ID);
            printf("\nName: %s", p_ccuurreenntt_student->current_student.name);
            printf("\nHeight: %f", p_ccuurreenntt_student->current_student.height);
            counter++;
            p_ccuurreenntt_student = p_ccuurreenntt_student->p_Next_student;
            printf("\n==============================================");
        }
    }
    else
    {
        printf("\n The list is empty ;("); // print it if list is NOT exist
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DELETE_ALL_FUN(void)
{
    if (p_g_first_student)
    {
        struct SStudent *p_ccuurreenntt_student = p_g_first_student;
        while (p_ccuurreenntt_student)
        {
            struct SStudent *p_temp_student = p_ccuurreenntt_student;
            p_ccuurreenntt_student = p_ccuurreenntt_student->p_Next_student;
            free(p_temp_student);
        }
        p_g_first_student = NULL;
    }
    else
    {
        printf("\n The list is empty ;("); // print it if list is NOT exist
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
