#include <iostream>
using namespace std;

int main(){
    int b = 2;
    {
        int b = 1;
        cout << "b = " << b <<endl;
    }
    cout << "b = " << b <<endl;
}