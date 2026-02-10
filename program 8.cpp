#include <stdio.h>

struct student
{
    int roll;
    float marks;
};

void display(struct student *a);

int main()
{
    struct student s;

    printf("\nEnter student roll number: ");
    scanf("%d", &s.roll);

    printf("\nEnter student marks: ");
    scanf("%f", &s.marks);

    display(&s);

    return 0;
}

void display(struct student *a)
{
    printf("\nStudent roll number = %d", a->roll);
    printf("\nStudent marks = %.2f", a->marks);
}
