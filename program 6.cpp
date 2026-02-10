#include <stdio.h>

void display(int a, float b);

struct student
{
    int roll;
    float marks;
};

int main()
{
    struct student s;

    printf("\nEnter student roll number: ");
    scanf("%d", &s.roll);

    printf("\nEnter student marks: ");
    scanf("%f", &s.marks);

    display(s.roll, s.marks);

    return 0;
}

void display(int a, float b)
{
    printf("\nStudent roll number: %d", a);
    printf("\nStudent marks: %.2f", b);
}
