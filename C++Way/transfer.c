#include <stdio.h>

int change(int tmp_t){
    tmp_t = 1;
    return tmp_t;
}

void fun(void)
{
    int tmp = 0;
    tmp = change(tmp);
    printf("###################\n\n tmp = %d", tmp);

    return;
}


int main(){
    fun();
}