#include<iostream>
#include<string>

using namespace std;

int main(){
    string s1 = "first ";
    string s2 = "sencond ";
    char *s3 = "third ";
    char s4[] = "fourth ";
    char ch = ' @';

    string s5 = s1 + s2;
    string s6 = s1 + s3;
    string s7 = s1 + s4;
    string s8 = s1 + ch;

    cout << s5 << endl
         << s6 << endl
         << s7 << endl
         << s8 << endl;

    return 0;
}