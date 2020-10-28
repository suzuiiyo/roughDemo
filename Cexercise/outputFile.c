#include<stdio.h>

int main()
{
    FILE *fp;
    char c;
    fp = fopen("runoob.txt","r");
    do{
        c = getc(fp);
        putchar(c);
    }
    while(c!=EOF);
    fclose(fp);
    return 0;
}