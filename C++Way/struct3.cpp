#include <iostream>
#include <cstring>

using namespace std;
void printBook(struct Books *book );

struct Books{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

int main(){
    Books Book1;            //定j结构体类型 Books 的变量Book1
    Books Book2;            //定j结构体类型 Books 的变量Book2

    //Book1 详述
    strcpy(Book1.title, "C++ 教程");
    strcpy(Book1.author, "Runoob");
    strcpy(Book1.subject, "编程语言");
    Book1.book_id = 12345;

    //Book2 详述
    strcpy(Book2.title, "CSS 教程");
    strcpy(Book2.author, "Runoob");
    strcpy(Book2.subject, "前端技术");
    Book2.book_id = 12346;

    //通过传 Book1 的地址来输出Book1信息
    printBook(&Book1);

    //通过传Book2 的地址来输出Book2信息
    printBook(&Book2);

    return 0;
}
//该函数j结构指针作为参数
void printBook(struct Books *book)
{
    cout << "书标题 ：" << book->title <<endl;
    cout << "书作者 ：" << book->author <<endl;
    cout << "书类目 ：" << book->subject <<endl;
    cout << "书ID   ：" << book->book_id <<endl;
}