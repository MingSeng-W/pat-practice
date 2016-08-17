//
//  main.c
//
//
//  Created by wanghongjie on 16/8/16.
//  Copyright © 2016年 wanghongjie. All rights reserved.
//

//树的构建


#include "stdio.h"
#include "stdlib.h"
typedef struct BiNode *BiTree;
typedef int  ElememtType;
typedef int bool;
#define true 1;
#define false 0;

struct BiNode{
    ElememtType data;
    BiTree left;
    BiTree right;
};

typedef BiTree ElemType;


//队列
typedef int Postion;
typedef BiTree ElemtType;
struct Qnode
{
    Postion front;
    Postion rear;
    ElemtType *data;
    int maxsize;
};
typedef struct Qnode *Queue;
//创建循环队列
Queue createQueue(int maxsize){
    Queue q;
    q=(Queue)malloc(sizeof(struct Qnode));
    q->data=(ElemtType*)malloc(maxsize*sizeof(ElemtType));
    q->front=0;
    q->rear=0;
    q->maxsize=maxsize;
    return q;
}

//判空

bool IsEmpty(Queue q){
    return (q->rear==q->front);
    
}
//判满
bool IsFull(Queue q){
    return((q->rear+1)%q->maxsize==q->front);
    
    
}
//入队
bool AddQ(Queue q,ElemtType x){
    if (IsFull(q))
    {
        printf("%s\n", "队列已满");
        return false;
    }else{
        q->rear=(q->rear+1)%q->maxsize;
        q->data[q->rear]=x;
        return true;
    }
    
}
//出队

ElemtType Delete(Queue q){
    ElemtType tmp;
    if (IsEmpty(q))
    {
        printf("%s\n","队列为空" );
        return NULL;
    }else{
        
        
        q->front=(q->front+1)%q->maxsize;
        tmp=q->data[q->front];
        return tmp;
        
    }
}

//堆栈
typedef struct Snode *PtrlToSNode;
struct Snode
{
    ElemType data;
    PtrlToSNode next;
};
typedef PtrlToSNode Stack;

Stack createStack(){
    Stack s;
    s=(PtrlToSNode)malloc(sizeof(struct Snode));
    s->next=NULL;
    return s;
}
//判空
bool Empty(Stack S){
    return (S->next==NULL);
}


//push方法
bool push(Stack S,ElemType x){
    PtrlToSNode tmp;
    tmp=(PtrlToSNode)malloc(sizeof(struct Snode));
    tmp->data=x;
    tmp->next=S->next;
    S->next=tmp;
    return true;
}

//pop方法

ElemType pop(Stack S){
    PtrlToSNode tmp=S->next;
    if (Empty(S))
    {
        return NULL;
    }else{
        S->next=tmp->next;
        ElemType returndata=tmp->data;
        free(tmp);
        return returndata;
    }
    
}




//先序遍历建立二叉树
BiTree createBiTree(){
    BiTree T;
    char c;
    scanf("%c",&c);
    if(c=='#'){
        T=NULL;
    }else{
        T=(BiTree)malloc(sizeof(struct BiNode));
        T->data=c-'0';
        T->left=createBiTree();
        T->right=createBiTree();
    }
    return T;
}



//二叉树的非递归遍历,中序遍历
void inOrderTraverse(BiTree T){
    Stack s;
    s=createStack();
    while (T||!Empty(s)) {
        while (T) {
            push(s, T);
            T=T->left;
        }
        if (!Empty(s)) {
            T=pop(s);
            printf("%d\n",T->data);
            T=T->right;
        }
    }
    
    
}

//二叉树的非递归遍历,先序遍历
void preOrderTraverse(BiTree T){
    Stack s;
    s=createStack();
    
    while (T||!Empty(s)) {
        while (T) {
            printf("%d\n",T->data);
            push(s, T);
            T=T->left;
        }
        if (!Empty(s)) {
            T=pop(s);
            T=T->right;
        }
        
        
    }
    
}

//求树的高度
int BitreeHeight(BiTree T){
    int lh,rh,maxh;
    if (T) {
        lh=BitreeHeight(T->left);
        rh=BitreeHeight(T->right);
        maxh=(rh>lh)?rh:lh;
        return maxh+1;
    }else{
        return 0;
    }
}


//二叉树的层次遍历

void levelTraverse(BiTree T){
    Queue q;
    q=createQueue(100);
    AddQ(q, T);
    while (!IsEmpty(q)) {
        T=Delete(q);
        printf("%d\n",T->data);
        if (T->left) {
             AddQ(q, T->left);
        }
        if (T->right) {
             AddQ(q, T->right);
        }
       
       
    }
}





int main(){
    BiTree T;
    T=createBiTree();
    levelTraverse(T);
    printf("%d\n",BitreeHeight(T));
    
    return 0;
}


