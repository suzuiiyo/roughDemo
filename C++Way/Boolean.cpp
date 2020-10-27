//使用boolalpha输出为bool类型
//使用noboolalpha输出为数字类型

#include<iostream>

using namespace std;

int main(){
    int a, b;
    bool flag;
    cout<<"请依次输入a, b的值:"<<endl;
    cin>>a>>b;
    flag = a > b;
    cout<<"flag is "<<flag<<endl;
    cout<<"flag is "<<boolalpha<<flag<<endl;
    //cout<<"flag is "<<noboolalpha<<flag<<endl;

    if(flag){
        cout<<"As time goes by"<<endl;
    }

    return 0;
}