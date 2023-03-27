#ifndef FINDSECONDMINVALUE_H
#define FINDSECONDMINVALUE_H

typedef struct node{
    struct node *left;
    struct node *right;
    struct node *next;
    struct node *parent;
    int key;
}node;

class findSecondMinValue
{
public:
    findSecondMinValue();

    int find(node *head);
};

#endif // FINDSECONDMINVALUE_H
