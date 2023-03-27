#include "findsecondminvalue.h"
#include <stdio.h>
#include <stdlib.h>

findSecondMinValue::findSecondMinValue()
{

}

int findSecondMinValue::find(node *head)
{
    node **curr, *ptr, *q, *t;

    while(head->next){
        //q指向每一层第一个节点
        //ptr移动地指向每两两节点的第一个
        q=ptr=head;
        curr=&t;
        while(ptr){
            (*curr)=(node *)malloc(sizeof (*q));
            (*curr)->next=NULL;
            //数组为奇数个
            if(ptr->next==NULL){
                (*curr)->key=ptr->key;
                (*curr)->left=(*curr)->right=ptr;
                ptr->parent=*curr;
                break;
            }
            else
            {
                int fir=ptr->key;
                int sec=ptr->next->key;
                (*curr)->key=(fir>sec?sec:fir);
                (*curr)->left=ptr;
                (*curr)->right=ptr->next;
                ptr->parent=ptr->next->parent=*curr;
            }
            curr=&((*curr)->next);
            ptr=ptr->next->next;
        }
        //向上移动一层
        head=q->parent;
    }

    int min=head->key, min2=0x7fffffff;
    //从根节点往下找，从最小值的那个分支找次小值
    while(head->left){
        int lval=head->left->key;
        int rval=head->right->key;
        if(lval==min){
            min2=rval>min2?min2:rval;
            head=head->left;
        }else {
            min2=lval>min2?min2:lval;
            head=head->right;
        }
    }
    return min2;
}


