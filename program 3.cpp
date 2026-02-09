#include <stdio.h>

struct student
{
    int roll;
    char name[20];
    float marks;
    char grade;
};

int main()
{
    struct student s;

    printf("\nEnter student roll number: ");
    scanf("%d", &s.roll);

    printf("\nEnter student name: ");
    scanf(" %[^\n]", s.name);

    printf("\nEnter student marks: ");
    scanf("%f", &s.marks);

    printf("\nEnter student grade: ");
    scanf(" %c", &s.grade);

    printf("\nStudent roll number: %d\nStudent name: %s\nStudent marks: %.2f\nStudent grade: %c",
           s.roll, s.name, s.marks, s.grade);

    return 0;
}
