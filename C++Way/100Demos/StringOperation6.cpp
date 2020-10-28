#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "first second second third";
    string s2 = "asecond";
    int index = s1.find_first_of(s2);
    if (index < s1.length())
        cout << "Found at index : " << index << endl;
    else
        cout << "Not found" << endl;

    return 0;
}