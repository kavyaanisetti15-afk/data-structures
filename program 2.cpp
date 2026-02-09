#include <stdio.h>
#include <string.h>

struct student
{
    int roll;
    char name[20];
    float marks;
    char grade;
};

int main() 
{
    struct student s1;

    s1.roll = 101;
    strcpy(s1.name, "kavya");
    s1.marks = 99.12;
    s1.grade = 'O';

    printf("\nSize of the s1 variable = %d", sizeof(s1));
    printf("\nStudent roll = %d\nStudent name = %s\nStudent marks = %.2f\nStudent grade = %c",
           s1.roll, s1.name, s1.marks, s1.grade);

    return 0;
}
