#include <iostream>
using namespace std;

class Student{
    private:
        char *m_name;
        int m_age;
        float m_score;

    public:
        //声明构造函数
        Student();
        Student(char *name, int age, float score);

        void setName(char *name);
        void setAge(int age);
        void setScore(float score);
        void show();
};

Student::Student(){
    m_name = NULL;
    m_age = 0;
    m_score = 0.0;
}

Student::Student(char *name, int age, float score){
    m_name = name;
    m_age = age;
    m_score = score;
}

void Student::show(){
    if(m_name == NULL || m_age <=0){
        cout<<"成员变量还未初始化"<<endl;
    }
    else{
        cout<<m_name<<"的年纪是"<<m_age<<", 成绩是"<<m_score<<endl;
    }
}

void Student::setName(char *name){
    m_name = name;
}

void Student::setAge(int age){
    m_age = age;
}

void Student::setScore(float score){
    m_score = score;
}

int main(){
    Student stu1((char*)"小明", 15, 92.5f);
    stu1.show();
    //创建对象向x构造函数传参
    Student *stu2 = new Student();
    stu2 -> show();
    stu2 -> setName((char*)"梨花");
    stu2 -> setAge(16);
    stu2 -> setScore(96.7f);
    stu2 -> show();
    delete stu2;

    return 0;
}