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

struct BiNode{
    ElememtType data;
    BiTree left;
    BiTree right;
};


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



//先序遍历二叉树，使用递归算法

void preOrderTraverse(BiTree T){
    if (T) {
        printf("%d\n",T->data);
        preOrderTraverse(T->left);
        preOrderTraverse(T->right);
    }
}


//中序遍历二叉树,同样使用递归算法


void inOrderTraverse(BiTree T){
    if (T) {
        inOrderTraverse(T->left);
        printf("%d\n",T->data);
        inOrderTraverse(T->right);
    }
}
//后序遍历二叉树，使用递归算法

void PostOrderTraverse(BiTree T){
    if (T) {
        PostOrderTraverse(T->left);
        PostOrderTraverse(T->right);
        printf("%d\n",T->data);
    }
}


int main(){
    BiTree T;
    T=createBiTree();
    inOrderTraverse(T);
    
    return 0;
}


