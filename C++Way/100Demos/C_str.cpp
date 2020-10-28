#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cout << "请输入字符串" << endl;
    cin >> s;
    cout << s << endl;

    string path = "a:/never.txt";
    cout << path << endl;
    FILE *fp = fopen(path.c_str(), "rt");
}