#include<stdio.h>
#include<iostream>

using namespace std;

class Student{
    public:
        Student(char *name, int age, float score);
        void show();
    
    public:
        static int getTotal();
        static float getPoints();

    private:
        static int m_total;
        static float m_points;
    
    private:
        char *m_name;
        int m_age;
        float m_score;
};

int Student::m_total = 0;
float Student::m_points = 0.0;

//构造函数
Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){
    m_total++;
    m_points += score;
}

void Student::show(){
    cout<<m_name<<"的年龄是"<<m_age<<",成绩是"<<m_score<<endl;
}

int Student::getTotal(){
    return m_total;
}

float Student::getPoints(){
    return m_points;
}

int main(){
    //匿名对象
    (new Student((char*)"天王老子", 18, 78.5)) -> show();
    (new Student((char*)"玉皇大帝", 19, 80.5)) -> show();
    (new Student((char*)"王母娘娘", 17, 88.5)) -> show();
    (new Student((char*)"三清真人", 20, 97.5)) -> show();
    (new Student((char*)"真武大帝", 19, 76.5)) -> show();

    int total = Student::getTotal();
    float points = Student::getPoints();
    cout<<"当前共有"<<total<<"名神仙，总成绩是"<<points<<", 平均分是"<<points/total<<endl;

    return 0;
}

