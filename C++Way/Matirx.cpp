#include<iostream>
using namespace std;
int main(){
    int a[5][5], m, n, i, j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++)
            cin >> a[i][j];
    }
    cin >> m >> n;
    for(j =0 ; j<5; j++){
        i=a[m-1][j];
        a[m-1][j] - a[n-1][j];
        a[n-1][j] - i;
    }
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}