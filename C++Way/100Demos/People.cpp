#include<iostream>
#include<string>

using namespace std;

class People{
    public : 
        void setName(string name);
        void setAge(int age);

        string getName();
        int getAge();
    
    private:
        string m_name;
        int m_age;
};

void People::setName(string name){
    m_name = name;
}

void People::setAge(int age){
    m_age = age;
}

string People::getName(){
    return m_name;
}

int People::getAge(){
    return m_age;
}

class Student: public People{
    public:
        void setScore(float score);
        float getScore();
    
    private:
        float m_score;
};

void Student::setScore (float score){
    m_score = score;
}

float Student::getScore(){
    return m_score;
}

int main(){
    Student stu;
    stu.setName("薛海若");
    stu.setAge(17);
    stu.setScore(99.78f);
    cout << stu.getName() << "的年龄是" << stu.getAge() << "岁, 成绩是" << stu.getScore()<<"分" << endl;

    return 0;
}