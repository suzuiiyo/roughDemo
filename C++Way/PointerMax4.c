#include <stdio.h>

//回调函数a
void callback_a(int var_a){
    printf("Call callback_a, var: %d\n\n", var_a);
}

//回调函数b
void callback_b(int var_b){
    printf("Call callback_b, var: %d\n\n", var_b);
}

//回调动作
void callback_act(int x, void (*callback)(int var)){
    printf("Call callback_act, var_x; %d\n\n", x);
    callback(x);
}


void main(){
    int a = 1, b = 2;
    callback_act(a, callback_a);
    callback_act(b, callback_b);
    printf("Main program has done.");
}