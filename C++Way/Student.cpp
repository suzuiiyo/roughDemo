#include<stdio.h>
#include<iostream>

using namespace std;
class Student{
    public:
    //类包含的变量
        char *name;
        int age;
        float score;

    //类包含的函数
        void say(){
            cout<<name<<"的年龄是"<<age<<", 成绩是"<<score<<endl;
        }
};

int main(){
    Student stu1;
    stu1.name = (char*)"小华";
    stu1.age = 23;
    stu1.score = 99.5f;

    stu1.say();
    
    return 0;
}