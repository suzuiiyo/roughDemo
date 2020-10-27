#include<iostream>

using namespace std;

void func(int, int);
void func(char, int, float);
void func(char, long, double);

int main(){
    short n = 99;
    func('@', n, 99);
    func('@', n, 99.5);
    getchar();
    return 0;
}