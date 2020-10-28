#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main(){
    vector<int> v(10);      //建立整形向量(vector), 大小为10
                            //向量是一个在标准c库中的一个模板
    v[5] = 10;              //这个被赋值的目标对象就是操作符[]返回的值

    cout << v[5] << endl;

    return 0;
}