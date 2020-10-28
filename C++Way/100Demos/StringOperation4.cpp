#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "first second third";
    string s2;

    s2 = s1.substr(6, 6);
    cout << s1 << endl;
    cout << s2 << endl;

    return 0;
}