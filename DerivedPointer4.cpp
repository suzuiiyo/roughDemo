//
// Created by yanGw on 2020/11/2.
//

#include<iostream>
#include<string>

using namespace std;

//基类People
class People {
public:
    People(string name, int age);

    virtual void display();             //声明为虚函数

protected:
    string m_name;
    int m_age;
};

People::People(string name, int age) {
    m_name = name;
    m_age = age;
}

void People::display() {
    cout << m_name << "今年" << m_age << "岁了， 是个无业游民." << endl;
}

class Teacher : public People {
public:
    Teacher(string name, int age, int salary);

    virtual void display();         //声明为虚函数

private:
    int m_salary;
};

Teacher::Teacher(string name, int age, int salary) : People(name, age), m_salary(salary) {}

void Teacher::display() {
    cout << m_name << "今年" << m_age << "岁了， 是一名教师， 每月有" << m_salary << "元的收入." << endl;
}

int main() {
    //基类指针指向派生类对象
    People *p = new People("铁子", 23);
    p->display();

    p = new Teacher("小白", 45, 8200);

    p->display();

    return 0;
}