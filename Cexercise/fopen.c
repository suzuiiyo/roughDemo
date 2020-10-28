#include<stdio.h>

int main()
{
    FILE *fp = NULL;
    char buff[255];

    fp = fopen("C:/Users/GDWY_YG/Desktop/Studio/C/WorkSpace/tmp/test.txt", "w+");
    fprintf(fp, "This is testing for fprinf...\n");
    fputs("This is testing for fputs...\n", fp);
    fclose(fp);

    fp = fopen("C:/Users/GDWY_YG/Desktop/Studio/C/WorkSpace/tmp/test.txt", "r");
    fscanf(fp, "%s", buff);
    printf("1: %s\n", buff);

    fgets(buff, 255, (FILE*)fp);
    printf("2: %s\n", buff);

    fgets(buff, 255, (FILE*)fp);
    printf("3: %s\n", buff);
    fclose(fp);
    
    fp = fopen("C:/Users/GDWY_YG/Desktop/Studio/C/WorkSpace/tmp/test.txt", "r+");
    fprintf(fp, "This is testing for fprintf...\n");
    fseek(fp, 10, SEEK_SET);
    if(fputc(72, fp) == EOF)
    {
        printf("fputc fail");
    }
    fclose(fp);
}
