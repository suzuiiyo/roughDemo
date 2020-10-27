#include<stdio.h>
#include<iostream>

using namespace std;

class Student{
    public:
        Student(char *name, int age, float score);
        Student();
        void show();

        char *getName() const;
        int getAge() const;
        float getScore() const;

        void setName(char* name);
        void setAge(int age);
        void setScore(float score);
        
    private:
        char *m_name;
        int m_age;
        float m_score;
};

Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){};
Student::Student(){};

void Student::show(){
    cout<<m_name<<"的年龄是"<<m_age<<", 成绩是"<<m_score<<endl;
}

//定义常成员函数
char *Student::getName() const{
    return m_name;
}

int Student::getAge() const{
    return m_age;
}

float Student::getScore() const{
    return m_score;
}

void Student::setName(char* name) {
    m_name = name;
}

void Student::setAge(int age) {
    m_age = age;
}

void Student::setScore(float score) {
    m_score = score;
}

int main(){
    Student *stu = new Student((char*)"傅里叶", 17, 99);
    stu -> show();
    delete stu;

    Student stu1;
    stu1.setName((char*)"天灵盖");
    stu1.setAge(18);
    stu1.setScore(89);
    stu1.show();
}