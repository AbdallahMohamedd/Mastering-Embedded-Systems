/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 5********PROJECT_2********Topic:Student Data Base
File:student.c
*/
#include "student.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************** Add student by file  ********************************************/
void ADD_STUDENT_FILE_FUNC()
{
    FILE *FILE_POINTER;
    int roll, i, c = 0;
    //S_STUDENTS_t *new_student;

    FILE_POINTER = fopen("student_data.txt", "r");
    if (FILE_POINTER)
    {
        while (fscanf(FILE_POINTER, "%d", &roll) == 1)
        {
            int k = 0;
            while (STUDENT_ARRAY[k].ROLL && (int)STUDENT_ARRAY[k].GPA)
            {
                (k != 55) ? (++k) : (k = 0);
            }
            STUDENT_ARRAY[k].ROLL = roll;
            while (c < STUDENT_LIST.counter)
            {
                if (STUDENT_ARRAY[k].ROLL == STUDENT_ARRAY[c].ROLL)
                {
                    printf("[ERROR] Roll number (%d) is already taken\n", STUDENT_ARRAY[k].ROLL);
                    printf("[INFO] Student Details is NOT added successfully\n");
                    return;
                }
                c++;
            }
            fscanf(FILE_POINTER, "%s", STUDENT_ARRAY[k].FIRST_NAME);
            fscanf(FILE_POINTER, "%s", STUDENT_ARRAY[k].LAST_NAME);
            fscanf(FILE_POINTER, "%f", &STUDENT_ARRAY[k].GPA);
            for (i = 0; i < 5; ++i)
            {
                fscanf(FILE_POINTER, "%d", &STUDENT_ARRAY[k].COURSE[i]);
            }
            ENqueue_LIST_FUNC(&STUDENT_ARRAY[k]);
        }
        fclose(FILE_POINTER);
    }
    else
        printf("[ERROE] FILE NOT FOUND\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************** Add student Manually ********************************************/
void ADD_STUDENT_MANUALLY_FUNC()
{
    int i = 0;
    while (STUDENT_ARRAY[i].ROLL && (int)STUDENT_ARRAY[i].GPA)
    {
        (i != 55) ? (++i) : (i = 0);
    }
    FILL_STUDENT_DATA_FUNC(&STUDENT_ARRAY[i]);
    ENqueue_LIST_FUNC(&STUDENT_ARRAY[i]);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************** Fill student data ********************************************/
void FILL_STUDENT_DATA_FUNC(S_STUDENTS_t *current_student)
{
    printf("\nEnter The Roll Number: ");
    scanf("%d", &current_student->ROLL);

    printf("Enter The First Name of student: ");
    scanf("%s", &current_student->FIRST_NAME);

    printf("Enter The Last Name of student: ");
    scanf("%s", &current_student->LAST_NAME);

    printf("Enter The GPA you obtained: ");
    scanf("%f", &current_student->GPA);

    printf("Enter The Course ID of each course\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Course %d ID: ", i + 1);
        scanf("%d", &current_student->COURSE[i]);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************** Find student by roll number ********************************************/
void FIND_STUDENT_BY_ROLL_FUNC()
{
    int search_roll = 0;
    printf("Enter your Roll Number of the student: ");
    scanf("%d", &search_roll);
    int c = 0;
    while (c < STUDENT_LIST.counter)
    {
        if (search_roll == STUDENT_ARRAY[c].ROLL)
        {
            printf("The Students Details are\n");
            printf("The First Name is %s\n", STUDENT_ARRAY[c].FIRST_NAME);
            printf("The Last Name is %s\n", STUDENT_ARRAY[c].LAST_NAME);
            printf("The GPA is %f \n", STUDENT_ARRAY[c].GPA);
            printf("Enter the course of each course\n");
            for (int i = 0; i < 5; i++)
            {
                printf("Course ID are: %d  \n", STUDENT_ARRAY[c].COURSE[i]);
            }
            return;
        }
        c++;
    }
    printf("[ERROR] Roll Number (%d) NOT found", search_roll);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************** Find student by 1st name ********************************************/
void FIND_STUDENT_BY_1st_NAME_FUNC()
{
    int flag = 1;
    char search_name[50];
    printf("Enter your First Name of the student: ");
    scanf("%s", &search_name);
    int c = 0;
    while (c < STUDENT_LIST.counter)
    {
        if (!stricmp(search_name, STUDENT_ARRAY[c].FIRST_NAME))
        {
            flag = 0;
            printf("The Students Details are\n");
            printf("The First Name is %s\n", STUDENT_ARRAY[c].FIRST_NAME);
            printf("The Last Name is %s\n", STUDENT_ARRAY[c].LAST_NAME);
            printf("The Roll number is %d\n", STUDENT_ARRAY[c].ROLL);
            printf("The GPA is %f \n", STUDENT_ARRAY[c].GPA);
            printf("Enter the course of each course\n");
            for (int i = 0; i < 5; i++)
            {
                printf("Course ID are: %d  \n", STUDENT_ARRAY[c].COURSE[i]);
            }
            printf("\n");
        }
        c++;
    }
    if (flag)
        printf("[ERROR] First Name (%s) NOT found", search_name);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************** Find student by course ********************************************/
void FIND_STUDENT_BY_COURSE_FUNC()
{
    int flag = 1;
    int course_id = 0;
    int c = 0;
    int stud = 0;
    printf("Enter The Course ID: ");
    scanf("%d", &course_id);
    while (c < STUDENT_LIST.counter)
    {
        int counter_course = 0;
        while (counter_course < 5)
        {
            if (course_id == (STUDENT_ARRAY[c].COURSE[counter_course]))
            {
                flag = 0;
                printf("\nThe Students Details are\n");
                printf("The First Name is %s\n", STUDENT_ARRAY[c].FIRST_NAME);
                printf("The Last Name is %s\n", STUDENT_ARRAY[c].LAST_NAME);
                printf("The Roll number is %d\n", STUDENT_ARRAY[c].ROLL);
                printf("The GPA is %f \n", STUDENT_ARRAY[c].GPA);
                stud++;
            }
            counter_course++;
        }
        c++;
    }
    if (flag)
        printf("[ERROR] Course ID (%d) NOT found", course_id);
    else
        printf("[INFO] Total Number of students Enrolled: %d", stud);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************** Find Total number of students ********************************************/
void FIND_TOTAL_STUDENTS_FUNC()
{
    printf("-------------------------------------------------------------\n");
    printf("[INFO] The total number of student is: %d\n", STUDENT_LIST.counter);
    printf("[INFO] You can add up to %d students\n", STUDENT_LIST.length);
    printf("[INFO] You can add %d more students\n", (55 - STUDENT_LIST.counter));
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************** Show all Students ********************************************/
void SHOW_ALL_STUDENTS()
{
    if (!STUDENT_LIST.counter)
    {
        printf("LIST IS EMPTY!!");
        return;
    }
    int c = 0;
    while (c < STUDENT_LIST.counter)
    {
        printf("The First Name is %s\n", STUDENT_ARRAY[c].FIRST_NAME);
        printf("The Last Name is %s\n", STUDENT_ARRAY[c].LAST_NAME);
        printf("The Roll number is %d\n", STUDENT_ARRAY[c].ROLL);
        printf("The GPA is %f \n", STUDENT_ARRAY[c].GPA);
        printf("Enter the course of each course\n");
        for (int i = 0; i < 5; i++)
        {
            printf("Course ID are: %d  \n", STUDENT_ARRAY[c].COURSE[i]);
        }
        printf("-------------------------------------------------------------\n");
        c++;
    }
    FIND_TOTAL_STUDENTS_FUNC();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************** Delete Student ********************************************/
void DELETE_STUDENT_BY_ROLL_FUNC()
{
    int flag = 1;
    int selected_roll;
    int c = 0;
    printf("Enter the Roll Number which you want to delete: ");
    scanf("%d", &selected_roll);
    while (c < STUDENT_LIST.counter)
    {
        if (selected_roll == STUDENT_ARRAY[c].ROLL)
        {
            STUDENT_LIST.counter--;
            flag = 0;
            int next = c;
            while (next < STUDENT_LIST.counter)
            {
                next++;
                STUDENT_ARRAY[next - 1] = STUDENT_ARRAY[next];
            }
            STUDENT_LIST.head--;
            printf("[INFO] Student Details is Removed successfully\n");
            return;
        }
        c++;
    }
    if (flag)
        printf("[ERROR] Roll Number (%d) NOT found\n", selected_roll);
    FIND_TOTAL_STUDENTS_FUNC();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************** Update Student's Data ********************************************/
void UPDATE_STUDENT_BY_ROLL_FUNC()
{
    int flag1 = 1;
    int selected_roll;
    int c = 0, cc = 0;
    int choice;
    int temp_roll;
    printf("Enter the Roll Number to update the entry: ");
    scanf("%d", &selected_roll);
    while (c < STUDENT_LIST.counter)
    {
        if (selected_roll == STUDENT_ARRAY[c].ROLL)
        {
            flag1 = 0;
            printf("\nChoose one of the following Options \n");
            printf("1. First Name\n");
            printf("2. Last Name\n");
            printf("3. Roll Number\n");
            printf("4. GPA\n");
            printf("5. Courses\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter The New First name: ");
                scanf("%s", &STUDENT_ARRAY[c].FIRST_NAME);
                break;
            case 2:
                printf("Enter The New Last name: ");
                scanf("%s", &STUDENT_ARRAY[c].LAST_NAME);
                break;
            case 3:
                printf("Enter The New Roll: ");
                scanf("%d", &temp_roll);
                while (cc < STUDENT_LIST.counter)
                {
                    if (temp_roll == STUDENT_ARRAY[cc].ROLL)
                    {
                        printf("[ERROR] Roll number (%d) is already taken\n", temp_roll);
                        printf("[INFO] Student Details is NOT updated successfully\n");
                        return;
                    }
                    cc++;
                }
                STUDENT_ARRAY[c].ROLL = temp_roll;
                break;
            case 4:
                printf("Enter The New GPA: ");
                scanf("%f", &STUDENT_ARRAY[c].GPA);
                break;
            case 5:
                printf("Enter The New Courses\n");
                for (int i = 0; i < 5; i++)
                {
                    printf("Course %d ID: ", i + 1);
                    scanf("%d", &STUDENT_ARRAY[c].COURSE[i]);
                }
                break;
            default:
                printf("\n Wrong option  :(");
                break;
            }
            printf("[INFO] UPDATED SUCCESSFULLY  ;) \n");
            return;
        }
        c++;
    }
    if (flag1)
        printf("[ERROR] Roll Number (%d) NOT found", selected_roll);
}