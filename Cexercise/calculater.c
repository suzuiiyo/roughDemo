#include<stdio.h>

int main()
{
    float a, b;
    float plus, diffen, product;
    float quotient;
    printf("please enter two numbers to operate: ");
    scanf("%f %f", &a, &b);

    plus = a + b;
    printf("%.4f + %.4f = %.4f\n", a, b, plus);
    diffen = a - b;
    printf("%.4f - %.4f = %.4f\n", a, b, diffen);
    product = a*b;
    printf("%.4f * %.4f = %.4f\n", a, b, product);
    quotient = a/b;
    printf("%.4f / %.4f = %.4f\n", a, b, quotient);
}