#include<stdio.h>

int main()
{
    int integerType;
    float floatType;
    double doubleType;
    char charType;

    printf("size of int: %ld bytes\n", sizeof(integerType));
    printf("size of float: %ld bytes\n", sizeof(floatType));
    printf("size of double: %ld bytes\n", sizeof(doubleType));
    printf("size of char: %ld bytes\n", sizeof(charType));
}

