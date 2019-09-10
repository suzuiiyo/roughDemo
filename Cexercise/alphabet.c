#include<stdio.h>

int main()
{
    char letter;
    for(int i=0; ; i++)
    {
        letter = i;
        if((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
            printf("%c ", letter);
    }
    return 0;
}