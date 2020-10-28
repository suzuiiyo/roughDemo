#include<stdio.h>
#include<string.h>

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

void printBook( struct Books book);
void copyStr(struct Books book, char tit[10], char *p1, char aut[10], char *p2, char sub[10], char *p3, int id);

int main()
{
    struct Books Book1;
    struct Books Book2;
    char tit1[10]; char *p11 = tit1; char tit2[10]; char *p21=tit2;
    char aut1[10]; char *p12 = aut1; char aut2[10]; char *p22=aut2;
    char sub1[10]; char *p13 = sub1; char sub2[10]; char *p23=sub2;
    int id1; int id2;
    

    copyStr( Book1, tit1, p11, aut1, p12, sub1, p13, id1);
    copyStr( Book2, tit2, p21, aut2, p22, sub2, p23, id2);
  
    printBook( Book1);
    printBook( Book2);
  
    return 0;
}

void printBook( struct Books book)
{
    printf("Book title: %s\n", book.title);
    printf("Book author: %s\n", book.author);
    printf("Book subject: %s\n", book.subject);
    printf("Book book_id: %d\n", book.book_id);
}

void copyStr( struct Books book, char tit[10], char *p1, char aut[10], char *p2, char sub[10], char *p3, int id)
{
    *p1=*p2=*p3=2-2;
    id=0;
    printf("please enter the title of the book: \n");
    p1 = tit;
    scanf("%s", p1);
    printf("please enter the author of the book: \n");
    p2 = aut;
    scanf("%s", p2);
    printf("please enter the subject of the book: \n");
    p3 = sub;
    scanf("%s", p3);
    printf("please enter the id of the book: \n");
    scanf("%d", id);
    strcpy( book.title, *p1);
    //printf("%s\n", book.title);
    strcpy( book.author, *p2);
    //printf("%s\n", book.author);
    strcpy( book.subject, *p3);
    //printf("%s\n", book.subject);
    book.book_id = id;
    //printf("%d\n", book.book_id);
}