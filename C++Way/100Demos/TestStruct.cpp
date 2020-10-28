#include<iostream>
#include<string>

using namespace std;

struct Student{
    Student(string name, int age, float score);
    void show();

    string m_name;
    int m_age;
    float m_score;
};

Student::Student(string name, int age, float score):m_name(name), m_age(age), m_score(score){}

void Student::show(){
    cout << m_name << "的年龄是" << m_age << ", 成绩是" << m_score << endl;
}

int main(){
    Student *pstu = new Student("青鸾", 18, 89.45f);
    pstu->show();

    Student stu1("山魈", 17, 98.45f);
    stu1.show();

    return 0;
}

