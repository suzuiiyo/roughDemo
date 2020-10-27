#include<iostream>
#include<string.h>
using namespace std;

class Address;          //提前声明Address类

//声明Student类
class Student{
    public:
        Student(char *name, int age, float score);
        void show(Address *adr);
    
    private:
        string m_name;
        int m_age;
        float m_score;
};

class Address{
    private:
        char *m_province; 
        char *m_city;
        char *m_district;
    
    public:
        Address(char *provice, char *city, char *district);
        //将Student类中的成员函数show()声明为友元函数
        friend void Student::show(Address *addr);
};

Student::Student(string name, int age, float score): m_name(name), m_age(age), m_score(score){}
void Student::show(Address *addr){
    cout<<m_name<<"的年龄是 "<<m_age<<", 成绩是 "<<m_score<<endl;
    cout<<"家庭住址："<<addr->m_province<<"省"<<addr->m_city<<"市"<<addr->m_district<<"区"<<endl;
}

//实现Address类
Address::Address(char *provice, char *city, char *district):m_province(provice), m_city(city), m_district(district){};

int main(){
    Student stu("蒲里昂", 16, 95.6f);
    Address addr((char*)"湖北", (char*)"武汉", (char*)"将军路");
    stu.show(&addr);

    Student *stu1 = new Student("梁天", 18, 97.77f);
    Address *addr1 = new Address((char*)"湖南", "长沙", "大栅栏");
    stu1 -> show(addr1);

    return 0;
}