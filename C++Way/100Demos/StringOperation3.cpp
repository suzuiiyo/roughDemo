#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1, s2, s3;
    s1 = s2 = s3 = "1234567890";
    s2.erase(5);
    s3.erase(5, 3);

    cout << s1 << endl
         << s2 << endl
         << s3 << endl;

    return 0;
}