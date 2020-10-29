#include <iostream>
#include <string>

using namespace std;

class People
{
public:
    void show();

    void setName(string name);
    void setAge(int age);
    string getName();
    int getAge();

protected:
    string m_name;
    int m_age;
};

void People::show()
{
    cout << m_name << "的年龄是" << m_age << endl;
}

void People::setName(string name)
{
    m_name = name;
}

void People::setAge(int age)
{
    m_age = age;
}

string People::getName()
{
    return m_name;
}

int People::getAge()
{
    return m_age;
}

class Student : public People
{
public:
    void learning();

public:
    using People::m_age;  //将protected改为public
    using People::m_name; //将protected改为public
    float m_score;

private:
    using People::show; //将public改为private
};

void Student::learning()
{
    cout << "我是" << m_name << ", 今年" << m_age << "岁， 这次考了" << m_score << "分!" << endl;
}

int main()
{
    Student stu;
    stu.m_name = "阿格斯之盾";
    stu.m_age = 16;
    stu.m_score = 99.56f;
    //stu.show();
    stu.learning();

    People ppl;
    ppl.setName("北郡牧师");
    ppl.setAge(17);
    ppl.show();

    return 0;
}