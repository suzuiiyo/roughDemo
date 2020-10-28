#include<iostream>
#include<string>

using namespace std;

void g(string &a, const string &b){
    cout << "a address :" << &a << endl;
    cout << "b address :" << &b << endl;
}

string f(){}

int main(){
    string input = "I love you";
    int a = 1;
    cout << "input address: " << &input << endl;
    const char *b = "****";
    cout << "b address: " << &b << endl;

    g(input, b);

    //getchar();

    return 0;
}

