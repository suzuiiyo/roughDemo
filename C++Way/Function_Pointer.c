#include <stdio.h>

void func1(int *a, int **b)
{
    (*a)++;
    (*b)++;//这里虽然传进来的是指针形式，但其实是指针c的地址，
            //可以认为这里本质还是值传递，只不过这个值是地址值
}

int main(){
    int a[2] = {10, 20};
    int *b   = &a[0];
    int *c   = a + 1;
    int **d  = &c;

    func1(b, d);
    printf("%p %p %p\n", *b, *c, **d);
    printf("a[0]=%d  a[1]=%d\n", a[0], a[1]);

    return 0;
}