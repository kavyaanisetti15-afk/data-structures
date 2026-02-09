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
    struct student s = {101, "kavya", 98.26, 'O'};

    printf("Student Roll Number: %d\nStudent Name: %s\nStudent Marks: %.2f\nStudent Grade: %c",
           s.roll, s.name, s.marks, s.grade);

    return 0;
}
