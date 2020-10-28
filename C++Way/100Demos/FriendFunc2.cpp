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

        void setName(string name);
        void setAge(int age);
        void setScore(float score);

        string getName();
        int getAge();
        float getScore();

    private:
        string m_name;
        int m_age;
        float m_score;
};

class Address{
    public:
        Address(string province, string city, string district);
        friend void Student::show(Address *addr);

    private:
        string m_province;
        string m_city;
        string m_district;
};

Student::Student(string name, int age, float score):m_name(name), m_age(age), m_score(score){}
Student::Student(){}

Address::Address(string province, string city, string district):m_province(province), m_city(city), m_district(district){}

void Student::show(Address *addr){
    cout << m_name << "年龄" << m_age << ",成绩是:" << m_score << endl;
    cout << "家庭地址" << addr -> m_province << "省" << addr -> m_city << "市" << addr -> m_district << "区" << endl;
}

void Student::setName(string name){
    m_name = name;
}

void Student::setAge(int age){
    m_age = age;
}

void Student::setScore(float score){
    m_score = score;
}

string Student::getName(){
    return m_name;
}

int Student::getAge(){
    return m_age;
}

float Student::getScore(){
    return m_score;
}

int main(){
    Student stu1;
    stu1.setName("穷奇");
    stu1.setAge(17);
    stu1.setScore(97.4f);

    Address addr1("南山", "绝湖", "深渊谷");
    stu1.show(&addr1);

    Student stu2("帝江", 19, 95.4f);
    Address addr2("北海", "离渊", "时空之隙");
    stu2.show(&addr2);

    Student *stu3 = new Student("饕餮", 18, 98.4f);
    Address *addr3 = new Address("嚎窟", "枯眼泉", "马玉玉");
    stu3->show(addr3);
}