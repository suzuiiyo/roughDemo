#include<iostream>
#include<string>

using namespace std;

class People{
    public:
        void setName(string name);
        void setAge(int age);
        void setHobby(string hobby);
        string getHobby();
    
    protected:
        string m_name;
        int m_age;
    
    private:
        string m_hobby;
};

void People::setName(string name){
    m_name = name;
}

void People::setAge(int age){
    m_age = age;
}

void People::setHobby(string hobby){
    m_hobby = hobby;
}

string People::getHobby(){
    return m_hobby;
}

class Student: public People{
    public:
        void setScore(float score);
    
    protected:
        float m_score;
};

void Student::setScore(float score){
    m_score = score;
}

class Pupil:public Student{
    public:
        void setRanking(int ranking);
        void display();
    
    private:
        int m_ranking;
};

void Pupil::setRanking(int ranking){
    m_ranking = ranking;
}

void Pupil::display(){
    cout << m_name << "的年龄是" << m_age << ", 成绩是" << m_score << "分, 班级排名第" << m_ranking << ", TA的爱好是" << getHobby() << "." << endl;
}

int main(){
    Pupil pup;
    pup.setName("天目纯");
    pup.setAge(15);
    pup.setScore(99.97f);
    pup.setRanking(3);
    pup.setHobby("拍写真");

    pup.display();

    return 0;
}