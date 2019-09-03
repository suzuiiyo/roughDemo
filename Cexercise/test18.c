#include<stdio.h>
#include<math.h>
int main()
{
    int i,j;
    printf("100以内的素数有：\n");
    for(i=2; i<100; i++){
        for(j=2; j<sqrt(i); j++){
            if(i%j==0){
                break;
            }
        }
           // if(j>sqrt(i)){
                printf("%d,\t", i);
          //  }
    }
}
