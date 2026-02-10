#include <stdio.h>

struct student
{
    int marks;
};

int main()
{
    struct student s[100];
    int n, i, total = 0;
    float avg;

    printf("\nEnter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter student %d marks: ", i + 1);
        scanf("%d", &s[i].marks);
        total = total + s[i].marks;
    }

    avg = (float) total / n;

    printf("\nTotal = %d", total);
    printf("\nAverage = %.2f", avg);

    return 0;
}
