#include<stdio.h>

using namespace std;

int sum(int n){
    int total = 0;
    //在fox循环的条件语句内部定义变量i
    for(int i=1; i<=n; i++){
        total += i;
    }
    return total;
}

int main(){
    cout<<"Input a integer: ";
    int n;
    cin>>n;
    cout<<"Total: "<<sum(n)<<endl;

    return 0;
}