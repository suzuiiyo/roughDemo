#include<stdio.h>
#include<math.h>

int main()
{
    double a, b, c;
    double x1, x2;
    double delta;
    char ch;
    
    do
    {
        printf("请输入一元二次方程的三个系数，依次用空格隔开: ");
        scanf("%lf %lf %lf", &a, &b, &c);
        delta = b*b - 4*a*c;
        if(delta > 0)
        {
            x1 = ( -b + sqrt(delta)) / 2;
            x2 = ( -b - sqrt(delta)) / 2;
            printf("方程%lfx^2+%lfx+%lf=0有两个不等的实数根: x1 = %lf x2 = %lf\n", a, b, c, x1, x2);
        }
        else if(delta = 0)
        {
            x1 = ( -b + sqrt(delta)) / 2;
            printf("方程%lfx^2+%lfx+%lf=0有两个相等的实数根: x1 = x2 = %lf\n", a, b, c,x1);
        }
        else
            printf("方程%lfx^2+%lfx+%lf=0没有实数根\n", a, b, c); 

        printf("是否继续求解方程: Y/N\n");    
        scanf("%c", &ch);
        getchar();
    }while (ch == 'y' || ch == 'Y');
    return 0;
}