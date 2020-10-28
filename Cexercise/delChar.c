#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, j;
    char line[150];
    printf("enter a cahracter string: \n");
    fgets(line, (sizeof line / sizeof line[0]), stdin);

    for(i=0; line[i] != '\0'; ++i)
    {
        if(!((line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<='Z')||line[i]=='\0'))
        {
            for(j=i; line[j]!='\0'; ++j)
            {
                line[j]=line[j+1];
            }
            line[j]='\0';
        }

        
    }
    printf("puts: ");
    puts(line);
    return 0;
}