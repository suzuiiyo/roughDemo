#include <stdio.h>

typedef struct
{
    unsigned char a;
    unsigned int  b;
    unsigned char c;
} debug_size1_t;

typedef struct
{
    unsigned char a;
    unsigned char b;
    unsigned int  c;
} debug_size2_t;

int main(void)
{
    printf("debug_size1_t size=%lu,debug_size2_t size=%lu\r\n", sizeof(debug_size1_t), sizeof(debug_size2_t));
    return 0;
}