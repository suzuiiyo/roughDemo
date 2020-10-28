#include<iostream>
#include<string>

using namespace std;

int main(){
    string s1 = "first second third";
    string s2 = "second";
    string s3 = "das";
    int index = s1.find(s2, 5);
    int index2 = s1.find(s3, 3);
    if(index<s1.length())
        cout << "Found at index : " << index << endl;
    else
        cout << "Not found" << endl;


    if(index2<s1.length())
        cout << "Found at index : " << index2 << endl;
    else
        cout << "Not found" << endl;
    return 0;
}