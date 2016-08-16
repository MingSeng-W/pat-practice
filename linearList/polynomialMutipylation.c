//
//  main.c
//  test
//
//  Created by wanghongjie on 16/8/16.
//  Copyright © 2016年 wanghongjie. All rights reserved.
//

//多项式乘法
#include "stdio.h"
#include "stdlib.h"
struct PolyNode
{
    int ceof;
    int expon;
    struct PolyNode *link;
};

typedef struct PolyNode *Polynomial;

void Attach(int ceof,int expon,Polynomial *rear){
    Polynomial tmp;
    tmp=(Polynomial)malloc(sizeof(struct PolyNode));
    tmp->ceof=ceof;
    tmp->expon=expon;
    (*rear)->link=tmp;
    (*rear)=tmp;
}
void PolyRead(Polynomial *rear){
    int total,ceof,expon;
    char c;
    scanf("%d ",&total);
    while(1) {
        scanf("%d ",&ceof);
        scanf("%d",&expon);
        Attach(ceof,expon,rear);
        c=getchar();
        if (c=='\n')
        {
            break;
        }
    }
}
void createPoly(Polynomial *p){
    Polynomial tmp,rear;
    tmp=(Polynomial)malloc(sizeof(struct PolyNode));
    rear=tmp;
    PolyRead(&rear);
    rear->link=NULL;
    *p=tmp->link;
    free(tmp);
}
int Compare(int a,int b){
    if (a>b)
    {
        return 1;
    }else if (a<b)
    {
        return -1;
    }else{
        return 0;
    }
}

Polynomial Addition(Polynomial p1,Polynomial p2){
    Polynomial front,rear;
    front=(Polynomial)malloc(sizeof(struct PolyNode));
    rear=front;
    int sum=0;
    while(p1&&p2) {
        switch(Compare(p1->expon,p2->expon)){
            case 1:
                Attach(p1->ceof,p1->expon,&rear);
                p1=p1->link;
                break;
            case -1:
                Attach(p2->ceof,p2->expon,&rear);
                p2=p2->link;
                break;
            case 0:
                sum=p1->ceof+p2->ceof;
                if (sum)
                {
                    Attach(sum,p1->ceof,&rear);
                }
                p1=p1->link;
                p2=p2->link;
                break;
        }
    }
    for(;p1;p1=p1->link) Attach(p1->ceof,p1->expon,&rear);
    for(;p2;p2=p2->link) Attach(p2->ceof,p2->expon,&rear);
    rear->link=NULL;
    rear=front->link;
    free(front);
    return rear;
    
}


Polynomial Mutiplytion(Polynomial p1,Polynomial p2){
    Polynomial p,rear,t1,t2,t;
    t1=p1;
    t2=p2;
    int e,c;
    p=(Polynomial)malloc(sizeof(struct PolyNode));
    p->link=NULL;
    rear=p;
    while (t2) {
        
        Attach(t1->ceof*t2->ceof, t2->expon+t1->expon,&rear);
        t2=t2->link;
            }
    t1=t1->link;
    while (t1) {
        t2=p2;rear=p;
        while (t2) {
            e=t1->expon+t2->expon;
            c=t1->ceof*t2->ceof;
            while (rear->link&&rear->link->expon>e) {
                rear=rear->link;
            }
            if (rear->link&&rear->link->expon==e) {
                if (rear->link->ceof+c) {
                    rear->link->ceof+=c;
                }else{
                    t=rear->link;
                    rear->link=t->link;
                    free(t);

                }
            }else{
                t=(Polynomial)malloc(sizeof(struct PolyNode));
                t->ceof=c;
                t->expon=e;
                t->link=rear->link;
                rear->link=t;
                rear=rear->link;
            }
            t2=t2->link;
        }
        t1=t1->link;
    }
    t2=p;
    p=p->link;
    free(t2);
    return p;
}

void myPrint(Polynomial p){
    while(p) {
        printf("%d ", p->ceof);
        if (p->link)
        {
            printf("%d ",p->expon);
        }else{
            printf("%d", p->expon);
        }
        
        p=p->link;
    }
    printf("\n");
}








int main(int argc, char const *argv[])
{
    Polynomial p1,p2,addR,MutiR;
    createPoly(&p1);
    createPoly(&p2);
    addR=Addition(p1,p2);
     MutiR=Mutiplytion(p1,p2);
    myPrint(addR);
    myPrint(MutiR);
    return 0;
}

//可执行文件为polynomiaMutipylation

