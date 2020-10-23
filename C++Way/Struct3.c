#include <stdio.h>

typedef struct Struct3
{
    /* data */
    unsigned char a;
    unsigned int b;
    unsigned char c;
} debug_size1_t;

typedef struct Struct3_2
{
    unsigned char a;
    unsigned char b;
    unsigned int c;
} debug_size2_t;

int main(void)
{
    printf("debug_size_t size=%lu, debug_size2_t size=%lu\r\n", sizeof(debug_size1_t), sizeof(debug_size2_t));
    return 0;
}
