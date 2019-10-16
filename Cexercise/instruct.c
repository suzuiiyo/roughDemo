#include<stdio.h>

struct student
{
    char name[50];
    int roll;
    float marks;
} s;

int main()
{
    printf("enter the infomation: \n");

    printf("name: ");
    scanf("%s", s.name);

    printf("number: ");
    scanf("%d", &s.roll);

    printf("mark: ");
    scanf("%f", &s.marks);

    printf("show the information: \n");

    printf("name: ");
    puts(s.name);

    printf("number: %d\n marks: %.1f\n", s.roll, s.marks);

    return 0;
}