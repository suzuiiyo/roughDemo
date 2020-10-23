#include <stdio.h>

void change(int *tmp_t){
    *tmp_t = 1;
    return;
}

void func(void){
    int tmp = 0;
    change(&tmp);
    printf("######## tmp = %d", tmp);

    return;
}

int main(){
    func();
}