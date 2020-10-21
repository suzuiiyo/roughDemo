#include<stdio.h>

void func_ppc(const char **n){
    printf("**n =  %c\n", **n);
}

void func_pc(const char *m){
    printf("*m = %c\n", *m);
}

void func_p(const char p){
    printf("p = %c\n", p);
}

int main(){
    char c = 'a';
    char *pc = &c;
    char **ppc = &pc;
    func_ppc(ppc);

    func_ppc(&pc);

    func_pc(pc);

    func_pc(&c);
    func_p(**ppc);

    return 1;
}