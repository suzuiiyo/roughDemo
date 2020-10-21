#include<iostream>
using namespace std;

int main(){
    enum rank{
        first, second, third
    };

    int nRank=1;
    switch(nRank){
        case first:
            cout << "第一名";
            break;
        
        case second:
            cout << "第二名";
            break;
        
        case third:
            cout << "第三名";
            break;
        
        default:
            break;
    }
    //system("pause");
    return 0;
}