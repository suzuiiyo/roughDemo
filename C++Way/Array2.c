#include <stdio.h>

int main(){
    char *str="Hello";
    char arrgs[]="Hello";

    //char *p=(char*)&arrgs == char *p=arrgs;
    //char *p=(char*)(&(arrgs[0])) == &arrgs == arrgs;

    //char *p=(char*)&str != str; 
    //str==str[0] == 'H';

    //for(int i=0; i<sizeof(arrgs); i++){
    //    printf(arrgs[i]);
    //}
    printf(arrgs);
}