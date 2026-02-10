#include <stdio.h>

struct dob
{
    int day, month, year;
};

struct student
{
    int roll;
    char name[20];
    struct dob d;
} s1;

int main()
{
    printf("\nEnter student roll number: ");
    scanf("%d", &s1.roll);

    printf("\nEnter student name: ");
    scanf("%s", s1.name);

    printf("\nEnter student date of birth (dd mm yy): ");
    scanf("%d %d %d", &s1.d.day, &s1.d.month, &s1.d.year);

    printf("\nStudent roll = %d", s1.roll);
    printf("\nStudent name = %s", s1.name);
    printf("\nStudent date of birth = %d-%d-%d", s1.d.day, s1.d.month, s1.d.year);

    return 0;
}
