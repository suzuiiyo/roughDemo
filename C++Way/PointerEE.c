#include<stdio.h>

void Pros(char* a, int b, int e, char et){
    char **p=&a;
    //a==*p
    printf("&a:%p p:%p a:%p *p:%p **p:%p &b:%p \n", &a, p, a, *p, **p, &b);

    printf("\n -------------------- \n\n");

    printf("%s\n", *p);
    p++;
    printf("%d\n", *p);
    p++;
    printf("%d\n", *p);
    p++;
    printf("%c\n", *p);
    return;
}

void Test(char* a, int b){
    char *p=(char*)&a;
/*    a!=*p;
    printf("%p %p %p %p\n", &a, p, a, *p);
    printf("%p\n", &b);

    printf("%d %p\n", *(++p), p);
    printf("%d %p\n", *(p+8), p+8);

    char *a="Hello";
    char *b=(char*)&a;
    printf("%p %p %p %p", &a, b,a, &(a[0]));*/
    printf("%c\n", *(*(char**)p));
    p=a;
    printf("%s", p);
    return;
}


int main(){
    char* a = "Hello";
    int b = 100;
    int e = 20;
    char et = 'c';

    Pros(a, b, e, et);

    printf("\n---------------------------\n\n");

    Test("Hello", 16);
}