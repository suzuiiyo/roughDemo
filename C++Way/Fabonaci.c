#include <stdio.h>

int fabonaci(int a){
    if(a==1)
        return 1;
    else if (a==2)
        return 1;
    else if (a >=3)
        return (fabonaci(a-1) + fabonaci(a -2));
}

int main(){
    for(int i=1; i<10; i++){
        int a = fabonaci(i);
        printf("%d \n", a);
    }
}