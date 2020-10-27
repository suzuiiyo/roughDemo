#include<iostream>

using namespace std;

class Student{
    public:
        void setName(char *name);
        void setAge(int age);
        void setScore(float score);
        void show();
        void printThis();

    private:
        char *name;
        int age;
        float score;
};

void Student::setName(char *name){
    this->name = name;
}

void Student::setAge(int age){
    this->age = age;
}

void Student::setScore(float score){
    this->score = score;
}

void Student::show(){
    cout<<this->name<<"的年龄是"<<this->age<<", 成绩是"<<this->score<<endl;
}

void Student::printThis(){
    cout<<this<<endl;
}

int main(){
    Student *pstu = new Student;
    pstu -> setName((char *)"梨花");
    pstu -> setAge(17);
    pstu -> setScore(97.5);
    pstu -> show();

    //打印this
    pstu -> printThis();
    cout<<pstu<<endl;

    Student *pstu1 = new Student;
    pstu1 -> printThis();
    cout<<pstu1<<endl;

    delete pstu;
    return 0;
}