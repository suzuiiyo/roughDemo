#include<stdio.h>
#include<math.h>

int checkPrime(int n);

int main()
{
    int flag=0;
    int num;
    printf("please enter a number£º");
    scanf("%d", &num);

    for(int i=2; i<num/2; i++)
    {
        if(checkPrime(i)==1)
        {
            if(checkPrime(num-i)==1)
            {
                printf("%d+%d=%d\n", i, num-i, num);
                flag = 1;
            }
        }
    }
    if(flag==0)
        printf("%d can't be divided to two primes.", num);
    
    return 0;
}

int checkPrime(int n)
{
    int i, isPrime = 1;
    for(i=2; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            isPrime = 0;
            break;
        }
    }
    return isPrime;
}