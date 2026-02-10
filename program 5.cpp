#include <stdio.h>
#include <string.h>

struct copying
{
    int roll;
    float marks;
    char name[20];
};

int main()
{
    struct copying s1, s2;

    s1.roll = 101;
    s1.marks = 99.5;
    strcpy(s1.name, "Kavya");   

    s2 = s1;  

    printf("\nStudent roll number: %d", s2.roll);
    printf("\nStudent marks: %.2f", s2.marks);
    printf("\nStudent name: %s", s2.name);

    return 0;
}
