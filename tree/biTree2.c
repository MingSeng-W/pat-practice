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

struct BiNode{
    ElememtType data;
    BiTree left;
    BiTree right;
};

typedef BiTree ElemType;



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




int main(){
    BiTree T;
    T=createBiTree();
    preOrderTraverse(T);
    printf("%d\n",BitreeHeight(T));
    
    return 0;
}


