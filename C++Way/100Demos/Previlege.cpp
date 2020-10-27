#include<iostream>
using namespace std;

class Student{
    private:
        char *m_name;
        int m_age;
        float m_score;

    public:
        void setName(char *name);
        void setAge(int age);
        void setScore(float score);
        void show();
};

//成员函数的定义
void Student::setName(char *name){
    m_name = name;
}

void Student::setAge(int age){
    m_age = age;
}

void Student::setScore(float score){
    m_score = score;
}

void Student::show(){
    cout<<m_name<<"的年龄是"<<m_age<<",成绩是"<<m_score<<endl;
}

int main(){
    //在栈上创建对象
    Student stu;
    stu.setName((char*)"小明");
    stu.setAge(19);
    stu.setScore(92.5f);
    stu.show();

    //在堆上创建对象
    Student *stu1 = new Student;
    stu1 -> setName((char*)"梨花");
    stu1 -> setAge(16);
    stu1 -> setScore(96.77f);
    stu1 -> show();
    delete stu1;

    return 0;
}