//
// Created by yanGw on 2021/3/15.
//

using namespace std;

class Demo
{
public:
    Demo();
    Demo(double a);
    Demo(int a, double b);
    Demo(int a, int b=10, double c=1.6);
    ~Demo();
    void Func(void);

private:
    int value1;
    int value2;
};