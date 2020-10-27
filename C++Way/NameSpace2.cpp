#include<iostream>
#include<string>

int main(){
    using namespace std;

    string str;

    int age;

    //cout<<"请依次输入站名和年限，以回车隔开"<<endl;
    printf_s("请依次输入站名和年限,以回车隔开");

    cin>>str>>age;

    cout<<str<<"已经成立"<<age<<"年了!"<<endl;

    return 0;
}