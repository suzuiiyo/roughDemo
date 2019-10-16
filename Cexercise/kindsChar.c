#include<stdio.h>
#include<stdlib.h>

int  main()
{
    char str[100];
    int i, vowels=0, consonants=0, digits=0, spaces=0;
    printf("enter the string: \n");
    fgets(str, sizeof(str)/sizeof(str[0]), stdin);

    for(i=0; i<sizeof (str)/sizeof(str[0]); ++i)
    {
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||
            str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
            ++vowels;
        else if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')
            ++consonants;
        else if(str[i]>='0'&&str[i]<='9')
            ++digits;
        else if(str[i]==' ')
            ++spaces;
    }

    printf("numbers of vowels, consonants, digits and spaces are succesively: %d %d %d %d",
         vowels, consonants, digits, spaces);
        
    return 0;
}