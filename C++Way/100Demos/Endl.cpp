#include<iostream>

using namespace std;
void out1(){
    cout<<"Hello, World."<<endl;
}

void out2(){
    std::cout<<"Hello, World."<<std::endl;
}

void out3(){
    std::cout<<"Hello, World."<<&std::endl;
}

int main(int argc, char *argv[]){
    out1();
    out2();
    out3();
    return 0;
}