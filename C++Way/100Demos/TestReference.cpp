#include <iostream>
#include <string>
using namespace std;

//不存在指向空值的引用，意味着使用引用的代码效率比使用指针的要高,因为在使用引用之前不需要测试它的合法性
void printDouble(const double &rd)
{
    cout << rd << endl;
}

void printDouble(const double *pd)
{
    if (pd)
    {
        cout << *pd << endl;
    }
}

int main()
{
    double d = 35.43;
    printDouble(d);
    printDouble(&d);

    string s1("Nancy");
    string s2("Clancy");
    string &rs = s1;  //rs引用s1
    string *ps = &s1; //ps指向s1
    rs = s2;          //rs仍旧引用s1
                      //把s2赋值给s1
                      //但是s1的现在值是"CLancy"
    ps = &s2;         //ps现在指向s2
                      //s1没有改变

    cout << "s1: " << s1 << endl
         << "s2: " << s2 << endl
         << "rs: " << rs << endl
         << "ps: " << *ps << endl;

    return 0;
}