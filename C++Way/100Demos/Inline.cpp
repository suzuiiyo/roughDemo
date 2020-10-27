#include<iostream>

using namespace std;
class Student{
    public:
        char *name;
        int age;
        float score;

        void say();   //内联函数声明, 可以增加inline关键字，但是编译器会忽略
};

//函数定义
inline void Student::say(){
    cout<<name<<"的年龄是"<<age<<", 成绩是"<<score<<endl;
}

int main(){
    Student *stu1 = new Student;
    stu1 -> name = (char*)"天玄";
    stu1 -> age = 43;
    stu1 -> score = 56.43;
    stu1 -> say();
    delete stu1;

    Student stu2;
    stu2.name = (char*)"淼淼";
    stu2.age = 17;
    stu2.score = 34.67;
    stu2.say();
}