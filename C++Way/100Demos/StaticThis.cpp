#include<stdio.h>
#include<iostream>

using namespace std;
class Student{
    public:
        Student(char *name, int age, float score);
        void show();

        static int m_total;

    private:
        char *m_name;
        int m_age;
        float m_score;
};

int Student::m_total = 0;

Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){
    m_total++;          //操j静态成员变量
}

void Student::show(){
    cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<"(当前共有"<<m_total<<"名学生)"<<endl;
}

int main(){
    //创建匿名对象
    (new Student((char*)"小明", 15, 90)) -> show();
    (new Student((char*)"梨花", 16, 87)) -> show();
    (new Student((char*)"梅姐", 17, 95)) -> show();
    (new Student((char*)"华子", 15, 99)) -> show();

    return 0;
}