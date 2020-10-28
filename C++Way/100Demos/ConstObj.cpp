#include<stdio.h>
#include<iostream>

using namespace std;

class Student{
    public:
        Student(char *name, int age, float score);
    
        void show() const;
        void show1();

        char *getName() const;
        int getAge() const;
        float getScore() const;
    
    private:
        char *m_name;
        int m_age;
        float m_score;
};

Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){}

void Student::show() const{
    cout<<m_name<<"的年龄是"<<m_age<<", 成绩是"<<m_score<<endl;
}

void Student::show1() {
    cout<<"再来一遍:"<<m_name<<"的年龄是"<<m_age<<", 成绩是"<<m_score<<endl;
}

char *Student::getName() const{
    return m_name;
}

int Student::getAge() const{
    return m_age;
}

float Student::getScore() const{
    return m_score;
}

int main(){
    //cost对象
    const Student stu((char*)"小明", 15, 90.6);
    stu.show();
    //stu.show1();    

    Student stu1((char*)"梨花", 17, 94.3);
    stu1.show();
    stu1.show1();

    const Student *pstu = new Student((char*)"梅姐", 18, 99.5);
    pstu -> show();
    //pstu -> show1();
    delete pstu;

    Student *pstu1 = new Student((char*)"飞鸿", 17, 87.4);
    pstu1 -> show();
    pstu1 -> show1();
    delete pstu1;
}