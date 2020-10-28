#include<iostream>
#include<string>
using namespace std;

class Address;

class Student{
    public:
        Student();
        Student(string name, int age, float score);
    
    public:
        void show(Address *addr);

    private:
        string m_name;
        int m_age;
        float m_score;
};

class Address{
    public:
        Address(string province, string city, string ditrict);
    
    public:
        //将Student类声明为Address类的友元类
        friend class Student;
    
    private:
        string m_province;
        string m_city;
        string m_district;
};

Student::Student(){}
Student::Student(string name, int age, float score):m_name(name), m_age(age), m_score(score){}

void Student::show(Address *addr){
    cout << m_name << "的年龄是 " << m_age << ",成绩是 " << m_score << endl;
    cout << "家庭住址" << addr->m_province << "省" << addr->m_city << "市" << addr->m_district << "区" << endl;
}

Address::Address(string province, string city, string district):m_province(province), m_city(city), m_district(district){}

int main(){
    Student stu("小明", 16, 95.5f);
    Address addr("陕西", "西安", "阎罗");
    stu.show(&addr);

    Student *pstu = new Student("李磊", 16, 89.5);
    Address *paddr = new Address("河北", "衡水", "桃城");
    pstu->show(paddr);

    return 0;
}