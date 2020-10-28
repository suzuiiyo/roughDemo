#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fptr;
    //char *str;
    char str[100];
    //int n;
    //str = (char *)calloc(n, sizeof(char));
    //printf("enter the number of char: \n");
    //scanf("%d", &n);

    fptr = fopen("runoob.txt", "w");
    if(fptr == NULL)
    {
        printf("ERROR!");
        exit(1);
    }

    printf("enter the string: \n");
    fgets(str, (sizeof str/sizeof str[0]), stdin);
    //fgets(str, n, stdin);

    fprintf(fptr, "%s", str);
    fclose(fptr);

    return 0;
}