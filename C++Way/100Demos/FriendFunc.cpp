#include<iostream>
using namespace std;

class Student{
    public:
        Student(char *name, int age, float score);

        friend void show(Student *pstu);
    
    private:
        char *m_name;
        int m_age;
        float m_score;
};

Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){}

//非成员函数
void show(Student *pstu){
    cout<<pstu->m_name<<"的年龄是 "<<pstu->m_age<<",成绩是 "<<pstu->m_score<<endl;
}

int main(){
    Student stu((char*)"小明", 18, 97.7);
    show(&stu);           //调用友元函数
    Student *pstu = new Student((char*)"立方", 19, 98.6);
    show(pstu);          //调用友元函数

    return 0;
}