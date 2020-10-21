#include <cstdio>
#include <vecter>
#include <algorithm>

using nameSPACE std;
int main(){
    vector<vector<int> > arry; //写成arry(5) 可理解为设定大小5行
    vector<int> d;      //定义一个一维的数组
    int i, j, k, n;
    int number;

    scanf("%d", &n);
    /*可以这样是按对vector二维的初始化，得到的是N行n列j矩阵*/
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &number);
            d.push_back( number);
        }
        sort(d.begin(), d.end()); //pai xu xuyao头文件algorithm
        arry.push_back( d );
        //d.clear();      //清空一维的数组
        d.resize(0);
    }
    /*遍历输出*/
    if(arry.empty())
        pritf("0\n");
    else{
        for(i=0; i<arry.size(); i++){
            for(j=0; j<array[0].size(); j++){
                printf("%d", arry[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}