#include<iostream>
#include<string>

using namespace std;

class People{
    public:
        void show();
    
    protected:
        string m_name;
        int m_age;
};

void People::show(){
    cout << "嗨，大家好，我叫" << m_name << ", 今年" << m_age << "岁" << endl;
}

//派生类student
class Student:public People{
    public:
        Student(string name, int age, float score);
        void show();         //遮j基类的show()
    
    private:
        float m_score;
};

Student::Student(string name, int age, float score){
    m_name = name;
    m_age = age;
    m_score = score;
}

void Student::show(){
    cout << m_name << "的年龄是" << m_age << ", 成绩是" << m_score << endl;
}

int main(){
    Student stu("小明", 16, 90.5f);
    stu.show();

    stu.People::show();

    return 0;
}