#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    string s2 = "c plus plus";
    string s3 = s2;
    string s4(5, 's');

    cout << s1 << "\n"
         << s2 << "\n"
         << s3 << "\n"
         << s4 << endl;

    string s = "http://dashetianxia.net";
    int len = s.length();
    cout << len << endl;

    return 0;
}